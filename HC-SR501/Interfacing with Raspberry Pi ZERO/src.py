import RPi.GPIO as GPIO                          
import time                                
GPIO.setmode(GPIO.BOARD)                          
pir = 26                                          
GPIO.setup(pir, GPIO.IN)                        
print "Waiting for sensor to settle"
time.sleep(2)
print "Detecting motion"
while True:
   if GPIO.input(pir):                          
      print "Motion Detected!"
      time.sleep(2)
   else:
   	print”No motion detected”
time.sleep(1)                           
  time.sleep(0.1)
