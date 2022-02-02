import time
import board
import busio
import machine
from ublox_gps import UbloxGps
sda=machine.Pin(1)
scl=machine.Pin(2)
i2c = machine.I2C(0,sda=sda, scl=scl, freq=400000)
gps = UbloxGps(i2c, debug=False)
def run():

    try:
        print("Listening for UBX Messages")
        while True:
            try:
                geo = gps.geo_coords()
                print("Longitude: ", geo.lon) 
                print("Latitude: ", geo.lat)
                print("Heading of Motion: ", geo.headMot)
            except (ValueError, IOError) as err:
                print(err)

    finally:
        port.close()


if __name__ == '__main__':
    run()
