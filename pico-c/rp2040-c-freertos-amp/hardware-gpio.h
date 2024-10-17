/* @page hardware-gpio.h
 *       Platform-Dependent Code (RP2040)
 *       GPIO common driver
 *       2024, atgroup09@gmail.com
 */

/** @note
 *       DI - discrete input
 *       DO - discrete output
 */

#ifndef HARDWARE_GPIO_H_
#define HARDWARE_GPIO_H_

#include "boards/pico.h"
#include "pico/stdlib.h"


/** @def GPIO states
 */
#define PLC_GPIO_OFF         (bool)0  //off
#define PLC_GPIO_ON          (bool)1  //on

/** @def DO mode
 */
#define PLC_GPIO_DO_PP       (uint8_t)0  //push-pull
#define PLC_GPIO_DO_OD       (uint8_t)1  //open-drain (LoLevel to GND, HiLevel to Up or Down)

/** @def DI mode
 */
#define PLC_GPIO_DI_NORM     (uint8_t)0  //normal
#define PLC_GPIO_DI_REVERSE  (uint8_t)1  //reverse


/** @brief  DO: Turn-On
 *  @param  PinIn - pin number
 *  @return Current Pin-status:
 *  @arg     = PLC_GPIO_ON | PLC_GPIO_OFF
 */
bool PlcGpio_DO_On(uint PinIn);

/** @brief  DO: Turn-Off
 *  @param  PinIn - pin number
 *  @return Current Pin-status:
 *  @arg    = PLC_GPIO_OFF | PLC_GPIO_ON
 */
bool PlcGpio_DO_Off(uint PinIn);

/** @brief  DO: Toggle.
 *  @param  PinIn - pin number
 *  @return Current Pin-status:
 *  @arg    = PLC_GPIO_OFF | PLC_GPIO_ON
 */
bool PlcGpio_DO_Toggle(uint PinIn);

/** @brief  DO: Set state
 *  @param  PinIn - pin number
 *  @param  StateIn - state:
 *  @arg    = PLC_GPIO_OFF
 *  @arg    = PLC_GPIO_ON
 *  @return Current Pin-status:
 *  @arg    = PLC_GPIO_OFF | PLC_GPIO_ON
 */
bool PlcGpio_DO_Set(uint PinIn, bool StateIn);

/** @brief  DO: Get current state
 *  @param  PinIn - pin number
 *  @return Current state:
 *  @arg    = PLC_GPIO_OFF | PLC_GPIO_ON
 */
bool PlcGpio_DO_Get(uint PinIn);

/** @brief  DI: Get current state.
 *  @param  PinIn - pin number
 *  @return Current state:
 *  @arg    = PLC_GPIO_OFF | PLC_GPIO_ON
 */
bool PlcGpio_DI_Get(uint PinIn);

#endif /* HARDWARE_GPIO_H_ */
