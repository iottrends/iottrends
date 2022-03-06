import RPi.GPIO as GPIO
from time import sleep
import BME280
i2c = I2C(scl=Pin(9), sda=Pin(8), freq=10000)
while True:
  bme = BME280.BME280(i2c=i2c)
  temp = bme.temperature
  hum = bme.humidity
  pres = bme.pressure
  print('Temperature: ', temp)
  print('Humidity: ', hum)
  print('Pressure: ', pres)

  sleep(5)
