/* USER CODE BEGIN Header */
/** 
 * @file dac.h
 * @brief <h1>������ ���������� ���</h1>
 * @author <a href="mailto://acoustics@list.ru">�������� ������� �����������</a>
 * @date 18 ����� 2023 �.
 * @details
 * ������ ������ ������������ ������������� ���������� ������ ���, ��� �������,
 * ��������� � ���������� ����������� ������ ������
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
/** @brief ������������� ������ ���
*/
/* USER CODE END Private defines */

void MX_DAC_Init(void);

/* USER CODE BEGIN Prototypes */

/** @brief ��������� ������ ���
*/
void MX_DAC_Start(void);

/** @brief ��������� ���������� �� ������ ���
    @param [in] DAC_value 12-�� ��������� ��������, ���������������� 
		                      ��������� ����������
*/
void MX_DAC_Out(uint16_t DAC_value);

/** @brief ���������� ������ ���
*/
void MX_DAC_Stop(void);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __DAC_H__ */

