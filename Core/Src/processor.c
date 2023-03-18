#include "stm32f0xx_hal.h"

#include "processor.h"

#include "adc.h"
#include "dac.h"
#include "dma.h"
#include "gpio.h"
#include "tim.h"

#define ADC_DATA_LENGTH			100
#define AVDD								3300

// ������ ������ ��� ��� ����������
static uint16_t ADC_Data[ADC_DATA_LENGTH];
// ����������� �������� ���  ��� ���
static uint32_t average_value = 0;
// ����� �������� ��� ��� ���������
static uint32_t terminal_average_value = 0;
// ���������� ���������������� �������� ��� ��� ���������
static uint32_t terminal_average_value_counter = 0;
// ����������� �������� ��� ��� ���������
static uint16_t terminal_value = 0;
// ���� ���������� �������� ��� ��� ���������
static bool terminal_average_value_valid = false;

// ������� ������� ��������� ���������� ����� 100 �����
void DMA_Restart(void)
{
	// ��������� DMA 
	MX_DMA_Control(false);
	// ������������� ���������� ���������
	MX_DMA_SetDataCount(ADC_DATA_LENGTH);
	// ������������� ��������� ����� ������� ��� ���������� �����������
  MX_DMA_SetMemAddr(ADC_Data);
	// �������� DMA
	MX_DMA_Control(true);
}
// ������� ��������� ���������� �� DMA
void DMA_Transfer_OK(void)
{
  uint8_t i;
	// ������������� DMA
  DMA_Restart();
	// ��������� ��������� ���� ���������
	MX_ADC_Start();
	// ��������� �������� �������� ��� ���������� ��� ������������
	average_value = (ADC_DATA_LENGTH + 1) >> 1;
	// ��������� ����� ���� ���������
	for (i = 0; i < ADC_DATA_LENGTH; i++)
		average_value += ADC_Data[i];
	// ���������� ������� ��������
	average_value /= ADC_DATA_LENGTH;
	// ������� ���������� �������� � ����� ���
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
  // �������������� GPIO (������ � ���������)
  MX_GPIO_Init();
	// �������������� DMA
  MX_DMA_Init();
	// �������������� ���
  MX_ADC_Init();
	// �������������� ���
  MX_DAC_Init();
	// �������������� ������
  MX_TIM2_Init();
	
  // �������������� ������ � ������ ���������� ����� ���������
	DMA_Restart();
	// �������� ���
	MX_ADC_Control(true);
	// ��������� ������ ���
	MX_ADC_Start();
	// ��������� ������ �, ������ � ���, ����������� ���������
	MX_TIM2_Start();
	MX_DAC_Start();
}

uint16_t Processor_GetValue(bool real)
{
	if (real)
	{
		// ���������� ����������� ���������� �������� � ��
		return MX_ADC_GetVRef() * average_value / 4095;
	}
	else
		// ���������� ����������� ���������� �������� � ����� ���
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
