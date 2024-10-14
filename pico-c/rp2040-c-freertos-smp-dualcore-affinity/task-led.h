/* @page task-led.h
 *       Platform-InDependent Code / FreeRTOS
 *       LED task
 *       2024, atgroup09@gmail.com
 */

#ifndef TASK_LED_H_
#define TASK_LED_H_

#include "hardware-led.h"
#include "rtos.h"
#include "task-rtc.h"


/** @brief  Task LED: init hardware.
 *  @param  None.
 *  @return None.
 *  @note
 *  static void TaskLED_Init(void);
 */

/** @brief  Task LED: deInit hardware.
 *  @param  None.
 *  @return None.
 *  @note
 *  static void TaskLED_DeInit(void);
 */

/** @brief  Task LED: send current info.
 *  @param  None.
 *  @return None.
 *  @note
 *  static void TaskLED_SendInfo(void);
 */

/** @brief  Task LED.
 *  @param  ParamsIn - pointer to additional task parameters.
 *  @return None.
 */
void TaskLED(void *ParamsIn);

#endif /* TASK_LED_H_ */
