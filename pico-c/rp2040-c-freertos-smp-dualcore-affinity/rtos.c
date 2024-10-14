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
TaskHandle_t TASK_SMP_A_T;
TaskHandle_t TASK_SMP_B_T;
TaskHandle_t TASK_SMP_C_T;
TaskHandle_t TASK_SMP_D_T;


/** @def  Queues
 */
QueueHandle_t TASK_UART0_Q;


/** @def  Semaphores
 */


/** @def  Mutexes
 */
SemaphoreHandle_t TASK_RTC_MTX;
