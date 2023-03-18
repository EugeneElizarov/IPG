#include "stm32f0xx_hal.h"

#include "processor.h"

#include "adc.h"
#include "dac.h"
#include "dma.h"
#include "gpio.h"
#include "tim.h"

#define ADC_DATA_LENGTH			100
#define AVDD								3300

// Массив данных АЦП для усреднения
static uint16_t ADC_Data[ADC_DATA_LENGTH];
// Усредненное значение АЦП  для ЦАП
static uint32_t average_value = 0;
// Сумма значений АЦП для терминала
static uint32_t terminal_average_value = 0;
// Количество просуммированных значений АЦП для терминала
static uint32_t terminal_average_value_counter = 0;
// Усредненное значение АЦП для терминада
static uint16_t terminal_value = 0;
// Флаг готовности значения АЦП для терминала
static bool terminal_average_value_valid = false;

// Функция запуска измерения очередного блока 100 точек
void DMA_Restart(void)
{
	// Отключаем DMA 
	MX_DMA_Control(false);
	// Устанавливаем количество измерений
	MX_DMA_SetDataCount(ADC_DATA_LENGTH);
	// Устанавливаем начальный адрес массива для сохранения результатов
  MX_DMA_SetMemAddr(ADC_Data);
	// Включаем DMA
	MX_DMA_Control(true);
}
// Функция обработки прерывания от DMA
void DMA_Transfer_OK(void)
{
  uint8_t i;
	// Перезапускаем DMA
  DMA_Restart();
	// Запускаем очередной цикл измерений
	MX_ADC_Start();
	// Загружаем начально значение для округления без отбрасывания
	average_value = (ADC_DATA_LENGTH + 1) >> 1;
	// Вычисляем сумму всех измерений
	for (i = 0; i < ADC_DATA_LENGTH; i++)
		average_value += ADC_Data[i];
	// Определяем среднее значение
	average_value /= ADC_DATA_LENGTH;
	// Выводим полученное значение в канал ЦАП
	MX_DAC_Out(average_value);
	terminal_average_value += average_value;
	terminal_average_value_counter++;
	if (terminal_average_value_counter >= 100)
	{
		terminal_value /= terminal_average_value_counter;
		terminal_average_value_valid = true;
  	terminal_average_value = 0;
	  terminal_average_value_counter = 0;
	}
}

void Processor_Init(void)
{
  // Инициализируем GPIO (кнопка и светодиод)
  MX_GPIO_Init();
	// Инициализируем DMA
  MX_DMA_Init();
	// Инициализируем АЦП
  MX_ADC_Init();
	// Инициализируем ЦАП
  MX_DAC_Init();
	// Инициализируем таймер
  MX_TIM2_Init();
	
  // Подготавливаем модули к старту очередного цикла измерений
	DMA_Restart();
	// Включаем АЦП
	MX_ADC_Control(true);
	// Разрешаем работу АЦП
	MX_ADC_Start();
	// Запускаем таймер и, вместе с ним, циклические измерения
	MX_TIM2_Start();
	MX_DAC_Start();
}

uint16_t Processor_GetValue(bool real)
{
	if (real)
	{
		// Возвращаем усредненное измеренное значение в мВ
		return MX_ADC_GetVRef() * average_value / 4095;
	}
	else
		// Возвращаем усредненное измеренное значение в кодах АЦП
		return average_value;
}

bool Processor_DataAvailable(void)
{
	if (terminal_average_value_valid)
	{
		terminal_average_value_valid = false;
	  return true;
	}
	return false;
}
