/* @page task-demo.c
 *       Platform-InDependent Code / FreeRTOS
 *       Demo task
 *       2024, atgroup09@gmail.com
 */

#include <task-demo.h>


static void TaskDEMO_SendInfo(void)
{
	datetime_t t;
	TaskRTC_GetDateTime(&t);

	TaskHandle_t TaskHandle = xTaskGetCurrentTaskHandle();

	TASK_UART0_Q_t TASK_UART0_Q_Item;
	if(TaskHandle == TASK_DEMO_A_T)
	{
		TASK_UART0_Q_Item.ID = TASK_UART0_Q_ID_DEMO_A;
	}
	else if(TaskHandle == TASK_DEMO_B_T)
	{
		TASK_UART0_Q_Item.ID = TASK_UART0_Q_ID_DEMO_B;
	}
	else if(TaskHandle == TASK_DEMO_C_T)
	{
		TASK_UART0_Q_Item.ID = TASK_UART0_Q_ID_DEMO_C;
	}
	else if(TaskHandle == TASK_DEMO_D_T)
	{
		TASK_UART0_Q_Item.ID = TASK_UART0_Q_ID_DEMO_D;
	}
	TASK_UART0_Q_Item.TS_year  = t.year;
	TASK_UART0_Q_Item.TS_month = t.month;
	TASK_UART0_Q_Item.TS_day   = t.day;
	TASK_UART0_Q_Item.TS_hour  = t.hour;
	TASK_UART0_Q_Item.TS_min   = t.min;
	TASK_UART0_Q_Item.TS_sec   = t.sec;
	TASK_UART0_Q_Item.CoreMask = -1;
	TASK_UART0_Q_Item.CoreNum  = get_core_num();

	//TASK_UART0_Q: send (not-blocking mode)
	queue_try_add(&TASK_UART0_Q, &TASK_UART0_Q_Item);
}

void TaskDEMO(void *ParamsIn)
{
	//variables

	//fix unused
	(void)ParamsIn;

	//init hardware

	//start
	for(;;)
	{
		TaskDEMO_SendInfo();
		vTaskDelay(TASK_DEMO_DELAY);

		//fast switch to other task
		taskYIELD();
	}

	//error start
}
