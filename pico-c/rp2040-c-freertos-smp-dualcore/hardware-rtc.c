/* @page hardware-rtc.c
 *       Platform-Dependent Code (RP2040)
 *       RTC driver
 *       2024, atgroup09@gmail.com
 */

#include "hardware-rtc.h"


/** @var RTC init-flag
 */
static uint8_t PLC_RTC_INITED = 0;


bool PlcRTC_Set(datetime_t *DateTimeIn)
{
	if(DateTimeIn)
	{
		rtc_set_datetime(DateTimeIn);
		return (true);
	}
	return (false);
}

bool PlcRTC_Get(datetime_t *DateTimeIn)
{
	if(DateTimeIn)
	{
		rtc_get_datetime(DateTimeIn);
		return (true);
	}
	return (false);
}

bool PlcRTC_GetStr(char *StrIn, uint StrSzIn)
{
	if(StrIn && StrSzIn && PLC_RTC_INITED)
	{
		datetime_t t;
		PlcRTC_Get(&t);
		datetime_to_str(StrIn, StrSzIn, &t);
		return (true);
	}
	return (false);
}

bool PlcRTC_SetAlarm(datetime_t *DateTimeIn, rtc_callback_t UserCallbackIn)
{
	if(DateTimeIn && UserCallbackIn)
	{
		rtc_set_alarm(DateTimeIn, UserCallbackIn);
		return (true);
	}
	return (false);
}

void PlcRTC_Init(void)
{
	//datetime by default
	datetime_t t = {.year  = 2024,
					.month = 10,
					.day   = 10,
					.dotw  = 4, // 0 is Sunday, so 5 is Friday
					.hour  = 11,
					.min   = 15,
					.sec   = 00
					};

	rtc_init();
	PlcRTC_Set(&t);

	// clk_sys is >2000x faster than clk_rtc, so datetime is not updated immediately when rtc_get_datetime() is called.
	// The delay is up to 3 RTC clock cycles (which is 64us with the default clock settings)
	sleep_us(64);

	PLC_RTC_INITED = 1;
}

void PlcRTC_DeInit(void)
{

}
