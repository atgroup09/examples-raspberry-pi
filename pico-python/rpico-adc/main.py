# @page Main cycle
#       RPico 2020, micro-Python SDK
#       timer example
# @date 2024-09-25

from machine import Pin, Timer, ADC;
from registers import GPIO_PINS, ADC_DEVICE, ADC_FIFO_ADDR;


# GLOBAL VARIABLES

# Led
LED_USER_PIN = 25;
LED_USER_STATUS = GPIO_PINS[LED_USER_PIN].GPIO_STATUS;
LED_USER = None;

# Button
BT_USER_PIN = 5;
BT_USER = None;

# Internal Temperature Sensor
ADC_SENSOR_TEMP_CH = 4;
ADC_SENSOR_TEMP = None;

# Timer1
TIM1 = None;


# FUNCTIONS

# @func Scale the ADC-value of the Temperature sensor
# @param  AdcCode - ADC-value of the Temperature sensor.
# @return Value [float, 32bit; degree C]
def ADC_SENSOR_TEMP_scale(AdcCode):
    # ADC scale factor
    Value = AdcCode*(3.3/4095);
    # Typically, Vbe = 0.706V at 27 degrees C, with a slope of -1.721mV (0.001721) per degree
    Value = 27-((Value-0.706)/0.001721);
    return (Value);
    
# @func Read the ADC-value of the Temperature sensor
# @param  None.
# @return Value [uint16, 16bit; ADC-code]
def ADC_SENSOR_TEMP_read():
    global ADC_SENSOR_TEMP;
    # read ADC (16bit code)
    AdcCode = ADC_SENSOR_TEMP.read_u16();
    return (AdcCode);
    
# @func Toggle state of LED_USER
# @param  None.
# @return None.
def LED_USER_toggle():
    global LED_USER;
    LED_USER.toggle();
    

# CORE0 PROCESSES

# TIM1.tick handler-function
def TIM1_tick(timer):
    global LED_USER_STATUS;
    global ADC_DEVICE;
    print("CORE-0 TIM1_tick");
    
    LED_USER_toggle();
    print("- GPIO25.STATUS: {0}".format(LED_USER_STATUS.OUTTOPAD));
    
    if (ADC_DEVICE.CS.READY):
        AdcCode = ADC_DEVICE.RESULT_REG;
        Value   = ADC_SENSOR_TEMP_scale(AdcCode);
        print("- ADC: {0} {1}".format(AdcCode, Value));
        #ADC_DEVICE.CS.START_ONCE = 1;
    #AdcCode = ADC_SENSOR_TEMP_read();
    #Value   = ADC_SENSOR_TEMP_scale(AdcCode);

# BT_USER handler-function
def BT_USER_callback(Pin):
    print("CORE-0 BT_USER_callback");


# Init. Periphery

# LED_USER
LED_USER = Pin(LED_USER_PIN, Pin.OUT);

# BUTTON
BT_USER = Pin(BT_USER_PIN, Pin.IN, Pin.PULL_UP);
BT_USER.irq(trigger=Pin.IRQ_FALLING, handler=BT_USER_callback);

# SENSOR_TEMP
#ADC_SENSOR_TEMP = ADC(4);
ADC_DEVICE.CS_REG    = ADC_DEVICE.FCS_REG = 0;
ADC_DEVICE.CS.AINSEL = ADC_SENSOR_TEMP_CH;
ADC_DEVICE.CS.EN     = 1;
ADC_DEVICE.CS.TS_EN  = 1;
# enable circular mode
ADC_DEVICE.DIV_REG       = int((48000000/10000)-1) << 8;
ADC_DEVICE.FCS.EN        = 1;
ADC_DEVICE.CS.START_MANY = 1;

# TIM1
TIM1 = Timer();
TIM1.init(mode=Timer.PERIODIC, freq=1.0, callback=TIM1_tick);
