# @page RPico: ModBus RTU Slave Server
# @date 2023.08.09

# @note
#  UART0 115200 8 N 1
#  DevAddr = 10

from machine import Pin
from umodbus.serial import ModbusRTU;
from umodbus import version;
import os;
import global_var;


# @func Event Handler: value of a register has changed
# @param  reg_type - type of a register [string]:
# @arg    = "ISTS", "COILS", "IREGS", "HREGS"
# @param  address - address of a register [int]
# @param  val - value of a register [bool|int]
# @return None.
def changedRegister(reg_type, address, val):
    print("{0}[{1}]={2}".format(reg_type, address, val));
    
    if(reg_type=="COILS" and address==global_var.MODBUS_REG_ADDR_LED_CMD):
        # toggle LED
        global_var.LED.value(val[0]);
        # update value of ModBus register (Addr, Val)
        global_var.MODBUS_SRV.set_ist(global_var.MODBUS_REG_ADDR_LED_STATUS, val[0]);


# @def ModBus Device Address
MODBUS_DEV_ADDR  = 10;

# @def ModBus UART ID
MODBUS_UART_ID   = 0;
# @def ModBus UART GPx (TX, RX)
MODBUS_UART_GPIO = (Pin(0), Pin(1));
# @def ModBus UART Baudrate
MODBUS_UART_BAUD = 115200;


# @def ModBus Registers Map
# @note
#  ISTS  - Table: Input Status Registers (boolean; Access: for the Device - read/write, for external Clients - read only)
#  COILS - Table: Coils Registers        (boolean; Access: for the Device - read/write, for external Clients - read/write)
#  IREGS - Table: Input Registers        (numeric; Access: for the Device - read/write, for external Clients - read only)
#  HREGS - Table: Holding Registers      (numeric; Access: for the Device - read/write, for external Clients - read/write)
MODBUS_REGS = {
    "ISTS":
    {
        "LED_STATUS":
        {
            "register": global_var.MODBUS_REG_ADDR_LED_STATUS,
            "len": 1,
            "val": 0,
            "description": "RPico.LED status"
        }
    },
    "COILS":
    {
        "LED_CMD":
        {
            "register": global_var.MODBUS_REG_ADDR_LED_CMD,
            "len": 1,
            "val": 0,
            "description": "RPico.LED control command (0 - off, 1 - on)",
            "on_set_cb": changedRegister
        }
    },
    "IREGS":
    {
        "TEMP":
        {
            "register": global_var.MODBUS_REG_ADDR_TEMP,
            "len": 2,
            "val": [0, 0],
            "description": "RPico.InternalTemperatureSensor value (float, 32bit; byte/word order: 0-1 2-3)",
            "unit": "degrees C"
        }
    },
    "HREGS":
    {
        "USER_16BIT":
        {
            "register": global_var.MODBUS_REG_ADDR_USER_16BIT,
            "len": 1,
            "val": 0,
            "description": "User 16-bit (numeric) value",
            "on_set_cb": changedRegister
        }
    }
};


# @func Setup ModBus Server
# @param  None.
# @return None.
def setupModBusServer():
    # print system info
    OsInfo = os.uname();
    print("micropthon: {}".format(OsInfo));
    print("micropthon-modbus: {}".format(version.__version__));
    
    # init. interface and server
    global_var.MODBUS_SRV = ModbusRTU(uart_id=MODBUS_UART_ID,
                                      pins=MODBUS_UART_GPIO,
                                      baudrate=MODBUS_UART_BAUD,
                                      data_bits=8,
                                      parity=None,
                                      stop_bits=1,
                                      addr=MODBUS_DEV_ADDR
                                     );
    
    print("Using pins {} with UART ID {}".format(MODBUS_UART_GPIO, MODBUS_UART_ID));
    print("Setting up registers...");
    
    # setup registers
    global_var.MODBUS_SRV.setup_registers(registers=MODBUS_REGS);
    
    print("Register setup done");
    print("Serving as RTU client on address {} at {} baud".format(MODBUS_DEV_ADDR, MODBUS_UART_BAUD));
    
    # exec next code in Main-cycle
    # result = global_var.MODBUS_SRV.process();
