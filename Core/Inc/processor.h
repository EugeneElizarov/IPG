/* ************************************************************************** */
/**
 * @file processor.h
 * @brief <h1>������ ��������� �����������</h1>
 * @author <a href="mailto://acoustics@list.ru">�������� ������� �����������</a>
 * @date 18 ����� 2023 �.
 * 
 * ************************************************************************** */

#ifndef __PROCESSOR_H__

#define __PROCESSOR_H__

#include <stdbool.h>
#include <stdint.h>

/** @brief ������� ������������� ������� ��� 
           ����������� ������ ���������� �����
*/
void Processor_Init(void);

/** @brief ������� ��������� �������� �������� ���������� ��������
    @param [in] real true - ������� �������� � ��<br>
		                 false - ������� ������� ��� ���
    @return ������� �������� ���������� ��������
*/
uint16_t Processor_GetValue(bool real);

bool Processor_DataAvailable(void);

/** @brief ������� ��������� ������ �� ���������� ��������� 
           �������� ������ �� ������ ��� � ������ �� ������ DMA
*/
void DMA_Transfer_OK(void);

#endif
