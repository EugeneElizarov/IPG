/* USER CODE BEGIN Header */
/** 
 * @file adc.h
 * @brief <h1>Модуль управления АЦП</h1>
 * @author <a href="mailto://acoustics@list.ru">Елизаров Евгений Анатольевич</a>
 * @date 18 марта 2023 г.
 * @details
 * Данный модуль обеспечивает инициализацию аппартного модуля АЦП, связку его с 
 * модулями DMA и таймера, предоставляет функции для управления модулем, 
 * измерениями и т.д.
 * ************************************************************************** */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ADC_H__
#define __ADC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include <stdbool.h>
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
/** @brief Функция инициализации моуля АЦП. Производит настройку АЦП, 
           настройку и калибровку первого канала, подключение к нему 
					 канала DMA.
*/
/* USER CODE END Private defines */

void MX_ADC_Init(void);

/* USER CODE BEGIN Prototypes */
/** @brief Функция получения величины источника опорного напряжения
           модуля АЦП в мВ.
		@return значение источника опорного напряжения в мВ
*/
uint16_t MX_ADC_GetVRef(void);

/** @brief Функция управления модулем АЦП.
    @param [in] enable true - включение модуля АЦП<br>
		                   false - выключение модуля АЦП
*/
void MX_ADC_Control(bool enable);

/** @brief Разрешение запуска преобразования АЦП
*/
void MX_ADC_Start(void);

/** @brief Запрещение запуска преобразования АЦП
*/
void MX_ADC_Stop(void);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __ADC_H__ */

