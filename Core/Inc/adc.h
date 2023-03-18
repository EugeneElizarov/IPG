/* USER CODE BEGIN Header */
/** 
 * @file adc.h
 * @brief <h1>������ ���������� ���</h1>
 * @author <a href="mailto://acoustics@list.ru">�������� ������� �����������</a>
 * @date 18 ����� 2023 �.
 * @details
 * ������ ������ ������������ ������������� ���������� ������ ���, ������ ��� � 
 * �������� DMA � �������, ������������� ������� ��� ���������� �������, 
 * ����������� � �.�.
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
/** @brief ������� ������������� ����� ���. ���������� ��������� ���, 
           ��������� � ���������� ������� ������, ����������� � ���� 
					 ������ DMA.
*/
/* USER CODE END Private defines */

void MX_ADC_Init(void);

/* USER CODE BEGIN Prototypes */
/** @brief ������� ��������� �������� ��������� �������� ����������
           ������ ��� � ��.
		@return �������� ��������� �������� ���������� � ��
*/
uint16_t MX_ADC_GetVRef(void);

/** @brief ������� ���������� ������� ���.
    @param [in] enable true - ��������� ������ ���<br>
		                   false - ���������� ������ ���
*/
void MX_ADC_Control(bool enable);

/** @brief ���������� ������� �������������� ���
*/
void MX_ADC_Start(void);

/** @brief ���������� ������� �������������� ���
*/
void MX_ADC_Stop(void);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __ADC_H__ */

