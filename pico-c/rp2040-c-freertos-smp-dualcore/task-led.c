/* @page task-led.c
 *       Platform-InDependent Code / FreeRTOS
 *       LED task
 *       2024, atgroup09@gmail.com
 */

#include "task-led.h"


static void TaskLED_Init(void)
{
	PlcLED_Init();
}

static void TaskLED_DeInit(void)
{
	PlcLED_DeInit();
}

static void TaskLED_SendInfo(void)
{
	datetime_t t;
	TaskRTC_GetDateTime(&t);

	//TaskHandle_t TaskHandle = xTaskGetCurrentTaskHandle();

	TASK_UART0_Q_t TASK_UART0_Q_Item;
	TASK_UART0_Q_Item.ID       = TASK_UART0_Q_ID_LED_TOGGLE;
	TASK_UART0_Q_Item.TS_year  = t.year;
	TASK_UART0_Q_Item.TS_month = t.month;
	TASK_UART0_Q_Item.TS_day   = t.day;
	TASK_UART0_Q_Item.TS_hour  = t.hour;
	TASK_UART0_Q_Item.TS_min   = t.min;
	TASK_UART0_Q_Item.TS_sec   = t.sec;
	TASK_UART0_Q_Item.CoreMask = -1; //vTaskCoreAffinityGet(TaskHandle); this function is unsupported in this FreeRTOS version
	TASK_UART0_Q_Item.CoreNum  = get_core_num();

	//TASK_UART0_Q: send (not-blocking mode)
	xQueueSendToBack(TASK_UART0_Q, &TASK_UART0_Q_Item, 0);
}

void TaskLED(void *ParamsIn)
{
	//variables

	//fix unused
	(void)ParamsIn;

	//init hardware
	TaskLED_Init();

	//start
	for(;;)
	{
		PlcLED_Toggle();
		TaskLED_SendInfo();
		vTaskDelay(PLC_LED_USER_BLINK_PERIOD);

		//fast switch to other task
		taskYIELD();
	}

	//error start
	TaskLED_DeInit();
}
