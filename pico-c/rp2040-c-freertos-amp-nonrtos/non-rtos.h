/* @page non-rtos.h
 *       Platform-InDependent Code / nonRTOS
 *       nonRTOS context
 *       2024, atgroup09@gmail.com
 */

#ifndef NON_RTOS_H_
#define NON_RTOS_H_

#include <stdint.h>

#include "pico/stdlib.h"
#include "pico/util/queue.h"
#include "pico/multicore.h"


/** TASK
 *    *_T_NAME     - task name
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


/** UART0
 *  ===============
 */

/** @def  UART0 Task
 *  @note blocking by queue TASK_UART0_Q
 */
#define TASK_UART0_T_NAME              "T_UART0"

/** @def  UART0 Queue item
 *  @note structure
 */
typedef struct TASK_UART0_Q_t_
{
    //@var Task ID
    uint8_t  ID;
    //@var TimeStamp items
    int16_t  TS_year;
    int8_t   TS_month;
    int8_t   TS_day;
    int8_t   TS_hour;
    int8_t   TS_min;
    int8_t   TS_sec;
    //@var The number of core that a task is currently running on (result of get_core_num())
    uint8_t  CoreNum;
    //@var The core affinity mask (result of vTaskCoreAffinityGet())
    int8_t   CoreMask;

} TASK_UART0_Q_t;

/** @def  UART0 Queue item
 *  @note task IDs
 */
#define TASK_UART0_Q_ID_INIT     		0
#define TASK_UART0_Q_ID_LED_TOGGLE		1
#define TASK_UART0_Q_ID_RTC_ALARM		2
#define TASK_UART0_Q_ID_DEMO_A			3
#define TASK_UART0_Q_ID_DEMO_B			4
#define TASK_UART0_Q_ID_DEMO_C			5
#define TASK_UART0_Q_ID_DEMO_D			6

/** @def  UART0 Queue
 *  @note ID of task
 */
#define TASK_UART0_Q_ISZ    			(UBaseType_t)sizeof(TASK_UART0_Q_t)
#define TASK_UART0_Q_SZ     			(UBaseType_t)(8)
extern queue_t TASK_UART0_Q;


#endif /* NON_RTOS_H_ */
