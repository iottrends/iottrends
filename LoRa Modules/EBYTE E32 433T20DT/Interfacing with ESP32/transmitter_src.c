#include "EBYTE.h"

#define PIN_RX 16   
#define PIN_TX 17   

#define PIN_M0 4    
#define PIN_M1 22   
#define PIN_AX 21 


struct DATA {
  unsigned long Count;
  int Bits;
  float Volts;
  float Amps;

};

int Chan;
DATA MyData;
unsigned long Last;

EBYTE Transceiver(&Serial2, PIN_M0, PIN_M1, PIN_AX);

void setup() {


  Serial.begin(9600);

  Serial2.begin(9600);

  Serial.println("Starting Reader");

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

