/* USER CODE BEGIN Header */
/** 
 * @file tim.h
 * @brief <h1>������ ���������� �������� TMR2</h1>
 * @author <a href="mailto://acoustics@list.ru">�������� ������� �����������</a>
 * @date 18 ����� 2023 �.
 * @details
 * ������ ������ ������������ ������������� ���������� ������ TMR2, ��� �������,
 * ���������. ������ ������������� �� ������� ������������ 10���. �������
 * ������������ �������� ��������� ��� ������ �������������� ���
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
/** @brief ������������� ������ TMR2 */
/* USER CODE END Private defines */

void MX_TIM2_Init(void);

/* USER CODE BEGIN Prototypes */

/** @brief ������ ������� */
void MX_TIM2_Start(void);

/** @brief ������� ������� */
void MX_TIM2_Stop(void);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __TIM_H__ */

