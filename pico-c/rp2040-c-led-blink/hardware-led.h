/* @page hardware-led.h
 *       Platform-Dependent Code (RP2040)
 *       LED driver
 *       2024, atgroup09@gmail.com
 */

/** @note
 *       GPIO25 <- PLC_LED_USER (PICO_DEFAULT_LED_PIN)
 */

#ifndef HARDWARE_LED_H_
#define HARDWARE_LED_H_

#include "hardware-gpio.h"


/** @def GPIO
 */
#ifdef PICO_DEFAULT_LED_PIN
#define PLC_LED_USER_PIN               (PICO_DEFAULT_LED_PIN)
#else
#define PLC_LED_USER_PIN               (25)
#endif

/** @def Blink period, msec
 */
#ifdef DEBUG
#define PLC_LED_USER_BLINK_PERIOD      5000u
#else
#define PLC_LED_USER_BLINK_PERIOD      1000u
#endif


/** @brief  Init LED.
 *  @param  None.
 *  @return None.
 */
void PlcLed_Init(void);

/** @brief  DeInit LED.
 *  @param  None.
 *  @return None.
 */
void PlcLed_DeInit(void);


/** @brief  Blink LED.
 *  @param  None.
 *  @return None.
 */
void PlcLed_Blink(void);

#endif /* HARDWARE_LED_H_ */
