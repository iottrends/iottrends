#include <SoftwareSerial.h>
#include "EBYTE.h"


#define PIN_RX 14   
#define PIN_TX 12  

#define PIN_M0 5   
#define PIN_M1 4    
#define PIN_AX 16   

struct DATA {
  unsigned long Count;
  int Bits;
  float Volts;
  float Amps;

};

int Chan;
DATA MyData;
int i;

SoftwareSerial ESerial(PIN_RX, PIN_TX);

EBYTE Transceiver(&ESerial, PIN_M0, PIN_M1, PIN_AX);

void setup() {

  Serial.begin(9600);

  ESerial.begin(9600);
  
  Serial.println("Starting Sender");

  Serial.println(Transceiver.init());

  Transceiver.PrintParameters();

}

void loop() {

  MyData.Count++;
  MyData.Bits = analogRead(A0);
  MyData.Volts = MyData.Bits * ( 5.0 / 1024.0 );

  Transceiver.SendStruct(&MyData, sizeof(MyData));

  Serial.print("Sending: "); Serial.println(MyData.Count);
  delay(1000);


}
