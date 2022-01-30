#include <Adafruit_GPS.h>
//We can now create our Software Serial object after including the library
SoftwareSerial mySerial(3, 2);

//And finally attach our Serial object pins to our GPS module
Adafruit_GPS GPS(&mySerial);

void setup() {
Serial.begin(115200); //This baud rate will help a lot in printing all of the data that comes from the GPS Module to the serial monitor
GPS.begin(9600); 
//These lines configure the GPS Module

GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); 
//Sets output to only RMC and GGA sentences

GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
 //Sets the output to 1/second. If you want you can go higher/lower
GPS.sendCommand(PGCMD_ANTENNA); //Can report if antenna is connected or not
}

void loop() {
//Now we will start our GPS module, parse (break into parts) the Last NMEA sentence 

GPS.parse(GPS.lastNMEA()); //This is going to parse the last NMEA sentence the Arduino has received, breaking it down into its constituent parts.

GPS.newNMEAreceived(); //This will return a boolean TRUE/FALSE depending on the case.
//Print the current date/time/etc.

    Serial.print("\nTime: ");
    Serial.print(GPS.hour, DEC); Serial.print(':');
    Serial.print(GPS.minute, DEC); Serial.print(':');
    Serial.print(GPS.seconds, DEC); Serial.print('.');
    Serial.println(GPS.milliseconds);
    Serial.print("Date: ");
    Serial.print(GPS.day, DEC); Serial.print('/');
    Serial.print(GPS.month, DEC); Serial.print("/20");
    Serial.println(GPS.year, DEC);
    Serial.print("Fix: "); Serial.print((int)GPS.fix);
    Serial.print(" quality: "); Serial.println((int)GPS.fixquality);

//If GPS module has a fix, line by line prints the GPS information
    if (GPS.fix) {
      Serial.print("Location: ");
      Serial.print(GPS.latitude, 4); Serial.print(GPS.lat);
      Serial.print(", ");
      Serial.print(GPS.longitude, 4); Serial.println(GPS.lon);
      Serial.print("Location (in degrees, works with Google Maps): ");
      Serial.print(GPS.latitudeDegrees, 4);
      Serial.print(", ");
      Serial.println(GPS.longitudeDegrees, 4);
      Serial.print("Speed (knots): "); Serial.println(GPS.speed);
      Serial.print("Angle: "); Serial.println(GPS.angle);
      Serial.print("Altitude: "); Serial.println(GPS.altitude);
      Serial.print("Satellites: "); Serial.println((int)GPS.satellites);
    }
}
