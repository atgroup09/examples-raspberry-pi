/* @page main.c
 *       Main task
 *       2024, atgroup09@gmail.com
 */

#include "main.h"
#include "task-led.h"
#include "task-uart.h"
#include "task-rtc.h"


/** @brief  Main function.
 *  @param  None.
 *  @return None.
 */
int main(void)
{
	/** INIT
	 */

	TaskLED_Init();
	TaskUART_Init();
	TaskRTC_Init();


    /** PRESTART
     */


    /** START
     */

	while(1)
	{
		TaskUART();
		TaskLED();
	}


    /** ERROR: doesn't start
     */
}
