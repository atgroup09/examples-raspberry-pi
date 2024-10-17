# examples-raspberry-pi

## Raspberry Pi Pico

### Hardware Platform

- RPi Pico 2020
  - ARM Cortex-M0+ 32-bit RISC, Dual-Core
  - System Clock 133 MHz
  - FLASH 2 MB
  - SRAM 264 kB
  - GPIO 26x
  - ADC 1x 12-bit 4-channels
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
  - pico-sdk-c
- IDE
  - Eclipse / GCC-ARM-NONE-EABI
- Language
  - C
- RTOS
  - FreeRTOS-KernelV11.1.0 (SMP is supported)

## Example: rp2040-c-freertos-smp-affinity
LED + UART + RTC + FreeRTOS (Symmetric Multiprocessing - SMP, dualcore mode, with affinity-set)

Tasks:
- T_UART0
  - blocked (waiting for message in UART0.Queue)
  - read UART0.Queue and print received task-info
  - pinned to CORE.0
- T_LED
  - blocked (waiting for end of delay)
  - LED.toggle and send the task-info info UART0.Queue
  - pinned to CORE.1
- T_SMP_A
  - blocked (waiting for end of delay)
  - send the task-info info UART0.Queue
  - pinned to CORE.1
- T_SMP_B
  - blocked (waiting for end of delay)
  - send the task-info info UART0.Queue
  - pinned to CORE.1
- T_SMP_C
  - blocked (waiting for end of delay)
  - send the task-info info UART0.Queue
  - not pinned to any core, can run on either core (defines RTOS-scheduler)
- T_SMP_D
  - blocked (waiting for end of delay)
  - send the task-info info UART0.Queue
  - not pinned to any core, can run on either core (defines RTOS-scheduler)

Events:
- RTC.Alarm
  - send the task-info info Queue
  - not pinned to any core, can run on either core

Shared resources:
- RTC.datetime
  - thread-safe access via a mutex/semaphore

Each task send the info into UART0:
- current datetime from RTC
- its name
- the core (0, 1) that it is currently running on
- the core affinity mask (-1, 1, 2, 3)
