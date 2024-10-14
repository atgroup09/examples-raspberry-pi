/* @page main.c
 *       Main task
 *       2024, atgroup09@gmail.com
 */

#include "hardware-led.h"


int main(void)
{
	PlcLed_Init();

	while(1)
	{
		PlcLed_Blink();
	}
}
