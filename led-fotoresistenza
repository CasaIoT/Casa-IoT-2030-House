#include <SoftwareSerial.h>
int led = 8;
int analogInPin = A0;
int sensorValue = 0;

void setup() {
  pinMode (analogInPin, INPUT);
  pinMode (led, OUTPUT);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  if (sensorValue > 300){
    digitalWrite (led, HIGH);}
  else{ 
    digitalWrite (led, LOW);}
}
