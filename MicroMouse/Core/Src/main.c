/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "floodfill.h"
#include <math.h>


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

COM_InitTypeDef BspCOMInit;

/* USER CODE BEGIN PV */

float kpp = 1.0f;
float kvp = 20.0f;
float kvi = 10.0f;
float kenc = 0.015259f;
float dt = 0.001f;

// Wall centering parameters
float wall_centering_gain = 20.0f;  // Adjust this for centering strength
uint16_t close_threshold = 1500;  // Add this line
float turn_threshold = 15.0f;       // Threshold to detect turns vs straight moves
uint16_t front_threshold = 2700;

// Rate limiter parameters
static float prev_vel_ref_R = 0;
static float prev_vel_ref_L = 0;
static float max_vel_change = 100.0f;  // mm/s per control cycle (adjust as needed)

volatile int32_t encoder_ticks_R = 0;
volatile int32_t encoder_ticks_L = 0;
int32_t prev_encoder_ticks_R = 0;
int32_t prev_encoder_ticks_L = 0;
float vel_integral_R = 0;
float vel_integral_L = 0;

uint32_t last_control_time = 0;

#define NUM_IR_SENSORS 4
volatile uint16_t ir_readings[NUM_IR_SENSORS];

volatile uint8_t button_mode = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
float rate_limit_velocity(float new_vel_ref, float prev_vel_ref, float max_change);
float cascaded_control_with_vel_rate_limit(float pos_target, float pos_current,
                                          float vel_current, float *vel_integral,
                                          float *prev_vel_ref);
