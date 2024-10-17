/* @page task-uart0.h
 *       Platform-InDependent Code / nonRTOS
 *       UART0 task
 *       2024, atgroup09@gmail.com
 */

#ifndef TASK_UART0_H_
#define TASK_UART0_H_

#include "hardware-uart0.h"
#include "hardware-rtc.h"
#include "main.h"
#include "non-rtos.h"


/** @brief  UART0 Init hardware
 *  @param  None.
 *  @return None.
 *  @note
 *  static void TaskUART0_Init(void);
 */

/** @brief  UART0 deInit hardware
 *  @param  None.
 *  @return None.
 *  @note
 *  static void TaskUART0_DeInit(void);
 */

/** @brief  UART0 data process
 *  @param  InfoIn - pointer to info-item.
 *  @return None.
 *  @note
 *  static void TaskUART0_PrintInfo(const TASK_UART0_Q_t *InfoIn);
 */

/** @brief  UART0 task.
 *  @param  None.
 *  @return None.
 */
void TaskUART0(void);

#endif /* TASK_UART0_H_ */
