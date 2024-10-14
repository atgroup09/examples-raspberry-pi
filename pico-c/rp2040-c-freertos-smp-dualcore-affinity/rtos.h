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


/** UART0
 *  ===============
 */

/** @def  UART0 Task
 *  @note blocking by queue TASK_UART0_Q
 */
#define TASK_UART0_T_NAME              "T_UART0"
#define TASK_UART0_T_STACK_SZ          (configSTACK_DEPTH_TYPE)configMINIMAL_STACK_SIZE
#define TASK_UART0_T_PRIORITY          (UBaseType_t)4
extern TaskHandle_t TASK_UART0_T;

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
#define TASK_UART0_Q_ID_SMP_A			3
#define TASK_UART0_Q_ID_SMP_B			4
#define TASK_UART0_Q_ID_SMP_C			5
#define TASK_UART0_Q_ID_SMP_D			6

/** @def  UART0 Queue
 *  @note ID of task
 */
#define TASK_UART0_Q_ISZ    			(UBaseType_t)sizeof(TASK_UART0_Q_t)
#define TASK_UART0_Q_SZ     			(UBaseType_t)(8)
extern QueueHandle_t TASK_UART0_Q;


/** RTC
 *  ===============
 */

/** @def RTC Mutex
 */
extern SemaphoreHandle_t TASK_RTC_MTX;



/** SMP
 *  ===============
 */

/** @def  SMP Task
 *  @note blocking by task-delay
 */
#define TASK_SMP_T_NAME              	"T_SMP"
#define TASK_SMP_T_STACK_SZ          	(configSTACK_DEPTH_TYPE)configMINIMAL_STACK_SIZE
#define TASK_SMP_T_PRIORITY          	(UBaseType_t)3
extern TaskHandle_t TASK_SMP_A_T;
extern TaskHandle_t TASK_SMP_B_T;
extern TaskHandle_t TASK_SMP_C_T;
extern TaskHandle_t TASK_SMP_D_T;

#endif /* RTOS_H_ */