void set_motor_pwm_R(float cmd);
void set_motor_pwm_L(float cmd);
uint8_t robot_has_reached_next_cell(float pos_target_R, float pos_target_L);
float calculate_wall_centering(float pos_target_R, float pos_target_L);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC2_Init();
  MX_USART1_UART_Init();
  MX_TIM1_Init();
  MX_TIM16_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim16, TIM_CHANNEL_1);

  HAL_ADC_Start_DMA(&hadc2, (uint32_t*)ir_readings, NUM_IR_SENSORS);
  floodfill_set_goal(3, 3);   // or whatever cell you want as goal
  floodfill_init();

  // Give sensors time to stabilize
  HAL_Delay(500);  // 500ms is sufficient

  // NOW read the initial walls (using higher threshold for reliable detection)
  uint8_t front = (ir_readings[2] > 500);
  uint8_t left  = (ir_readings[0] > 500);
  uint8_t right = (ir_readings[3] > 500);
  floodfill_update_walls(front, left, right);
  floodfill_step();
  /* USER CODE END 2 */

  /* Initialize leds */
  BSP_LED_Init(LED_GREEN);

  /* Initialize COM1 port (115200, 8 bits (7-bit data + 1 stop bit), no parity */
  BspCOMInit.BaudRate   = 115200;
  BspCOMInit.WordLength = COM_WORDLENGTH_8B;
  BspCOMInit.StopBits   = COM_STOPBITS_1;
  BspCOMInit.Parity     = COM_PARITY_NONE;
  BspCOMInit.HwFlowCtl  = COM_HWCONTROL_NONE;
  if (BSP_COM_Init(COM1, &BspCOMInit) != BSP_ERROR_NONE)
  {
    Error_Handler();
  }

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	   if (!floodfill_is_goal_reached() && floodfill_get_pos_x() == floodfill_get_goal_x() && floodfill_get_pos_y() == floodfill_get_goal_y()) {
		  // Signal that goal was reached (LED blinks)
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
		  HAL_Delay(200);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
		  HAL_Delay(200);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
		  HAL_Delay(200);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	   }
      // Only do wall sensing during exploration (before goal is reached)
      if (!floodfill_is_goal_reached()) {
          uint8_t front = (ir_readings[2] > 500);
          uint8_t left  = (ir_readings[0] > 500);
          uint8_t right = (ir_readings[3] > 500);
          floodfill_update_walls(front, left, right);
          floodfill_step();
      }

      // Check if we've completed the return journey
      if (floodfill_is_goal_reached() &&
          floodfill_get_pos_x() == 0 &&
          floodfill_get_pos_y() == 0) {
          // Robot has returned to start - celebration sequence
          for(int i = 0; i < 5; i++) {
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
              HAL_Delay(200);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
              HAL_Delay(200);
          }
          break; // Exit or restart as needed
      }

      float pos_target_R = 0, pos_target_L = 0;
      uint8_t has_move = floodfill_next_motor_targets(&pos_target_R, &pos_target_L);

      if (!has_move) {
          HAL_Delay(1);
          continue;
      }

      // Reset encoder and control variables for the next move
      encoder_ticks_R = 0;
      encoder_ticks_L = 0;
      prev_encoder_ticks_R = 0;
      prev_encoder_ticks_L = 0;
      vel_integral_R = 0;
      vel_integral_L = 0;
      // Reset velocity reference rate limiter
      prev_vel_ref_R = 0;
      prev_vel_ref_L = 0;

      uint32_t timeout = HAL_GetTick() + 5000;

      while (!robot_has_reached_next_cell(pos_target_R, pos_target_L)) {
          if (HAL_GetTick() - last_control_time >= 1) {
              last_control_time += 1;

              float pos_current_R = encoder_ticks_R * kenc;
              float vel_current_R = (encoder_ticks_R - prev_encoder_ticks_R) * kenc / dt;
              prev_encoder_ticks_R = encoder_ticks_R;

              float pos_current_L = encoder_ticks_L * kenc;
              float vel_current_L = (encoder_ticks_L - prev_encoder_ticks_L) * kenc / dt;
              prev_encoder_ticks_L = encoder_ticks_L;

              // Use rate-limited cascaded control
              float pwm_R = cascaded_control_with_vel_rate_limit(pos_target_R, pos_current_R,
                                                                vel_current_R, &vel_integral_R,
                                                                &prev_vel_ref_R);
              float pwm_L = cascaded_control_with_vel_rate_limit(-pos_target_L, pos_current_L,
                                                                vel_current_L, &vel_integral_L,
                                                                &prev_vel_ref_L);

              // Calculate wall centering command (pass the targets to detect turns)
              float centering_cmd = calculate_wall_centering(pos_target_R, pos_target_L);

              // Apply differential centering (Method 2)
              float pwm_R_centered = pwm_R + centering_cmd;  // Right motor
              float pwm_L_centered = pwm_L + centering_cmd;  // Left motor (opposite)

              set_motor_pwm_R(pwm_R_centered);
              set_motor_pwm_L(pwm_L_centered);
          }
          if (HAL_GetTick() > timeout) break;
      }

      set_motor_pwm_R(0);
      set_motor_pwm_L(0);
  	  }
	  /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
  RCC_OscInitStruct.PLL.PLLN = 85;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

// Rate limiter function
float rate_limit_velocity(float new_vel_ref, float prev_vel_ref, float max_change) {
    float delta = new_vel_ref - prev_vel_ref;
    if (delta > max_change) {
        return prev_vel_ref + max_change;
    } else if (delta < -max_change) {
        return prev_vel_ref - max_change;
    }
    return new_vel_ref;
}

// Modified cascaded_control function with velocity rate limiting
float cascaded_control_with_vel_rate_limit(float pos_target, float pos_current,
                                          float vel_current, float *vel_integral,
                                          float *prev_vel_ref) {
    // Calculate desired velocity reference from position error
    float vel_ref_desired = kpp * (pos_target - pos_current);

    // Apply rate limiting to velocity reference
    float vel_ref = rate_limit_velocity(vel_ref_desired, *prev_vel_ref, max_vel_change);
    *prev_vel_ref = vel_ref;

    // Continue with normal velocity control
    float vel_error = vel_ref - vel_current;
    *vel_integral += vel_error * dt;

    float pwm = kvp * vel_error + kvi * (*vel_integral);

    // Anti-windup
    if (pwm > 100.0f) {
        pwm = 100.0f;
        *vel_integral -= vel_error * dt;
    } else if (pwm < -100.0f) {
        pwm = -100.0f;
        *vel_integral -= vel_error * dt;
    }

    return pwm;
}

