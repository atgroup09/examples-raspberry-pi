/* @page main.c
 *       Main task
 *       2024, atgroup09@gmail.com
 */

#include "main.h"
#include "error.h"

#include "task-led.h"
#include "task-rtc.h"
#include "task-uart0.h"


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

    //TASK_UART0_T = NULL;
	if(xTaskCreate(TaskUART0, TASK_UART0_T_NAME, TASK_UART0_T_STACK_SZ, NULL, TASK_UART0_T_PRIORITY, &TASK_UART0_T) != pdTRUE)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	//LED

	TASK_LED_T = NULL;
	if(xTaskCreate(TaskLED, TASK_LED_T_NAME, TASK_LED_T_STACK_SZ, NULL, TASK_LED_T_PRIORITY, &TASK_LED_T) != pdTRUE)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	//RTC

	TaskRTC_Init();

	TASK_RTC_MTX = xSemaphoreCreateMutex();
	if(!TASK_RTC_MTX) _Error_Handler(__FILE__, __LINE__);


    /** PRESTART
     */


    /** START
     */

	vTaskStartScheduler();


    /** ERROR: doesn't start
     */

	_Error_Handler(__FILE__, __LINE__);
}
