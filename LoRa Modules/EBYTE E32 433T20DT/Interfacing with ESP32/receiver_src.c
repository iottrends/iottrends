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

  Transceiver.init();

  Transceiver.PrintParameters();


}

void loop() {


  if (Serial2.available()) {

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
