# @page Main cycle
#       RPico 2020, micro-Python SDK
#       thread / multi-core example
# @date 2023.10.24

from machine import Pin;
import _thread, time;


# GLOBAL VARIABLES

# Counter
CNT = 0;

# Led
LED_USER = None;

# A shared resource may be used by multiple tasks.
# Simultaneous access of several tasks to the same resource may cause an error.
# Semaphores/ or Mutexex are used to exclude such errors.

# Semaphore for shared resource:
# - counter and print()
SEMA_RES1 = None;


# CORE1 PROCESSES

# Task of Core1
# call debug-print
def taskCore1():
    
    while True:
    
        # test and lock the semaphore
        # if the semaphore is locked by another process, then the task is blocked until the semaphore is released
        SEMA_RES1.acquire();
        
        print("CORE-1 CNT={0}".format(CNT));
        
        # unlock the semaphore
        SEMA_RES1.release();


# CORE0 Procersses

# Init. Periphery
LED_USER = Pin(25, Pin.OUT)

# Init. Sepharores
SEMA_RES1 = _thread.allocate_lock();

# Init. Core1
_thread.start_new_thread(taskCore1, ());

# Main cycle
while True:
    
    # test and lock the semaphore
    # if the semaphore is locked by another process, then the task is blocked until the semaphore is released
    SEMA_RES1.acquire();
    
    print("CORE-0");
    CNT = CNT+1;
    
    # LED blink
    LED_USER.value(1);
    time.sleep(1);
    LED_USER.value(0);
    time.sleep(1);
    
    # unlock the semaphore
    SEMA_RES1.release();
