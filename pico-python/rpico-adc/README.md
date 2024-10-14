# examples-raspberry-pi

## Raspberry Pi Pico

![rpico module](../000-images/rpico-2020.png)

### Hardware Platform

- RPi Pico 2020
  - ARM Cortex-M0+ 32-bit RISC, Dual-Core
  - System Clock 133 MHz
  - FLASH 2 MB
  - SRAM 264 kB
  - GPIO 26x
  - ADC 1x 12-bit 4-channels
  - DMA
  - Timer 1x
  - RTC 1x
  - UART 2x
  - SPI 2x
  - I2C 2x
  - USB 1.1 Device/Host 1x
  - SWD 1x
  - Temperature sensor 1x (built-in, analog, connected to ADC.Ch4)

### Software Platform

- Embedded SDK (firmware)
  - micro-Python (rp2-pico-20230426-v1.20.0.uf2)
- IDE
  - Thonny 3.3.13
- Language
  - Python 3
- Frameworks, External libraries
  - umodbus


## rpico-adc

Example: ADC

### CORE-0

**Init. Periphery**
- LED
- ADC_TEMP
  - internal temperature sensor (ADC.CHANNEL4)
- TIM1
  - periodic mode
  - freq. 1 sec

**Main task**
(none)

**TIM1.tick**
(handler-function)
- LED toggle
- read and scale value of ADC.CHANNEL4
- print the core ID and value of ADC.CHANNEL4
