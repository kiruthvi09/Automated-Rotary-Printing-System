/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Roll1_EN1_Pin GPIO_PIN_0
#define Roll1_EN1_GPIO_Port GPIOA
#define Roll1_EN2_Pin GPIO_PIN_1
#define Roll1_EN2_GPIO_Port GPIOA
#define IN1_ROll1_Pin GPIO_PIN_2
#define IN1_ROll1_GPIO_Port GPIOA
#define IN2_Roll1_Pin GPIO_PIN_4
#define IN2_Roll1_GPIO_Port GPIOA
#define DyePump1_Pin GPIO_PIN_5
#define DyePump1_GPIO_Port GPIOA
#define DyePump2_Pin GPIO_PIN_6
#define DyePump2_GPIO_Port GPIOA
#define IN1_Roll2_Pin GPIO_PIN_7
#define IN1_Roll2_GPIO_Port GPIOA
#define IN2_Roll2_Pin GPIO_PIN_0
#define IN2_Roll2_GPIO_Port GPIOB
#define IN1_Conv1_Pin GPIO_PIN_1
#define IN1_Conv1_GPIO_Port GPIOB
#define IN2_Conv1_Pin GPIO_PIN_2
#define IN2_Conv1_GPIO_Port GPIOB
#define IN1_Conv2_Pin GPIO_PIN_12
#define IN1_Conv2_GPIO_Port GPIOB
#define IN2_Conv2_Pin GPIO_PIN_13
#define IN2_Conv2_GPIO_Port GPIOB
#define IN1_Conv3_Pin GPIO_PIN_14
#define IN1_Conv3_GPIO_Port GPIOB
#define IN2_Conv3_Pin GPIO_PIN_15
#define IN2_Conv3_GPIO_Port GPIOB
#define Conv4_EN4_Pin GPIO_PIN_8
#define Conv4_EN4_GPIO_Port GPIOA
#define Conv3_EN3_Pin GPIO_PIN_9
#define Conv3_EN3_GPIO_Port GPIOA
#define Conv2_EN2_Pin GPIO_PIN_10
#define Conv2_EN2_GPIO_Port GPIOA
#define Conv1_EN1_Pin GPIO_PIN_11
#define Conv1_EN1_GPIO_Port GPIOA
#define IN1_Conv4_Pin GPIO_PIN_12
#define IN1_Conv4_GPIO_Port GPIOA
#define IN2_Conv4_Pin GPIO_PIN_13
#define IN2_Conv4_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
