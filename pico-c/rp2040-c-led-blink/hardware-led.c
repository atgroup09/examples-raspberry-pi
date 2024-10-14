/* @page hardware-led.c
 *       Platform-Dependent Code (RP2040)
 *       LED driver
 *       2024, atgroup09@gmail.com
 */

#include "hardware-led.h"


void PlcLed_Init(void)
{
	gpio_init(PLC_LED_USER_PIN);
	gpio_set_dir(PLC_LED_USER_PIN, GPIO_OUT);
}

void PlcLed_DeInit(void)
{
	gpio_deinit(PLC_LED_USER_PIN);
}

void PlcLed_Blink(void)
{
	PlcGpio_DO_Toggle(PLC_LED_USER_PIN);
	sleep_ms(PLC_LED_USER_BLINK_PERIOD);
}
