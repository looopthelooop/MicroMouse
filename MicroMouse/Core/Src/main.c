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
float kvp = 5.0f;
float kvi = 1.5f;
float kenc = 0.015259f;

volatile int32_t encoder_ticks_R = 0;
volatile int32_t encoder_ticks_L = 0;
int32_t prev_encoder_ticks_R = 0;
int32_t prev_encoder_ticks_L = 0;
float vel_integral_R = 0;
float vel_integral_L = 0;

float pos_target_R = 0.0f;
float pos_target_L = 0.0f;

uint32_t last_control_time = 0;

#define NUM_IR_SENSORS 4
volatile uint16_t ir_readings[NUM_IR_SENSORS];

volatile uint8_t button_mode = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
float cascaded_control(float pos_target, float pos_current, float vel_current, float *vel_integral);
void set_motor_pwm_R(float cmd);
void set_motor_pwm_L(float cmd);
uint8_t robot_has_reached_next_cell(void);  // ✅ Add this line

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
  floodfill_set_goal(2, 1);   // or whatever cell you want as goal
  floodfill_init();
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
  while (1)
  {
	  if (1) {
		  // Example: read walls from IR sensors
		  uint8_t front = (ir_readings[2] > 500);
		  uint8_t left  = (ir_readings[0] > 500);
		  uint8_t right = (ir_readings[3] > 500);
		  // Update maze map
		  floodfill_update_walls(front, left, right);

		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);

		  // Recompute distances
		  floodfill_step();

		  Direction dir = floodfill_next_move();

		  if (dir == DIR_NORTH) {
			  pos_target_R = 20.0;
			  pos_target_L = 20.0;
		  } else if (dir == DIR_EAST) {
			  pos_target_R = -6.0;
			  pos_target_L = 6.0;
		  } else if (dir == DIR_WEST) {
			  pos_target_R = 6.0;
			  pos_target_L = -6.0;
		  } else if (dir == DIR_SOUTH) {
			  pos_target_R = -20.0;
			  pos_target_L = -20.0;
		  }

		  while (!robot_has_reached_next_cell()) {
			  if (HAL_GetTick() - last_control_time >= 10) {
				  last_control_time += 10;
				  // Control loop keeps running
				  float pos_current_R = encoder_ticks_R * kenc;
				  float vel_current_R = (encoder_ticks_R - prev_encoder_ticks_R) * kenc / 0.01f;
				  prev_encoder_ticks_R = encoder_ticks_R;
				  float pwm_R = cascaded_control(pos_target_R, pos_current_R, vel_current_R, &vel_integral_R);
				  set_motor_pwm_R(pwm_R);

				  float pos_current_L = encoder_ticks_L * kenc;
				  float vel_current_L = (encoder_ticks_L - prev_encoder_ticks_L) * kenc / 0.01f;
				  prev_encoder_ticks_L = encoder_ticks_L;
				  float pwm_L = cascaded_control(-pos_target_L, pos_current_L, vel_current_L, &vel_integral_L);
				  set_motor_pwm_L(pwm_L);
			  }
		  }

		  // Reset encoder for next block tracking
		  encoder_ticks_R = 0;
		  encoder_ticks_L = 0;
		  vel_integral_R = 0;
		  vel_integral_L = 0;
	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */
}

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

float cascaded_control(float pos_target, float pos_current, float vel_current, float *vel_integral)
{
    float vel_ref = kpp * (pos_target - pos_current);
    float vel_error = vel_ref - vel_current;
    *vel_integral += vel_error * 0.01f;

    float pwm = kvp * vel_error + kvi * (*vel_integral);

    if (pwm > 100.0f) {
        pwm = 100.0f;
        *vel_integral -= vel_error * 0.01f;
    } else if (pwm < -100.0f) {
        pwm = -100.0f;
        *vel_integral -= vel_error * 0.01f;
    }

    return pwm;
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

uint8_t robot_has_reached_next_cell(void) {
    float pos_current_R = encoder_ticks_R * kenc;
    float pos_current_L = encoder_ticks_L * kenc;

    if (fabsf(pos_target_R - pos_current_R) < 1.0f &&
        fabsf(-pos_target_L - pos_current_L) < 1.0f) {
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
