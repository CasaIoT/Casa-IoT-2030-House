#include <SoftwareSerial.h>
#include <Servo.h>
Servo servo1;

Servo myservo;
int Button_Sx;
int Button_Dx;
int Posizione_Servo=0;

void setup() {
  servo1.attach(9);
  myservo.attach(3);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  myservo.write(Posizione_Servo);
}

void loop() {
  Button_Sx = digitalRead(4);
  Button_Dx = digitalRead(5);
  if(Button_Sx != Button_Dx){
    if(Button_Sx == HIGH){
      Posizione_Servo = --Posizione_Servo;
    }
    if(Button_Dx == HIGH){
      Posizione_Servo = ++Posizione_Servo;
    }
    myservo.write(Posizione_Servo);
    delay(10);
  }
}
