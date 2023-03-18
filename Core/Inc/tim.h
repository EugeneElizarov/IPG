/* USER CODE BEGIN Header */
/** 
 * @file tim.h
 * @brief <h1>Модуль управления таймером TMR2</h1>
 * @author <a href="mailto://acoustics@list.ru">Елизаров Евгений Анатольевич</a>
 * @date 18 марта 2023 г.
 * @details
 * Данный модуль обеспечивает инициализацию аппартного модуля TMR2, его запуска,
 * остановки. Таймер настраивается на частоту переполнения 10кГц. Событие
 * переполнения является спусковым для начала преобразования АЦП
 * ************************************************************************** */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIM_H__
#define __TIM_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern TIM_HandleTypeDef htim2;

/* USER CODE BEGIN Private defines */
/** @brief Инициализация модуля TMR2 */
/* USER CODE END Private defines */

void MX_TIM2_Init(void);

/* USER CODE BEGIN Prototypes */

/** @brief Запуск таймера */
void MX_TIM2_Start(void);

/** @brief Останов таймера */
void MX_TIM2_Stop(void);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __TIM_H__ */

