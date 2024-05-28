#define BLYNK_TEMPLATE_ID "TMPL4YK8QZkoT"
#define BLYNK_TEMPLATE_NAME "2030 House"
#define BLYNK_AUTH_TOKEN "ttgJeIpYxyrXzFYxPLDb8Vj9NTPn9v64"
#define BLYNK_PRINT SerialUSB

#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>

char ssid[] = "SSID";
char pass[] = "password";

void setup(){
  SerialUSB.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); }

void loop(){
  Blynk.run(); 
}
