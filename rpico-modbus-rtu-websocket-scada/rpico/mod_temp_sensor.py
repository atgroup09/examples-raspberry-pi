# @page RPico: Internal Temperature Sensor
# @date 2023.08.09

# @note
#  The temperature sensor is connected to ADC(4).
#  The temperature sensor measures the Vbe voltage of a biased bipolar diode, connected to the fifth ADC channel.
#  Typically, Vbe = 0.706V at 27 degrees C, with a slope of -1.721mV (0.001721) per degree.

from machine import ADC;


# Sensor periphery
TEMP_SENSOR_ADC = ADC(4);

# Sensor scale factor (ADC-code > Voltage)
TEMP_SENSOR_SCALE_FACTOR = (3.3/65535.0);


# @func Read value of the Temperature sensor
# @param  None.
# @return Value [float, 32bit; degree C]
def readTempSensor():
    global TEMP_SENSOR_ADC;
    global TEMP_SENSOR_SCALE_FACTOR;
    
    # read ADC (16bit code)
    AdcCode = TEMP_SENSOR_ADC.read_u16();
    
    # scale ADC-code
    return (27.0-(((AdcCode*TEMP_SENSOR_SCALE_FACTOR)-0.706)/0.001721));
