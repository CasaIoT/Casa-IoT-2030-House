#include <SoftwareSerial.h>
SoftwareSerial SSerial(6, 7);  

void setup() {
  SSerial.begin(9600);
  pinMode(13, HIGH);
}

void loop() {
    if (SSerial.available()) {
    char ch = SSerial.read();
    Serial.println(ch);
    if (ch == 'a') {
      digitalWrite(13, HIGH);
    }
    if (ch == 's') {
      digitalWrite(13, LOW);
    } 
  }
}
