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
#include "stm32f4xx_hal.h"

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
#define LED_BOARD_Pin GPIO_PIN_13
#define LED_BOARD_GPIO_Port GPIOC
#define LED_STATUS_Pin GPIO_PIN_14
#define LED_STATUS_GPIO_Port GPIOC
#define BT_RIGHT_Pin GPIO_PIN_15
#define BT_RIGHT_GPIO_Port GPIOC
#define BT_OUT_Pin GPIO_PIN_3
#define BT_OUT_GPIO_Port GPIOA
#define BT_LEFT_Pin GPIO_PIN_4
#define BT_LEFT_GPIO_Port GPIOA
#define ST7789_DC_Pin GPIO_PIN_0
#define ST7789_DC_GPIO_Port GPIOB
#define ST7789_RST_Pin GPIO_PIN_1
#define ST7789_RST_GPIO_Port GPIOB
#define ST7789_CS_Pin GPIO_PIN_2
#define ST7789_CS_GPIO_Port GPIOB
#define ENC_BT_Pin GPIO_PIN_8
#define ENC_BT_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

extern I2C_HandleTypeDef hi2c1;

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
