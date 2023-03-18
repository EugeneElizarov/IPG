/* USER CODE BEGIN Header */
/* ************************************************************************** */
/**
 * @file processor.h
 * @brief <h1>Модуль инициализации GPIO</h1>
 * @author <a href="mailto://acoustics@list.ru">Елизаров Евгений Анатольевич</a>
 * @date 18 марта 2023 г.
 * 
 * ************************************************************************** */

/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
/** @brief Инициализация GPIO (Кнопка и светодиод)
*/
/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

