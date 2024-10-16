/* @page rtos.c
 *       Platform-InDependent Code / FreeRTOS
 *       RTOS context
 *       2024, atgroup09@gmail.com
 */

#include "rtos.h"


/** @def  Tasks
 */
TaskHandle_t TASK_LED_T;
TaskHandle_t TASK_UART0_T;
TaskHandle_t TASK_DEMO_A_T;
TaskHandle_t TASK_DEMO_B_T;
TaskHandle_t TASK_DEMO_C_T;
TaskHandle_t TASK_DEMO_D_T;


/** @def  Queues
 */


/** @def  Semaphores
 */


/** @def  Mutexes
 */
SemaphoreHandle_t TASK_RTC_MTX;
