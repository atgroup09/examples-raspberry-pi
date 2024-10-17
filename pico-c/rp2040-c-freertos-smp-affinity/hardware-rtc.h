/* @page hardware-rtc.h
 *       Platform-Dependent Code (RP2040)
 *       RTC driver
 *       2024, atgroup09@gmail.com
 */

#ifndef HARDWARE_RTC_H_
#define HARDWARE_RTC_H_

#include <stdio.h>
#include "hardware/rtc.h"
#include "pico/stdlib.h"
#include "pico/util/datetime.h"


/** @brief  RTC set datetime.
 *  @param  DateTimeIn - pointer to datetime-structure.
 *  @return Result:
 *  @param  = false or true
 */
bool PlcRTC_Set(datetime_t *DateTimeIn);

/** @brief  RTC get datetime.
 *  @param  DateTimeIn - pointer to datetime-structure.
 *  @return Result:
 *  @param  = false or true
 */
bool PlcRTC_Get(datetime_t *DateTimeIn);

/** @brief  RTC get datetime in standard string-format.
 *  @param  StrIn   - pointer to string buffer.
 *  @param  StrSzIn - the size of the passed in buffer.
 *  @return Result:
 *  @param  = false or true
 */
bool PlcRTC_GetStr(char *StrIn, uint StrSzIn);

/** @brief  RTC set alarm.
 *  @param  DateTimeIn - pointer to datetime-structure.
 *  @param  UserCallbackIn - pointer to user callback-function.
 *  @return Result:
 *  @param  = false or true
 */
bool PlcRTC_SetAlarm(datetime_t *DateTimeIn, rtc_callback_t UserCallbackIn);

/** @brief  RTC init.
 *  @param  None.
 *  @return None.
 */
void PlcRTC_Init(void);

/** @brief  RTC deinit.
 *  @param  None.
 *  @return None.
 */
void PlcRTC_DeInit(void);

#endif /* HARDWARE_RTC_H_ */
