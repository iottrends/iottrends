import RPi.GPIO as GPIO
import board

from time import sleep
from bme680 import *
i2c = I2C(scl=Pin(9), sda=Pin(8))
bme = BME680_I2C(i2c=i2c)

while True:
  try:
    temp = str(round(bme.temperature, 2)) + ' C'
    #temp = (bme.temperature) * (9/5) + 32
    #temp = str(round(temp, 2)) + 'F'
    
    hum = str(round(bme.humidity, 2)) + ' %'   
    pres = str(round(bme.pressure, 2)) + ' hPa'    
    gas = str(round(bme.gas/1000, 2)) + ' KOhms'

    print('Temperature:', temp)
    print('Humidity:', hum)
    print('Pressure:', pres)
    print('Gas:', gas)
    print('-------')
  except OSError as e:
    print('Failed to read sensor.')
   sleep(5)
