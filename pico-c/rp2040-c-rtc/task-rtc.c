/* @page task-rtc.c
 *       Platform-InDependent Code / Baremetal
 *       RTC task
 *       2024, atgroup09@gmail.com
 */

#include "task-rtc.h"


void TaskRTC_Init(void)
{
	datetime_t t = {.year  = 2024,
					.month = 10,
					.day   = 7,
					.dotw  = 1, // 0 is Sunday, so 5 is Friday
					.hour  = 15,
					.min   = 29,
					.sec   = 00
					};

	PlcRTC_Init();
	PlcRTC_Set(&t);

	// clk_sys is >2000x faster than clk_rtc, so datetime is not updated immediately when rtc_get_datetime() is called.
	// The delay is up to 3 RTC clock cycles (which is 64us with the default clock settings)
	sleep_us(64);
}
