/* @page task-smp.h
 *       Platform-InDependent Code / FreeRTOS
 *       Symmetric Multi-Processing (SMP) task
 *       2024, atgroup09@gmail.com
 */

#ifndef TASK_SMP_H_
#define TASK_SMP_H_

#include "rtos.h"
#include "task-rtc.h"


/** @def Task delay, msec
 */
#define TASK_SMP_DELAY	1000u


/** @brief  SML Task: send current info.
 *  @param  None.
 *  @return None.
 *  @note
 *  static void TaskSMP_SendInfo(void);
 */

/** @brief  SMP Task.
 *  @param  ParamsIn - pointer to additional task parameters.
 *  @return None.
 */
void TaskSMP(void *ParamsIn);

#endif /* TASK_SMP_H_ */
