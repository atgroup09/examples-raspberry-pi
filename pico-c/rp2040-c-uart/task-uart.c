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
	PlcUART0_PutStr("TASK.UART");
}
