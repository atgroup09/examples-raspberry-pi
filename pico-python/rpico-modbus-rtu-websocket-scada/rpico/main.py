# @page Main cycle
# @date 2023.08.09

from mod_modbus_slave import *;
from mod_temp_sensor import *;
from mod_timer1 import *;
from mod_led import *;
import global_var;


# Init. Periphery
setupModBusServer();
setupTimer1();
setupLed();


# Main cycle

while True:
    try:
        result = global_var.MODBUS_SRV.process();
    except KeyboardInterrupt:
        print('KeyboardInterrupt, stopping RTU client...');
        break
    except Exception as e:
        print('Exception during execution: {}'.format(e));

print("Finished providing/accepting data as client");
