/* @page task-rtc.h
 *       Platform-InDependent Code / Baremetal
 *       RTC task
 *       2024, atgroup09@gmail.com
 */

#ifndef TASK_RTC_H_
#define TASK_RTC_H_

#include "hardware-rtc.h"
#include "rtos.h"
#include "non-rtos.h"


/** @brief  Task RTC: get datetime (thread-safe).
 *  @param  BuffIn - pointer to datetime-buffer.
 *  @return Result:
 *  @param  = false or true
 *  @note   Call only from RTOS-tasks!
 */
bool TaskRTC_GetDateTime(datetime_t *BuffIn);

/** @brief  Task RTC: send current info
 *  @param  None.
 *  @return None.
 *  @note
 *  static void TaskRTC_SendInfo(void);
 */

/** @brief  Task RTC: alarm callback-handler
 *  @param  None.
 *  @return None.
 *  @note
 *  static void TaskRTC_AlarmHandler(void);
 */

/** @brief  Task RTC: init hardware and the task context
 *  @param  None.
 *  @return None.
 */
void TaskRTC_Init(void);

#endif /* TASK_RTC_H_ */
