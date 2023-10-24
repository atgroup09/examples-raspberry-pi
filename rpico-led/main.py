# @page Main cycle
#       RPico 2020, micro-Python SDK
#       led-blink example
# @date 2023.08.09

from machine import Pin
import time


# CORE0 PROCESSES
 
# Init. Periphery
led = Pin(25, Pin.OUT)

# Main cycle
while True:
    led.value(1)
    time.sleep(1)
    led.value(0)
    time.sleep(1)
