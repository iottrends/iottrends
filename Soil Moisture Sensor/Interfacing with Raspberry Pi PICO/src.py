import machine
import time
thresholdValue=800
adc=machine.ADC(34)
Sensorvalue = adc.read()
if SensorValue < thresholdValue:
	print(‘No need to water’)
else:
print(‘water the plants’)
time.sleep(10)
