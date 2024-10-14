/* @page task-uart.h
 *       Platform-InDependent Code / Baremetal
 *       UART task
 *       2024, atgroup09@gmail.com
 */

#ifndef TASK_UART_H_
#define TASK_UART_H_

#include "main.h"
#include "hardware-uart.h"


/** @brief  Task UART init.
 *  @param  None.
 *  @return None.
 */
void TaskUART_Init(void);

/** @brief  Task UART (blocked).
 *  @param  None.
 *  @return None.
 */
void TaskUART(void);

#endif /* TASK_UART_H_ */
