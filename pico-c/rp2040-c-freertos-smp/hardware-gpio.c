/* @page hardware-gpio.c
 *       Platform-Dependent Code (RP2040)
 *       GPIO common driver
 *       2024, atgroup09@gmail.com
 */

#include "hardware-gpio.h"


bool PlcGpio_DO_On(uint PinIn)
{
	gpio_put(PinIn, PLC_GPIO_ON);
	return (gpio_get(PinIn));
}

bool PlcGpio_DO_Off(uint PinIn)
{
	gpio_put(PinIn, PLC_GPIO_OFF);
	return (gpio_get(PinIn));
}

bool PlcGpio_DO_Toggle(uint PinIn)
{
	bool State = gpio_get(PinIn);
	return (State ? PlcGpio_DO_Off(PinIn) : PlcGpio_DO_On(PinIn));
}

bool PlcGpio_DO_Set(uint PinIn, bool StateIn)
{
   	return (!StateIn ? PlcGpio_DO_Off(PinIn) : PlcGpio_DO_On(PinIn));
}

bool PlcGpio_DO_Get(uint PinIn)
{
	return (gpio_get(PinIn));
}

bool PlcGpio_DI_Get(uint PinIn)
{
	return (gpio_get(PinIn));
}
