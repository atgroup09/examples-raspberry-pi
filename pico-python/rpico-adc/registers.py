# @page Registers
#       RPico 2020, micro-Python SDK
# @date 2024-09-25

from uctypes import BF_POS, BF_LEN, UINT32, BFUINT32, struct;


# GPIO

# start address
GPIO_BASE = 0x40014000;

# a channel page size
GPIO_CHAN_WIDTH = 0x08;

# the number of channels
GPIO_PIN_COUNT  = 30;

# fields of status register
GPIO_STATUS_FIELDS = {
    "IRQTOPROC":  26<<BF_POS | 1<<BF_LEN | BFUINT32,
    "IRQFROMPAD": 24<<BF_POS | 1<<BF_LEN | BFUINT32,
    "INTOPERI":   19<<BF_POS | 1<<BF_LEN | BFUINT32,
    "INFROMPAD":  17<<BF_POS | 1<<BF_LEN | BFUINT32,
    "OETOPAD":    13<<BF_POS | 1<<BF_LEN | BFUINT32,
    "OEFROMPERI": 12<<BF_POS | 1<<BF_LEN | BFUINT32,
    "OUTTOPAD":    9<<BF_POS | 1<<BF_LEN | BFUINT32,
    "OUTFROMPERI": 8<<BF_POS | 1<<BF_LEN | BFUINT32
};

# fields of control registers
GPIO_CTRL_FIELDS = {
    "IRQOVER": 28<<BF_POS | 2<<BF_LEN | BFUINT32,
    "INOVER":  16<<BF_POS | 2<<BF_LEN | BFUINT32,
    "OEOVER":  12<<BF_POS | 2<<BF_LEN | BFUINT32,
    "OUTOVER":  8<<BF_POS | 2<<BF_LEN | BFUINT32,
    "FUNCSEL":  0<<BF_POS | 5<<BF_LEN | BFUINT32
};

# registers
GPIO_REGS = {
    "GPIO_STATUS_REG":  0x00 | UINT32,
    "GPIO_STATUS":     (0x00, GPIO_STATUS_FIELDS),
    "GPIO_CTRL_REG":    0x04 | UINT32,
    "GPIO_CTRL":       (0x04, GPIO_CTRL_FIELDS)
};

GPIO_PINS = [struct(GPIO_BASE + n*GPIO_CHAN_WIDTH, GPIO_REGS) for n in range(0,GPIO_PIN_COUNT)];


# ADC

# start address
ADC_BASE = 0x4004c000;

# fields of control and status registers
ADC_CS_FIELDS = {
    "RROBIN":     16<<BF_POS | 5<<BF_LEN | BFUINT32,
    "AINSEL":     12<<BF_POS | 3<<BF_LEN | BFUINT32,
    "ERR_STICKY": 10<<BF_POS | 1<<BF_LEN | BFUINT32,
    "ERR":         9<<BF_POS | 1<<BF_LEN | BFUINT32,
    "READY":       8<<BF_POS | 1<<BF_LEN | BFUINT32,
    "START_MANY":  3<<BF_POS | 1<<BF_LEN | BFUINT32,
    "START_ONCE":  2<<BF_POS | 1<<BF_LEN | BFUINT32,
    "TS_EN":       1<<BF_POS | 1<<BF_LEN | BFUINT32,
    "EN":          0<<BF_POS | 1<<BF_LEN | BFUINT32
};

# fields of FIFO control and status registers
ADC_FCS_FIELDS = {
    "THRESH":     24<<BF_POS | 4<<BF_LEN | BFUINT32,
    "LEVEL":      16<<BF_POS | 4<<BF_LEN | BFUINT32,
    "OVER":       11<<BF_POS | 1<<BF_LEN | BFUINT32,
    "UNDER":      10<<BF_POS | 1<<BF_LEN | BFUINT32,
    "FULL":        9<<BF_POS | 1<<BF_LEN | BFUINT32,
    "EMPTY":       8<<BF_POS | 1<<BF_LEN | BFUINT32,
    "DREQ_EN":     3<<BF_POS | 1<<BF_LEN | BFUINT32,
    "ERR":         2<<BF_POS | 1<<BF_LEN | BFUINT32,
    "SHIFT":       1<<BF_POS | 1<<BF_LEN | BFUINT32,
    "EN":          0<<BF_POS | 1<<BF_LEN | BFUINT32,
};

