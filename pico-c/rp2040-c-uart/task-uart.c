/* @page task-uart.h
 *       Platform-InDependent Code / Baremetal
 *       UART task
 *       2024, atgroup09@gmail.com
 */

#include "task-uart.h"


/** @var UART buffer
 */
#define TASK_UART_BUFF_SZ  100
static char TASK_UART_BUFF[TASK_UART_BUFF_SZ];

/** @var UART init-flag
 */
static uint8_t TASK_UART_INITED = 0;


void TaskUART_Init(void)
{
	PlcUART0_Init();
}

void TaskUART(void)
{
	if(!TASK_UART_INITED)
	{
		sprintf(TASK_UART_BUFF, "= RP2040-C-UART\n\r= PLC.%d.%d RTE.%d (%d %d)\n\r", PLC_HW_CODE, PLC_HW_VAR, PLC_RTE_VERSION, PLC_RTE_YYYY, PLC_RTE_DDMM);
		PlcUART0_PutStr(TASK_UART_BUFF);
		TASK_UART_INITED = 1;
	}

	PlcUART0_PutStr("TASK.UART\n\r");
}
