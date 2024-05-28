#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char SSID[]     = SECRET_SSID;    // Network SSID 
const char PASS[]     = SECRET_OPTIONAL_PASS;    // Network password 

String weather_report;
float humidity;
float pressure;
float temperature;
int light;

void initProperties(){

  ArduinoCloud.addProperty(weather_report, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(humidity, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(pressure, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(temperature, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(light, READ, 1 * SECONDS, NULL); }

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);

