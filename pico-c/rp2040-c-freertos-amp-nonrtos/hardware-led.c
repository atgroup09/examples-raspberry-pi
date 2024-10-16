/* @page hardware-led.c
 *       Platform-Dependent Code (RP2040)
 *       LED driver
 *       2024, atgroup09@gmail.com
 */

#include "hardware-led.h"


void PlcLED_Init(void)
{
	gpio_init(PLC_LED_USER_PIN);
	gpio_set_dir(PLC_LED_USER_PIN, GPIO_OUT);
}

void PlcLED_DeInit(void)
{
	gpio_deinit(PLC_LED_USER_PIN);
}

void PlcLED_Toggle(void)
{
	PlcGpio_DO_Toggle(PLC_LED_USER_PIN);
}
