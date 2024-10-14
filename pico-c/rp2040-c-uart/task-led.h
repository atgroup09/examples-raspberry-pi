/* @page task-led.h
 *       Platform-InDependent Code / Baremetal
 *       LED task
 *       2024, atgroup09@gmail.com
 */

#ifndef TASK_LED_H_
#define TASK_LED_H_

#include "hardware-led.h"


/** @brief  Task LED init.
 *  @param  None.
 *  @return None.
 */
void TaskLED_Init(void);

/** @brief  Task LED (blocked).
 *  @param  None.
 *  @return None.
 */
void TaskLED(void);

#endif /* TASK_LED_H_ */
