/* USER CODE BEGIN Header */
/** 
 * @file dma.h
 * @brief <h1>������ ���������� DMA</h1>
 * @author <a href="mailto://acoustics@list.ru">�������� ������� �����������</a>
 * @date 18 ����� 2023 �.
 * @details
 * ������ ������ ������������ ������������� ���������� ������ DMA, ��� �������,
 * ��������� ������� ��������� � ������ ������, �, ��� ��, ���������� ������������
 * ������ �� ���� ����
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
/** @brief ������������� ������ DMA */
/* USER CODE END Private defines */

void MX_DMA_Init(void);

/* USER CODE BEGIN Prototypes */
/** @brief ��������� ������ ��������� (��������� ������)
    @param [in] addr ����� ������������ ������
*/
void MX_DMA_SetPeriAddr(void *addr);

/** @brief ��������� ������ ������ ������ (��������� ������)
    @param [in] addr ����� ������ ������
*/
void MX_DMA_SetMemAddr(void *addr);

/** @brief ���������� ������� DMA
    @param [in] enable true �������� ������ DMA<br>
		                   false ��������� ������ DMA
*/
void MX_DMA_Control(bool enable);

/** @brief ��������� ���������� ������������ ������ � ����� �����
    @param [in] count ���������� ������������ ������
*/
void MX_DMA_SetDataCount(uint32_t count);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __DMA_H__ */

