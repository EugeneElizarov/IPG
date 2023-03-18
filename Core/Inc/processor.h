/* ************************************************************************** */
/**
 * @file processor.h
 * @brief <h1>Модуль основного обработчика</h1>
 * @author <a href="mailto://acoustics@list.ru">Елизаров Евгений Анатольевич</a>
 * @date 18 марта 2023 г.
 * 
 * ************************************************************************** */

#ifndef __PROCESSOR_H__

#define __PROCESSOR_H__

#include <stdbool.h>
#include <stdint.h>

/** @brief Функция инициализации модулей для 
           обеспечения работы аппаратной части
*/
void Processor_Init(void);

/** @brief Функция получения среднего значения измеряемой велицины
    @param [in] real true - вернуть значение в мВ<br>
		                 false - вернуть средний код АЦП
    @return среднее значение измеряемой величины
*/
uint16_t Processor_GetValue(bool real);

bool Processor_DataAvailable(void);

/** @brief Функция обратного вызова из прерывания окончания 
           передачи данных из модуля АЦП в память по каналу DMA
*/
void DMA_Transfer_OK(void);

#endif
