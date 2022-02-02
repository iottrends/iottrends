#include <Wire.h> 
#include <SparkFun_u-blox_GNSS_Arduino_Library.h> 
SFE_UBLOX_GNSS myGNSS;

void setup()
{
  Serial.begin(115200);
  Serial.println("SparkFun u-blox GPS");

  Wire.begin();

  if (myGNSS.begin() == false)
  {
    Serial.println(F("u-blox GNSS module not detected at default I2C address. Please check wiring. Freezing."));
    while (1);
  }

  myGNSS.setNMEAOutputPort(Serial);
}

void loop()
{
  myGNSS.checkUblox();
  delay(250); 
}
