import time
import RPI.GPIO as GPIO
channel= 14
GPIO.setmode (GPIO.BCM)
GPIO.setup (channel, GPIO.IN)
def callback (channel) :
if GPIO.input(channel):
print(“no water detected")
else:
print("water detected")
GPIO.add_event_detect(channel)GPIO.BOTH, bounce time-300)
GPIO.add_event_callback(channel,callback)
while True:
time.sleep (1)
