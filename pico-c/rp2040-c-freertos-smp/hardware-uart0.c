/* @page hardware-uart.c
 *       Platform-Dependent Code (RP2040)
 *       UART.0 driver
 *       2024, atgroup09@gmail.com
 */

#include "hardware-uart0.h"


void PlcUART0_Init(void)
{
	//configure GPIO
	gpio_set_function(PLC_UART0_RX_PIN, GPIO_FUNC_UART);
	gpio_set_function(PLC_UART0_TX_PIN, GPIO_FUNC_UART);

	//set data format
	uart_set_format(PLC_UART0, PLC_UART0_DATABITS, PLC_UART0_STOPBITS, PLC_UART0_PARITY);

	//init
	uart_init(PLC_UART0, PLC_UART0_BAUDRATE);
}

void PlcUART0_DeInit(void)
{
	uart_deinit(PLC_UART0);
}

void PlcUART0_Tx(const char *StrIn)
{
	if(StrIn)
	{
		uart_puts(PLC_UART0, StrIn);
	}
}
