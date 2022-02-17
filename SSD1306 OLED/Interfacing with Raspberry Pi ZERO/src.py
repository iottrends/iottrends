import RPi.GPIO as GPIO
import board
from ssd1306 import SSD1306_I2C
i2c=I2C(0,sda=Pin(3), scl=Pin(5), freq=400000)
oled = SSD1306_I2C(128, 64, i2c)
oled.text("Hello World!", 0, 0)
oled.show()
