#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
boolean button_state = 0;
int led_pin = 3;
void setup() {
pinMode(6, OUTPUT);
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, address);   
radio.setPALevel(RF24_PA_MIN);       
radio.startListening();              
}
void loop()
{
if (radio.available())              
{
char text[32] = "";                
radio.read(&text, sizeof(text));    
radio.read(&button_state, sizeof(button_state));    
if(button_state == HIGH)
{
digitalWrite(6, HIGH);
Serial.println(text);
}
else
{
digitalWrite(6, LOW);
Serial.println(text);
}
}
delay(5);
}
