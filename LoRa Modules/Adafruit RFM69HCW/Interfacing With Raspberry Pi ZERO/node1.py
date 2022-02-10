import time
import board
import busio
import digitalio
import adafruit_rfm9x


transmit_interval = 10


RADIO_FREQ_MHZ = 915.0  # Frequency of the radio in Mhz. Must match your
# module! Can be a value like 915.0, 433.0, etc.

CS = digitalio.DigitalInOut(board.10)
RESET = digitalio.DigitalInOut(board.11)

spi = busio.SPI(board.SCK, MOSI=board.MOSI, MISO=board.MISO)
rfm9x = adafruit_rfm9x.RFM9x(spi, CS, RESET, RADIO_FREQ_MHZ)

rfm9x.enable_crc = True
rfm9x.node = 1
rfm9x.destination = 2
counter = 0
rfm9x.send(
    bytes("Startup message {} from node {}".format(counter, rfm9x.node), "UTF-8")
)

print("Waiting for packets...")
now = time.monotonic()
while True:
    packet = rfm9x.receive(with_header=True)
    if packet is not None:
        print("Received (raw header):", [hex(x) for x in packet[0:4]])
        print("Received (raw payload): {0}".format(packet[4:]))
        print("Received RSSI: {0}".format(rfm9x.last_rssi))
    if time.monotonic() - now > transmit_interval:
        now = time.monotonic()
        counter = counter + 1
        rfm9x.send(
            bytes(
                "message number {} from node {}".format(counter, rfm9x.node), "UTF-8"
            ),
            keep_listening=True,
        )
