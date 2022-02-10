#include <SPI.h>              
#include <LoRa.h>

const long frequency = 915E6;  

const int csPin = 5;          
const int resetPin = 17;        
const int irqPin = 18;         

void setup() {
  Serial.begin(9600);                   
  while (!Serial);

  LoRa.setPins(csPin, resetPin, irqPin);

  if (!LoRa.begin(frequency)) {
    Serial.println("LoRa init failed. Check your connections.");
    while (true);                       
  }

  Serial.println("LoRa init succeeded.");
  Serial.println();
  Serial.println("LoRa Simple Node");
  Serial.println("Only receive messages from gateways");
  Serial.println("Tx: invertIQ disable");
  Serial.println("Rx: invertIQ enable");
  Serial.println();

  LoRa.onReceive(onReceive);
  LoRa.onTxDone(onTxDone);
  LoRa_rxMode();
}

void loop() {
  if (runEvery(1000)) { 

    String message = "HeLoRa World! ";
    message += "I'm a Node! ";
    message += millis();

    LoRa_sendMessage(message); 

    Serial.println("Send Message!");
  }
}

void LoRa_rxMode(){
  LoRa.enableInvertIQ();                
  LoRa.receive();                       
}

void LoRa_txMode(){
  LoRa.idle();                          
  LoRa.disableInvertIQ();               
}

void LoRa_sendMessage(String message) {
  LoRa_txMode();                        
  LoRa.beginPacket();                   
  LoRa.print(message);                  
  LoRa.endPacket(true);                
}

void onReceive(int packetSize) {
  String message = "";

  while (LoRa.available()) {
    message += (char)LoRa.read();
  }

  Serial.print("Node Receive: ");
  Serial.println(message);
}

void onTxDone() {
  Serial.println("TxDone");
  LoRa_rxMode();
}

boolean runEvery(unsigned long interval)
{
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    return true;
  }
  return false;
}
