/* @page main.c
 *       Main task
 *       2024, atgroup09@gmail.com
 */

#include "main.h"
#include "error.h"

#include "task-led.h"
#include "task-rtc.h"
#include "task-uart0.h"
#include "task-smp.h"


/** @brief  Main function.
 *  @param  None.
 *  @return None.
 */
int main(void)
{
	/** INIT
	 */

	//UART0

	TASK_UART0_Q = xQueueCreate(TASK_UART0_Q_SZ, TASK_UART0_Q_ISZ);
    if(!TASK_UART0_Q) _Error_Handler(__FILE__, __LINE__);

    TASK_UART0_T = NULL;
	if(xTaskCreate(TaskUART0, TASK_UART0_T_NAME, TASK_UART0_T_STACK_SZ, NULL, TASK_UART0_T_PRIORITY, &TASK_UART0_T) != pdTRUE)
	{
		_Error_Handler(__FILE__, __LINE__);
	}
	//pin to CORE.0
	vTaskCoreAffinitySet(TASK_UART0_T, (1<<0));

	//RTC

	TaskRTC_Init();

	TASK_RTC_MTX = xSemaphoreCreateMutex();
	if(!TASK_RTC_MTX) _Error_Handler(__FILE__, __LINE__);

	//LED

	TASK_LED_T = NULL;
	if(xTaskCreate(TaskLED, TASK_LED_T_NAME, TASK_LED_T_STACK_SZ, NULL, TASK_LED_T_PRIORITY, &TASK_LED_T) != pdTRUE)
	{
		_Error_Handler(__FILE__, __LINE__);
	}
	//pin to CORE.1
	vTaskCoreAffinitySet(TASK_LED_T, (1<<1));

	//SMP

	TASK_SMP_A_T = NULL;
	if(xTaskCreate(TaskSMP, "T_SMP_A", TASK_SMP_T_STACK_SZ, NULL, TASK_SMP_T_PRIORITY, &TASK_SMP_A_T) != pdTRUE)
	{
		_Error_Handler(__FILE__, __LINE__);
	}
	//pin to CORE.0
	vTaskCoreAffinitySet(TASK_SMP_A_T, (1<<1));

	TASK_SMP_B_T = NULL;
	if(xTaskCreate(TaskSMP, "T_SMP_B", TASK_SMP_T_STACK_SZ, NULL, TASK_SMP_T_PRIORITY, &TASK_SMP_B_T) != pdTRUE)
	{
		_Error_Handler(__FILE__, __LINE__);
	}
	//pin to CORE.1
	vTaskCoreAffinitySet(TASK_SMP_B_T, (1<<1));

	TASK_SMP_C_T = NULL;
	if(xTaskCreate(TaskSMP, "T_SMP_C", TASK_SMP_T_STACK_SZ, NULL, TASK_SMP_T_PRIORITY, &TASK_SMP_C_T) != pdTRUE)
	{
		_Error_Handler(__FILE__, __LINE__);
	}
	//the task is not pinned to any core, can run on either core

	TASK_SMP_D_T = NULL;
	if(xTaskCreate(TaskSMP, "T_SMP_D", TASK_SMP_T_STACK_SZ, NULL, TASK_SMP_T_PRIORITY, &TASK_SMP_D_T) != pdTRUE)
	{
		_Error_Handler(__FILE__, __LINE__);
	}
	//the task is not pinned to any core, can run on either core


    /** PRESTART
     */


    /** START
     */

	vTaskStartScheduler();


    /** ERROR: doesn't start
     */

	_Error_Handler(__FILE__, __LINE__);
}
