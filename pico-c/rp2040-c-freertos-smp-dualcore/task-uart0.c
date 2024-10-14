/* @page task-uart0.c
 *       Platform-InDependent Code / FreeRTOS
 *       UART0 task
 *       2024, atgroup09@gmail.com
 */

#include "task-uart0.h"


/** @var Buffer
 */
#define TASK_UART0_BUFF_SZ  100
static char TASK_UART0_BUFF[TASK_UART0_BUFF_SZ];

/** @var Init-flag
 */
static uint8_t TASK_UART0_INITED = 0;

/** @var Info-event names
 */
#define TASK_UART0_NAMES_SZ 3
static const char *TASK_UART0_NAMES[TASK_UART0_NAMES_SZ] = {
	"INIT",
	"LED.TOGGLE",
	"RTC.ALARM"
};


static void TaskUART0_Init(void)
{
	PlcUART0_Init();
}

static void TaskUART0_DeInit(void)
{
	PlcUART0_DeInit();
}

/** @brief  UART0 data process
 *  @param  InfoIn - pointer to info-item.
 *  @return None.
 */
static void TaskUART0_PrintInfo(const TASK_UART0_Q_t *InfoIn)
{
	if(InfoIn)
	{
		switch(InfoIn->ID)
		{
			case TASK_UART0_Q_ID_INIT:
				sprintf(TASK_UART0_BUFF, "= RP2040-C-UART: PLC.%d.%d RTE.%d (%d %d)\n\r", PLC_HW_CODE, PLC_HW_VAR, PLC_RTE_VERSION, PLC_RTE_YYYY, PLC_RTE_DDMM);
				break;

			case TASK_UART0_Q_ID_LED_TOGGLE:
			case TASK_UART0_Q_ID_RTC_ALARM:
				sprintf(TASK_UART0_BUFF, "%02d-%02d-%02d %02d:%02d:%02d: %s core=%d mask=%d [this core=%d]\n\r", InfoIn->TS_year, InfoIn->TS_month, InfoIn->TS_day, InfoIn->TS_hour, InfoIn->TS_min, InfoIn->TS_sec, TASK_UART0_NAMES[InfoIn->ID], InfoIn->CoreNum, InfoIn->CoreMask, get_core_num());
				break;
		}

		PlcUART0_Tx(TASK_UART0_BUFF);
	}
}

void TaskUART0(void *ParamsIn)
{
	//variables
	TASK_UART0_Q_t TASK_UART0_Q_Item;
	BaseType_t     TASK_UART0_Q_Status;

	//fix unused
	(void)ParamsIn;

	//init hardware
	TaskUART0_Init();

	//start
	for(;;)
	{
		if(!TASK_UART0_INITED)
		{
			TASK_UART0_Q_Item.ID = TASK_UART0_Q_ID_INIT;
			TaskUART0_PrintInfo(&TASK_UART0_Q_Item);
			TASK_UART0_INITED = 1;
		}

		//TASK_UART0_Q: read (blocking mode)
		TASK_UART0_Q_Status = xQueueReceive(TASK_UART0_Q, &TASK_UART0_Q_Item, portMAX_DELAY);
		if(TASK_UART0_Q_Status == pdPASS)
		{
			TaskUART0_PrintInfo(&TASK_UART0_Q_Item);
		}
	}

	//error start
	TaskUART0_DeInit();
}
