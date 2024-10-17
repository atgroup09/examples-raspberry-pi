/* @page task-rtc.c
 *       Platform-InDependent Code / Baremetal
 *       RTC task
 *       2024, atgroup09@gmail.com
 */

#include "task-rtc.h"


bool TaskRTC_GetDateTime(datetime_t *BuffIn)
{
	bool Result = false;

	xSemaphoreTake(TASK_RTC_MTX, portMAX_DELAY);

	if(BuffIn)
	{
		Result = PlcRTC_Get(BuffIn);
	}

	xSemaphoreGive(TASK_RTC_MTX);

	return (Result);
}

static void TaskRTC_SendInfo(void)
{
	datetime_t t;
	TaskRTC_GetDateTime(&t);

	TASK_UART0_Q_t TASK_UART0_Q_Item;
	TASK_UART0_Q_Item.ID       = TASK_UART0_Q_ID_RTC_ALARM;
	TASK_UART0_Q_Item.TS_year  = t.year;
	TASK_UART0_Q_Item.TS_month = t.month;
	TASK_UART0_Q_Item.TS_day   = t.day;
	TASK_UART0_Q_Item.TS_hour  = t.hour;
	TASK_UART0_Q_Item.TS_min   = t.min;
	TASK_UART0_Q_Item.TS_sec   = t.sec;
	TASK_UART0_Q_Item.CoreMask = -1;
	TASK_UART0_Q_Item.CoreNum  = get_core_num();

	//TASK_UART0_Q: send (not-blocking mode)
	xQueueSendToBack(TASK_UART0_Q, &TASK_UART0_Q_Item, 0);
}

static void TaskRTC_AlarmHandler(void)
{
	TaskRTC_SendInfo();
}

void TaskRTC_Init(void)
{
	//alarm once a minute
	datetime_t t = {.year  = -1,
					.month = -1,
					.day   = -1,
					.dotw  = -1,
					.hour  = -1,
					.min   = -1,
					.sec   = 00
					};

	PlcRTC_Init();
	PlcRTC_SetAlarm(&t, &TaskRTC_AlarmHandler);
}
