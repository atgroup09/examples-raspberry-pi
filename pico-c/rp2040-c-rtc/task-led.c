/* @page task-led.c
 *       Platform-InDependent Code / Baremetal
 *       LED task
 *       2024, atgroup09@gmail.com
 */

#include "task-led.h"


void TaskLED_Init(void)
{
	PlcLED_Init();
}

void TaskLED(void)
{
	PlcLED_Toggle();
	sleep_ms(PLC_LED_USER_BLINK_PERIOD);
}
