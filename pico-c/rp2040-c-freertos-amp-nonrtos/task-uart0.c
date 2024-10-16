/* @page task-uart0.c
 *       Platform-InDependent Code / nonRTOS
 *       UART0 task
 *       2024, atgroup09@gmail.com
 */

#include "task-uart0.h"


/** @var Buffer
 */
#define TASK_UART0_BUFF_SZ  200
static char TASK_UART0_BUFF[TASK_UART0_BUFF_SZ];

/** @var Init-flag
 */
static uint8_t TASK_UART0_INITED = 0;

/** @var Info-event names
 */
#define TASK_UART0_NAMES_SZ 7
static const char *TASK_UART0_NAMES[TASK_UART0_NAMES_SZ] = {
	"INIT",
	"LED.TOGGLE",
	"RTC.ALARM",
	"DEMO.A",
	"DEMO.B",
	"DEMO.C",
	"DEMO.D"
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
				sprintf(TASK_UART0_BUFF, "= RP2040-C-FREERTOS-AMP-NONRTOS: PLC.%d.%d RTE.%d (%d %d)\n\r", PLC_HW_CODE, PLC_HW_VAR, PLC_RTE_VERSION, PLC_RTE_YYYY, PLC_RTE_DDMM);
				break;

			case TASK_UART0_Q_ID_LED_TOGGLE:
			case TASK_UART0_Q_ID_RTC_ALARM:
			case TASK_UART0_Q_ID_DEMO_A:
			case TASK_UART0_Q_ID_DEMO_B:
			case TASK_UART0_Q_ID_DEMO_C:
			case TASK_UART0_Q_ID_DEMO_D:
				sprintf(TASK_UART0_BUFF, "%04d-%02d-%02d %02d:%02d:%02d: %-12s core=%d mask=%02d [UART0.TASK core=%d]\n\r", InfoIn->TS_year, InfoIn->TS_month, InfoIn->TS_day, InfoIn->TS_hour, InfoIn->TS_min, InfoIn->TS_sec, TASK_UART0_NAMES[InfoIn->ID], InfoIn->CoreNum, InfoIn->CoreMask, get_core_num());
				break;

			default:
				return;
		}

		PlcUART0_Tx(TASK_UART0_BUFF);
	}
}

void TaskUART0(void)
{
	//variables
	TASK_UART0_Q_t TASK_UART0_Q_Item;

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
		queue_remove_blocking(&TASK_UART0_Q, &TASK_UART0_Q_Item);
		TaskUART0_PrintInfo(&TASK_UART0_Q_Item);
	}

	//error start
	TaskUART0_DeInit();
}
