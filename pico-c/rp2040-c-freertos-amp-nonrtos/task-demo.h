/* @page task-demo.h
 *       Platform-InDependent Code / FreeRTOS
 *       Demo task
 *       2024, atgroup09@gmail.com
 */

#ifndef TASK_DEMO_H_
#define TASK_DEMO_H_

#include "rtos.h"
#include "non-rtos.h"
#include "task-rtc.h"


/** @def Task delay, msec
 */
#define TASK_DEMO_DELAY	1000u


/** @brief  DEMO Task: send current info.
 *  @param  None.
 *  @return None.
 *  @note
 *  static void TaskDEMO_SendInfo(void);
 */

/** @brief  DEMO Task.
 *  @param  ParamsIn - pointer to additional task parameters.
 *  @return None.
 */
void TaskDEMO(void *ParamsIn);

#endif /* TASK_DEMO_H_ */
