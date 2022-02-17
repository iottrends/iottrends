#include <SD.h>
 
File myFile;
 
void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
 
   pinMode(10, OUTPUT);
 
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
 
  
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");
 
  
    while (myFile.available()) {
    	Serial.write(myFile.read());
    }
  
    myFile.close();
  } else {
  	    Serial.println("error opening test.txt");
  }
}
 
void loop()
{

}
