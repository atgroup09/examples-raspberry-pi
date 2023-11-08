# @page RPico: Timer1
# @date 2023.08.09

# @note
#  Mode = PERIODIC
#  Freq = 1sec

from lib.float import *;
from machine import Timer;
from mod_temp_sensor import readTempSensor;
import global_var;


# Timer periphery
TIM_1 = Timer();


# @func Event Handler: timer counter has expired
# @param  TimIn - timer.
# @return None.
def tickTimer1(TimIn):
    # read value of Temperature sensor
    Temp  = readTempSensor();
    WoLst = floatToWords(Temp, FLOAT_ORDER_LE, FLOAT_ORDER_LE);
    
    # print("{0}".format(Temp));
    
    # update value of ModBus register (Addr, Val)
    # byte/word order: 0-1 2-3 (LO-word first, LO-byte of word first)
    global_var.MODBUS_SRV.set_ireg(global_var.MODBUS_REG_ADDR_TEMP, WoLst);


# @func Setup Timer1
# @param  None.
# @return None.
def setupTimer1():
    global TIM_1;
    TIM_1.init(mode=Timer.PERIODIC, freq=1.0, callback=tickTimer1);