# registers
ADC_REGS = {
    "CS_REG":              0x00|UINT32,
    "CS":                 (0x00,ADC_CS_FIELDS),
    "RESULT_REG":          0x04|UINT32,
    "FCS_REG":             0x08|UINT32,
    "FCS":                (0x08,ADC_FCS_FIELDS),
    "FIFO_REG":            0x0c|UINT32,
    "DIV_REG":             0x10|UINT32,
    "INTR_REG":            0x14|UINT32,
    "INTE_REG":            0x18|UINT32,
    "INTF_REG":            0x1c|UINT32,
    "INTS_REG":            0x20|UINT32
};

ADC_DEVICE    = struct(ADC_BASE, ADC_REGS);
ADC_FIFO_ADDR = ADC_BASE + 0x0c;


# DMA

# start address
DMA_BASE = 0x50000000;

# a channel page size
DMA_CHAN_WIDTH = 0x40;

# the number of channers
DMA_CHAN_COUNT = 12;

# fields of control and status registers
DMA_CTRL_TRIG_FIELDS = {
    "AHB_ERROR":   31<<BF_POS | 1<<BF_LEN | BFUINT32,
    "READ_ERROR":  30<<BF_POS | 1<<BF_LEN | BFUINT32,
    "WRITE_ERROR": 29<<BF_POS | 1<<BF_LEN | BFUINT32,
    "BUSY":        24<<BF_POS | 1<<BF_LEN | BFUINT32,
    "SNIFF_EN":    23<<BF_POS | 1<<BF_LEN | BFUINT32,
    "BSWAP":       22<<BF_POS | 1<<BF_LEN | BFUINT32,
    "IRQ_QUIET":   21<<BF_POS | 1<<BF_LEN | BFUINT32,
    "TREQ_SEL":    15<<BF_POS | 6<<BF_LEN | BFUINT32,
    "CHAIN_TO":    11<<BF_POS | 4<<BF_LEN | BFUINT32,
    "RING_SEL":    10<<BF_POS | 1<<BF_LEN | BFUINT32,
    "RING_SIZE":    6<<BF_POS | 4<<BF_LEN | BFUINT32,
    "INCR_WRITE":   5<<BF_POS | 1<<BF_LEN | BFUINT32,
    "INCR_READ":    4<<BF_POS | 1<<BF_LEN | BFUINT32,
    "DATA_SIZE":    2<<BF_POS | 2<<BF_LEN | BFUINT32,
    "HIGH_PRIORITY":1<<BF_POS | 1<<BF_LEN | BFUINT32,
    "EN":           0<<BF_POS | 1<<BF_LEN | BFUINT32
};

# fields of channel-specific registers
DMA_CHAN_REGS = {
    "READ_ADDR_REG":       0x00|UINT32,
    "WRITE_ADDR_REG":      0x04|UINT32,
    "TRANS_COUNT_REG":     0x08|UINT32,
    "CTRL_TRIG_REG":       0x0c|UINT32,
    "CTRL_TRIG":          (0x0c,DMA_CTRL_TRIG_FIELDS)
};

# fields of general registers
DMA_REGS = {
    "INTR":               0x400|UINT32,
    "INTE0":              0x404|UINT32,
    "INTF0":              0x408|UINT32,
    "INTS0":              0x40c|UINT32,
    "INTE1":              0x414|UINT32,
    "INTF1":              0x418|UINT32,
    "INTS1":              0x41c|UINT32,
    "TIMER0":             0x420|UINT32,
    "TIMER1":             0x424|UINT32,
    "TIMER2":             0x428|UINT32,
    "TIMER3":             0x42c|UINT32,
    "MULTI_CHAN_TRIGGER": 0x430|UINT32,
    "SNIFF_CTRL":         0x434|UINT32,
    "SNIFF_DATA":         0x438|UINT32,
    "FIFO_LEVELS":        0x440|UINT32,
    "CHAN_ABORT":         0x444|UINT32
};

DMA_CHANS = [struct(DMA_BASE + n*DMA_CHAN_WIDTH, DMA_CHAN_REGS) for n in range(0,DMA_CHAN_COUNT)];
DMA_DEVICE = struct(DMA_BASE, DMA_REGS);
