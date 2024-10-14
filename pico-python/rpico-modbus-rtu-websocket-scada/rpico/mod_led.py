# @page RPico: LED
# @date 2023.08.09

from machine import Pin;
import global_var;


# @func Setup LED
# @param  None.
# @return None.
def setupLed():
    global_var.LED = Pin(25, Pin.OUT);
    global_var.LED.off();
