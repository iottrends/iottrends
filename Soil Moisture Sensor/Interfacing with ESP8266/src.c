int moisturePin = A0;
int thresholdValue = 800;

void setup(){
  pinMode(rainPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(moisturePin);
  Serial.print(sensorValue);
  if(sensorValue < thresholdValue){
    Serial.println(" - Doesn't need watering");
  }
  else {
    Serial.println(" - Time to water your plant");
  }
  delay(500);
}
