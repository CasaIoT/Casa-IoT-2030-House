#include "thingProperties.h"
#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;
 
int pir;
int pirState = 0;
int light = 0;
 
String light_alarm_state = "";
String movement_alarm_state = "";
String shake_alarm_state = "";
 
float Gx, Gy, Gz;
 
uint32_t redColor = carrier.leds.Color( 0, 255, 0);
uint32_t noColor = carrier.leds.Color( 0, 0, 0);

void setup() {
  Serial.begin(9600);
  delay(1500); 
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  while (ArduinoCloud.connected() != 1) {
    ArduinoCloud.update();
    delay(500); }
 
  delay(500);
  CARRIER_CASE = false;
  carrier.begin();
  pir = carrier.getBoardRevision() == 1 ? A6 : A0;
  carrier.display.setRotation(0);
  delay(1500);
  pinMode(pir, INPUT); }
 
void loop() {
  ArduinoCloud.update();
  pirState = digitalRead(pir);
 
  while (!carrier.Light.colorAvailable()) {
    delay(5); }
  int none; 
  carrier.Light.readColor(none, none, none, light);
  carrier.IMUmodule.readGyroscope(Gx, Gy, Gz);

  if (light_alarm == true) {
    if (light_event == true) {
      message_update = "Light alarm breached!";
      alarm(); } }
  
  if (movement_alarm == true) {
    if (pirState == HIGH) {
      movement_event = true; }
    if (movement_event == true) {
      message_update = "Movement alarm breached!";
      alarm(); } }
 
  if (shake_alarm == true) {
    if (Gy > 100 || Gy < -100) {
      shake_event = true; }
    if (shake_event == true) {
      message_update = "Shake alarm breached!";
      alarm(); } }
  delay(100); }
 
void alarm() {
  carrier.leds.fill(redColor, 0, 5);
  carrier.leds.show();
  carrier.Buzzer.sound(500);
  delay(500);
  carrier.leds.fill(noColor, 0, 5);
  carrier.leds.show();
  carrier.Buzzer.noSound();
  delay(500); }

void updateScreen() {
  carrier.display.fillScreen(ST77XX_BLACK);
  carrier.display.setTextColor(ST77XX_WHITE);
  carrier.display.setTextSize(2);
  carrier.display.setCursor(25, 60);
  carrier.display.print(light_alarm_state);
  carrier.display.setCursor(10, 100);
  carrier.display.print(movement_alarm_state);
  carrier.display.setCursor(30, 140);
  carrier.display.print(shake_alarm_state); }
 
void onLightAlarmChange() {
  if (light_alarm == true) {
    light_alarm_state = "LIGHT ALARM: ON"; } 
  else {
    light_alarm_state = "LIGHT ALARM: OFF"; }
 void onMovementAlarmChange() {
  if (movement_alarm == true) {
updateScreen(); }
void onShakeAlarmChange() {
  if (shake_alarm == true) {
    shake_alarm_state = "SHAKE ALARM: ON"; } 
  else {
    shake_alarm_state = "SHAKE ALARM: OFF"; }
  updateScreen(); }
     if (light > 200) {
      light_event = true; }
movement_alarm_state = "MOVEMENT ALARM: ON"; } 
  else {
    movement_alarm_state = "MOVEMENT ALARM: OFF"; }
  updateScreen(); }

void onMessageUpdateChange() { }
void onShakeEventChange() { }
void onMovementEventChange() { }
void onLightEventChange() { }


