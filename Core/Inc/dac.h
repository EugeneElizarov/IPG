/* USER CODE BEGIN Header */
/** 
 * @file dac.h
 * @brief <h1>Модуль управления ЦАП</h1>
 * @author <a href="mailto://acoustics@list.ru">Елизаров Евгений Анатольевич</a>
 * @date 18 марта 2023 г.
 * @details
 * Данный модуль обеспечивает инициализацию аппартного модуля ЦАП, его запуска,
 * остановки и управления напряжением выхода канала
 * ************************************************************************** */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DAC_H__
#define __DAC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern DAC_HandleTypeDef hdac;

/* USER CODE BEGIN Private defines */
/** @brief Инициализация модуля ЦАП
*/
/* USER CODE END Private defines */

void MX_DAC_Init(void);

/* USER CODE BEGIN Prototypes */

/** @brief Включение модуля ЦАП
*/
void MX_DAC_Start(void);

/** @brief Изменение напряжения на выходе ЦАП
    @param [in] DAC_value 12-ти разрядное значение, пропорциональное 
		                      выходному напряжению
*/
void MX_DAC_Out(uint16_t DAC_value);

/** @brief Выключение модуля ЦАП
*/
void MX_DAC_Stop(void);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __DAC_H__ */

