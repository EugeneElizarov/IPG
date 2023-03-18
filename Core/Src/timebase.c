/** 
 * @file tim.h
 * @brief <h1>������ ����������� ������ EventRecorder</h1>
 * @author <a href="mailto://acoustics@list.ru">�������� ������� �����������</a>
 * @date 18 ����� 2023 �.
 * ************************************************************************** */
#include "stm32f0xx_hal.h"

#include "EventRecorder.h"

#define SYSTICK_PERIOD		SysTick->LOAD

static volatile uint32_t SysTickCount; 		///< �������� ���������� "�����" ��������� ������� ��� SysTick
static volatile uint8_t  SysTickUpdated;	///< ������� ���������� ���������� SysTickCount

/** @brief ���������� ���������� ������� SysTick */
void HAL_IncTick(void)
{
  SysTickCount  += SYSTICK_PERIOD;
  SysTickUpdated = 1U;
  uwTick += uwTickFreq;
}

/** @brief ��������� ������� ������� ����������� ������ EventRecorder 
@return ������� ��������� ������� ������� ����������� ������ EventRecorder � �� 
*/
uint32_t EventRecorderTimerGetFreq (void)
{
	return SYSTICK_PERIOD * 1000 / uwTickFreq;
}

/** @brief ��������� ������� �������� ��������� "�����" � ������� ������� �������
@return �������� �������� �������
*/
uint32_t EventRecorderTimerGetCount (void)
{
  uint32_t val;
 
  do {
    SysTickUpdated = 0U;
    val  = SysTickCount;
    val += (SYSTICK_PERIOD - 1U) - SysTick->VAL;
  } while (SysTickUpdated != 0U);
 
  return (val);
}

/** @brief ������������ ������� ����������� ������ EventRecorder. 
�� ������������. ���������� 1
*/
uint32_t EventRecorderTimerSetup (void)
{
	return 1U;
}
