/* USER CODE BEGIN Header */
/** 
 * @file dma.h
 * @brief <h1>Модуль управления DMA</h1>
 * @author <a href="mailto://acoustics@list.ru">Елизаров Евгений Анатольевич</a>
 * @date 18 марта 2023 г.
 * @details
 * Данный модуль обеспечивает инициализацию аппартного модуля DMA, его запуска,
 * установки адресов периферии и буфера данных, а, так же, количества передаваемых
 * данных за один цикл
 * ************************************************************************** */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DMA_H__
#define __DMA_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* DMA memory to memory transfer handles -------------------------------------*/

/* USER CODE BEGIN Includes */
#include <stdbool.h>
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
/** @brief Инициализация модуля DMA */
/* USER CODE END Private defines */

void MX_DMA_Init(void);

/* USER CODE BEGIN Prototypes */
/** @brief Установка адреса периферии (источника данных)
    @param [in] addr адрес периферийных данных
*/
void MX_DMA_SetPeriAddr(void *addr);

/** @brief Установка адреса буфера данных (приемника данных)
    @param [in] addr адрес буфера данных
*/
void MX_DMA_SetMemAddr(void *addr);

/** @brief Управление модулем DMA
    @param [in] enable true Включить модуль DMA<br>
		                   false Выключить модуль DMA
*/
void MX_DMA_Control(bool enable);

/** @brief Установка количества передаваемых данных в одном цикле
    @param [in] count количество передаваемых данных
*/
void MX_DMA_SetDataCount(uint32_t count);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __DMA_H__ */

