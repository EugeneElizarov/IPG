/* ************************************************************************** */
/** 
 * @file stdout.c 
 * @brief <h1>������ ��������������� ������ � ����������� ���� stdout</h1>
 * @author <a href="mailto://acoustics@list.ru">�������� ������� �����������</a>
 * @date 18 ����� 2023 �.
 * @details
 * ��������������� ������������ ������ ����������� � ������ ����������� ������� 
 * fputc. ����� ��� ���� �������� ���������� ��������� ���������� __use_no_semihosting
 * ��� �������� ��-�������, � ����������� �� ������ �����������. ��� ������ �� 6.0 �
 * ���������� �������:
 * @code
 * __asm (".global __use_no_semihosting\n");
 * @endcode
 * ��� ����������� � ������� ������ 6.0 ����������� �������� ��������� �������:
 * @code
 * #pragma import(__use_no_semihosting)
 * @endcode
 * ��� �� ��� ������ �� 6.0 ���������� ��������������� ������� _sys_open.
 * ��������� � ��� ������ ������� _sys_exit � _ttywrch. ��� � ����� ��������
 * �� ������������, �� ��������������� �� ����������, ����� ���������� �� 
 * ������� �� �� ����� ������� �� ���������
 * ************************************************************************** */

#include <stdint.h>
#include <stdio.h>

#include "EventRecorder.h"

#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION > 6000000)
#include <rt_sys.h>

__asm (".global __use_no_semihosting\n");

extern void $Super$$_sys_open(void);

FILEHANDLE $Sub$$_sys_open(const char *name, int openmode)
{
 return 1;
}

#else
#ifdef __CC_ARM
#pragma import(__use_no_semihosting)
struct __FILE
{
  int handle;
};
FILE __stdout;
#endif
#endif

void _sys_exit(int x)
{
  (void) x;
}

void _ttywrch(int ch)
{
  (void) ch;
}

/** @brief ��������������� ������ � ����������� ���� stdout ����� EventRecorder
 * @param [in] ch ��������� ������
 * @param [in] f ����, � ������ ��������� ������ (������������)
 * @return ���������� ������
 */
int fputc(int ch, FILE *f)
{
	(void)f;
  static uint32_t index = 0U;
  static uint8_t  buffer[8];
 
  if (index >= 8U) 
	{
    return (-1);
  }
	if ((ch == '\n') || (ch == '\r'))
	{
		while (index < 7)
			buffer[index++] = 0x20;
		ch = '\n';
	}
  buffer[index++] = (uint8_t)ch;
  if (index == 8) 
	{
    EventRecordData(EventID(EventLevelOp, 0xFE, 0x00), buffer, index);
    index = 0U;
  }
  return (ch);
}