float calculate_wall_centering(float pos_target_R, float pos_target_L)
{
    float left_sensor = ir_readings[0];   // Left wall sensor
    float right_sensor = ir_readings[3];  // Right wall sensor

    float centering_command = 0;

    if (fabsf(pos_target_R) < turn_threshold || fabsf(pos_target_L) < turn_threshold) {
        // This is a turn - no centering applied
        return 0;
    }

    // Determine if we're moving forward or backward
    uint8_t moving_backward = (pos_target_R < 0 && pos_target_L < 0);

    if (left_sensor > close_threshold && right_sensor > close_threshold) {
        // Both walls present - center between them
        float left_closeness = (left_sensor - close_threshold) * (3.3f/4095);
        float right_closeness = (right_sensor - close_threshold) * (3.3f/4095);

        // Positive = steer left, Negative = steer right (for forward movement)
        centering_command = wall_centering_gain * (right_closeness - left_closeness);

        // Invert for backward movement
        if (moving_backward) {
            centering_command = -centering_command;
        }
    } else if (left_sensor > close_threshold) {
        // Only left wall - steer right (for forward movement)
        centering_command = -wall_centering_gain * ((left_sensor - close_threshold) * (3.3f/4095));

        // Invert for backward movement (steer left when going backward)
        if (moving_backward) {
            centering_command = -centering_command;
        }
    } else if (right_sensor > close_threshold) {
        // Only right wall - steer left (for forward movement)
        centering_command = wall_centering_gain * ((right_sensor - close_threshold) * (3.3f/4095));

        // Invert for backward movement (steer right when going backward)
        if (moving_backward) {
            centering_command = -centering_command;
        }
    }

    // Limit the centering command
    if (centering_command > 35.0f) centering_command = 35.0f;
    if (centering_command < -35.0f) centering_command = -35.0f;

    return centering_command;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_0) {
        uint8_t currA = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
        uint8_t currB = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);
        encoder_ticks_R += (currA == currB) ? -1 : +1;
    }
    else if (GPIO_Pin == GPIO_PIN_3) {
        uint8_t currA = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
        uint8_t currB = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
        encoder_ticks_L += (currA == currB) ? -1 : +1;
    }
    else if (GPIO_Pin == GPIO_PIN_5){
    	button_mode += 1;
    }
}

void set_motor_pwm_R(float cmd)
{
    if (cmd > 100.0f) {
        cmd = 100.0f;
    } else if (cmd < -100.0f) {
        cmd = -100.0f;
    }
    if (cmd >= 0) {
        HAL_GPIO_WritePin(DIRR_GPIO_Port, DIRR_Pin, GPIO_PIN_SET);
    } else {
        HAL_GPIO_WritePin(DIRR_GPIO_Port, DIRR_Pin, GPIO_PIN_RESET);
        cmd = -cmd;
    }
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, (uint16_t)(cmd * 655.35f));
}

void set_motor_pwm_L(float cmd)
{
    if (cmd > 100.0f) {
        cmd = 100.0f;
    } else if (cmd < -100.0f) {
        cmd = -100.0f;
    }
    if (cmd >= 0) {
        HAL_GPIO_WritePin(DIRL_GPIO_Port, DIRL_Pin, GPIO_PIN_SET);
    } else {
        HAL_GPIO_WritePin(DIRL_GPIO_Port, DIRL_Pin, GPIO_PIN_RESET);
        cmd = -cmd;
    }
    __HAL_TIM_SET_COMPARE(&htim16, TIM_CHANNEL_1, (uint16_t)(cmd * 655.35f));
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if (hadc->Instance == ADC2) {
        // e.g., process ir_readings[]
    }
}

uint8_t robot_has_reached_next_cell(float pos_target_R, float pos_target_L) {
  float pos_current_R = encoder_ticks_R * kenc;
  float pos_current_L = encoder_ticks_L * kenc;

  if (fabsf(pos_target_R - pos_current_R) < 1.0f &&
      fabsf(-pos_target_L - pos_current_L) < 1.0f) {
    return 1;
  }

  float distance_moved = fmaxf(fabsf(pos_current_R), fabsf(pos_current_L));
  if (distance_moved > 10.0f && ir_readings[2] > front_threshold) {
      return 1;
  }

  return 0;
}

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6)
  {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {

  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
