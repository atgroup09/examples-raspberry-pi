/* @page main.c
 *       Main task
 *       2024, atgroup09@gmail.com
 */

/** @note
 * 		 CORE.0 - nonRTOS (main loop)
 * 		 CORE.1 - RTOS (FreeRTOS)
 *
 * 		 Multi-core thread-safe communication via queue TASK_UART0_Q
 */

#include "main.h"
#include "error.h"

#include "task-led.h"
#include "task-rtc.h"
#include "task-uart0.h"
#include "task-demo.h"


/** @brief  Main function.
 *  @param  None.
 *  @return None.
 */
int main(void)
{
	/** INIT
	 *  nonRTOS
	 */

	// Multi-core thread-safe communication
	queue_init(&TASK_UART0_Q, TASK_UART0_Q_ISZ, TASK_UART0_Q_SZ);


	/** INIT
	 *  RTOS
	 */

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

	//SMP

	TASK_DEMO_A_T = NULL;
	if(xTaskCreate(TaskDEMO, "T_DEMO_A", TASK_DEMO_T_STACK_SZ, NULL, TASK_DEMO_T_PRIORITY, &TASK_DEMO_A_T) != pdTRUE)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	TASK_DEMO_B_T = NULL;
	if(xTaskCreate(TaskDEMO, "T_DEMO_B", TASK_DEMO_T_STACK_SZ, NULL, TASK_DEMO_T_PRIORITY, &TASK_DEMO_B_T) != pdTRUE)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	TASK_DEMO_C_T = NULL;
	if(xTaskCreate(TaskDEMO, "T_DEMO_C", TASK_DEMO_T_STACK_SZ, NULL, TASK_DEMO_T_PRIORITY, &TASK_DEMO_C_T) != pdTRUE)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	TASK_DEMO_D_T = NULL;
	if(xTaskCreate(TaskDEMO, "T_DEMO_D", TASK_DEMO_T_STACK_SZ, NULL, TASK_DEMO_T_PRIORITY, &TASK_DEMO_D_T) != pdTRUE)
	{
		_Error_Handler(__FILE__, __LINE__);
	}


    /** PRESTART
     */


    /** START
     *  nonRTOS
     */

	multicore_launch_core1(TaskUART0);


    /** START
     *  RTOS
     */

	vTaskStartScheduler();


    /** ERROR: doesn't start
     */

	_Error_Handler(__FILE__, __LINE__);
}
