/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

#include "stm32g4xx_nucleo.h"
#include <stdio.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_0
#define LED_GPIO_Port GPIOA
#define L_IR_Pin GPIO_PIN_1
#define L_IR_GPIO_Port GPIOA
#define F_IR_Pin GPIO_PIN_4
#define F_IR_GPIO_Port GPIOA
#define L_IRA5_Pin GPIO_PIN_5
#define L_IRA5_GPIO_Port GPIOA
#define PWM_L_Pin GPIO_PIN_6
#define PWM_L_GPIO_Port GPIOA
#define R_IR_Pin GPIO_PIN_7
#define R_IR_GPIO_Port GPIOA
#define RA_Pin GPIO_PIN_0
#define RA_GPIO_Port GPIOB
#define RA_EXTI_IRQn EXTI0_IRQn
#define PWMR_Pin GPIO_PIN_8
#define PWMR_GPIO_Port GPIOA
#define DIRR_Pin GPIO_PIN_11
#define DIRR_GPIO_Port GPIOA
#define DIRL_Pin GPIO_PIN_12
#define DIRL_GPIO_Port GPIOA
#define T_SWDIO_Pin GPIO_PIN_13
#define T_SWDIO_GPIO_Port GPIOA
#define T_SWCLK_Pin GPIO_PIN_14
#define T_SWCLK_GPIO_Port GPIOA
#define AL_Pin GPIO_PIN_3
#define AL_GPIO_Port GPIOB
#define AL_EXTI_IRQn EXTI3_IRQn
#define BL_Pin GPIO_PIN_4
#define BL_GPIO_Port GPIOB
#define BUTTON_Pin GPIO_PIN_5
#define BUTTON_GPIO_Port GPIOB
#define RB_Pin GPIO_PIN_6
#define RB_GPIO_Port GPIOB
#define RB_EXTI_IRQn EXTI9_5_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
