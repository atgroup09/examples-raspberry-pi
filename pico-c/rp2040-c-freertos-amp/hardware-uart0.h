/* @page hardware-uart.h
 *       Platform-Dependent Code (RP2040)
 *       UART.0 driver
 *       2024, atgroup09@gmail.com
 */

/** @note
 *			UART.0
 *			- Tx -> GPIO.0
 *			- Rx <- GPIO.1
 */

#ifndef HARDWARE_UART_H_
#define HARDWARE_UART_H_

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"


/** @def UART.0
 */
#define PLC_UART0             uart0
#define PLC_UART0_RX_PIN      1
#define PLC_UART0_TX_PIN      0
#define PLC_UART0_BAUDRATE    115200
#define PLC_UART0_DATABITS    8
#define PLC_UART0_STOPBITS    1
#define PLC_UART0_PARITY      UART_PARITY_NONE


/** @brief  UART.0 init.
 *  @param  None.
 *  @return None.
 */
void PlcUART0_Init(void);

/** @brief  UART.0 deinit.
 *  @param  None.
 *  @return None.
 */
void PlcUART0_DeInit(void);

/** @brief  Write string to UART.0 for transmission.
 *  @param  StrIn - pointer to a string-buffer.
 *  @return None.
 */
void PlcUART0_Tx(const char *StrIn);

#endif /* HARDWARE_UART_H_ */
