/* @page rtos.h
 *       Platform-InDependent Code / FreeRTOS
 *       RTOS context
 *       2024, atgroup09@gmail.com
 */

#ifndef RTOS_H_
#define RTOS_H_

#include <stdint.h>

#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "timers.h"


/** TASK
 *    *_T_NAME     - task name (for debug, strlen <= configMAX_TASK_NAME_LEN)
 *    *_T_STACK_SZ - task stack size (>= configMINIMAL_STACK_SIZE)
 *    *_T_PRIORITY - task priority (<= configMAX_PRIORITIES)
 *    *_T          - task context
 *
 *  QUEUE
 *    *_Q_ISZ      - size of one queue-item (sizeof(t), where t is the item type)
 *    *_Q_SZ       - quantity of queue-items
 *    *_Q          - queue context
 *
 *  MUTEX
 *    *_MTX      - mutex context
 *
 *  SEMAPHORE (binary)
 *    *_SEMA     - semaphore context
 */


/** LED
 *  ===============
 */

/** @def  LED Task
 *  @note blocking by task-delay
 */
#define TASK_LED_T_NAME                "T_Led"
#define TASK_LED_T_STACK_SZ            (configSTACK_DEPTH_TYPE)configMINIMAL_STACK_SIZE
#define TASK_LED_T_PRIORITY            (UBaseType_t)4
extern TaskHandle_t TASK_LED_T;



/** RTC
 *  ===============
 */

/** @def RTC Mutex
 */
extern SemaphoreHandle_t TASK_RTC_MTX;



/** DEMO
 *  ===============
 */

/** @def  DEMO Task
 *  @note blocking by task-delay
 */
#define TASK_DEMO_T_NAME              	"T_DEMO"
#define TASK_DEMO_T_STACK_SZ          	(configSTACK_DEPTH_TYPE)configMINIMAL_STACK_SIZE
#define TASK_DEMO_T_PRIORITY          	(UBaseType_t)3
extern TaskHandle_t TASK_DEMO_A_T;
extern TaskHandle_t TASK_DEMO_B_T;
extern TaskHandle_t TASK_DEMO_C_T;
extern TaskHandle_t TASK_DEMO_D_T;

#endif /* RTOS_H_ */
