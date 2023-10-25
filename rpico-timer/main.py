# @page Main cycle
#       RPico 2020, micro-Python SDK
#       timer example
# @date 2023-08-08

from machine import Pin, Timer;


# GLOBAL VARIABLES

# Counter
CNT = 0;

# Led
LED_USER = None;

# Timer1
TIM1 = None;


# CORE0 PROCESSES

# TIM1.tick handler-function
def TIM1_tick(timer):
    global CNT;
    global LED_USER;
    CNT = CNT+1;
    LED_USER.toggle();
    print("CORE-0 TIM1_tick CNT={0}".format(CNT));

# Init. Periphery
LED_USER = Pin(25, Pin.OUT);
TIM1 = Timer();
TIM1.init(mode=Timer.PERIODIC, freq=1.0, callback=TIM1_tick);
