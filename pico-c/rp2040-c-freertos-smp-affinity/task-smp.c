/* @page task-smp.c
 *       Platform-InDependent Code / FreeRTOS
 *       Symmetric Multi-Processing (SMP) task
 *       2024, atgroup09@gmail.com
 */

#include "task-smp.h"


static void TaskSMP_SendInfo(void)
{
	datetime_t t;
	TaskRTC_GetDateTime(&t);

	TaskHandle_t TaskHandle = xTaskGetCurrentTaskHandle();

	TASK_UART0_Q_t TASK_UART0_Q_Item;
	if(TaskHandle == TASK_SMP_A_T)
	{
		TASK_UART0_Q_Item.ID = TASK_UART0_Q_ID_SMP_A;
	}
	else if(TaskHandle == TASK_SMP_B_T)
	{
		TASK_UART0_Q_Item.ID = TASK_UART0_Q_ID_SMP_B;
	}
	else if(TaskHandle == TASK_SMP_C_T)
	{
		TASK_UART0_Q_Item.ID = TASK_UART0_Q_ID_SMP_C;
	}
	else if(TaskHandle == TASK_SMP_D_T)
	{
		TASK_UART0_Q_Item.ID = TASK_UART0_Q_ID_SMP_D;
	}
	TASK_UART0_Q_Item.TS_year  = t.year;
	TASK_UART0_Q_Item.TS_month = t.month;
	TASK_UART0_Q_Item.TS_day   = t.day;
	TASK_UART0_Q_Item.TS_hour  = t.hour;
	TASK_UART0_Q_Item.TS_min   = t.min;
	TASK_UART0_Q_Item.TS_sec   = t.sec;
	TASK_UART0_Q_Item.CoreMask = vTaskCoreAffinityGet(TaskHandle);
	TASK_UART0_Q_Item.CoreNum  = get_core_num();

	//TASK_UART0_Q: send (not-blocking mode)
	xQueueSendToBack(TASK_UART0_Q, &TASK_UART0_Q_Item, 0);
}

void TaskSMP(void *ParamsIn)
{
	//variables

	//fix unused
	(void)ParamsIn;

	//init hardware

	//start
	for(;;)
	{
		TaskSMP_SendInfo();
		vTaskDelay(TASK_SMP_DELAY);

		//fast switch to other task
		taskYIELD();
	}

	//error start
}
