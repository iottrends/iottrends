from pyLoraRFM9x import LoRa, ModemConfig

def on_recv(payload):
    print("From:", payload.header_from)
    print("Received:", payload.message)
    print("RSSI: {}; SNR: {}".format(payload.rssi, payload.snr))

lora = LoRa(1, 22, 2, reset_pin = 31, 
modem_config=ModemConfig.Bw125Cr45Sf128, tx_power=21, acks=True)
lora.on_recv = on_recv

message = "Hello there!"
status = lora.send_to_wait(message, 10, retries=2)
if status is True:
    print("Message sent!")
else:
    print("No acknowledgment from recipient")

    
