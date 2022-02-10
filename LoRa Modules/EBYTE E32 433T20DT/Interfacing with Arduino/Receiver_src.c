#include <SoftwareSerial.h>
#include "EBYTE.h"

#define PIN_RX 2
#define PIN_TX 3
#define PIN_M0 4
#define PIN_M1 5
#define PIN_AX 6


struct DATA {
  unsigned long Count;
  int Bits;
  float Volts;
  float Amps;

};

int Chan;
DATA MyData;
unsigned long Last;


SoftwareSerial ESerial(PIN_RX, PIN_TX);

EBYTE Transceiver(&ESerial, PIN_M0, PIN_M1, PIN_AX);

void setup() {


  Serial.begin(9600);

  ESerial.begin(9600);
  Serial.println("Starting Reader");


  Transceiver.PrintParameters();


}

void loop() {


  if (ESerial.available()) {

    Transceiver.GetStruct(&MyData, sizeof(MyData));
  
    Serial.print("Count: "); Serial.println(MyData.Count);
    Serial.print("Bits: "); Serial.println(MyData.Bits);
    Serial.print("Volts: "); Serial.println(MyData.Volts);
    Last = millis();

  }
  else {
    if ((millis() - Last) > 1000) {
      Serial.println("Searching: ");
      Last = millis();
    }

  }
} 
