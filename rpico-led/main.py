# Библиотека для работы с пинами ввода-вывода
from machine import Pin
# Библиотека для работы с временем
import time
 
# Светодиод в режим выхода на 25 пине
led = Pin(25, Pin.OUT)
 
while True:
    # Зажигаем светодиод
    led.value(1)
    # Ждём 1 секунду
    time.sleep(1)
    # Гасим светодиод
    led.value(0)
    # Ждём 1 секунду
    time.sleep(1)

