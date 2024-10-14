/* @page hardware-rtc.c
 *       Platform-Dependent Code (RP2040)
 *       RTC driver
 *       2024, atgroup09@gmail.com
 */

#include "hardware-rtc.h"


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
	if(StrIn && StrSzIn)
	{
		datetime_t t;
		PlcRTC_Get(&t);
		datetime_to_str(StrIn, StrSzIn, &t);
		return (true);
	}
	return (false);
}

void PlcRTC_Init(void)
{
	rtc_init();
}

void PlcRTC_DeInit(void)
{

}
