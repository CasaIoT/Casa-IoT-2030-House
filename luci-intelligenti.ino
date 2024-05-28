#include "thingProperties.h"
#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;
 
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
  carrier.display.setRotation(0); }
 
void loop() {
  ArduinoCloud.update();
  // Your code here
  uint8_t r, g, b;
  control_RGB.getValue().getRGB(r, g, b);
 
  if (circle_RGB == true) {
    for (int ring = 0; ring <= 4; ring++) {
      carrier.leds.setPixelColor(ring, r, g, b);
      carrier.leds.show();
      delay(100);
      carrier.leds.clear();
    } } 
  else {
    lightsOff(); }
 
  if (blink_RGB == true) {
    lightsOn();
    delay(blink_speed);
    lightsOff();
    delay(blink_speed); }
 
  if (switch_RGB == true) {
    lightsOn(); } 
  else {
    lightsOff(); }
 
  if (relay_1 == true) {
    carrier.Relay1.open(); } 
  else {
    carrier.Relay1.close(); }
 
  if (relay_2 == true) {
    carrier.Relay2.open(); } 
  else {
    carrier.Relay2.close(); }
  delay(100); }
 
void lightsOn() {
  uint8_t r, g, b;
  control_RGB.getValue().getRGB(r, g, b);
  carrier.leds.setPixelColor(0, r, g, b);
  carrier.leds.setPixelColor(1, r, g, b);
  carrier.leds.setPixelColor(2, r, g, b);
  carrier.leds.setPixelColor(3, r, g, b);
  carrier.leds.setPixelColor(4, r, g, b);
  carrier.leds.show(); }

void lightsOff() {
  carrier.leds.setPixelColor(0, 0, 0, 0);
  carrier.leds.setPixelColor(1, 0, 0, 0);
  carrier.leds.setPixelColor(2, 0, 0, 0);
  carrier.leds.setPixelColor(3, 0, 0, 0);
  carrier.leds.setPixelColor(4, 0, 0, 0);
  carrier.leds.show(); }

void onControlRGBChange() { }
void onBlinkRGBChange() { }
void onCircleRGBChange() { }
void onSwitchRGBChange() { }
void onRelay1Change() { }
void onRelay2Change() { }
void onBlinkSpeedChange() { }

