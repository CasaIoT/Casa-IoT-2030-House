#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
const char SSID[]     = SECRET_SSID;    // Network SSID
const char PASS[]     = SECRET_OPTIONAL_PASS;    // Network password 

void onMessageUpdateChange();
void onLightAlarmChange();
void onLightEventChange();
void onMovementAlarmChange();
void onMovementEventChange();
void onShakeAlarmChange();
void onShakeEventChange();

String message_update;
bool light_alarm;
bool light_event;
bool movement_alarm;
bool movement_event;
bool shake_alarm;
bool shake_event;

void initProperties(){
  ArduinoCloud.addProperty(message_update, READWRITE, ON_CHANGE, onMessageUpdateChange);
  ArduinoCloud.addProperty(light_alarm, READWRITE, ON_CHANGE, onLightAlarmChange);
  ArduinoCloud.addProperty(light_event, READWRITE, ON_CHANGE, onLightEventChange);
  ArduinoCloud.addProperty(movement_alarm, READWRITE, ON_CHANGE, onMovementAlarmChange);
  ArduinoCloud.addProperty(movement_event, READWRITE, ON_CHANGE, onMovementEventChange);
  ArduinoCloud.addProperty(shake_alarm, READWRITE, ON_CHANGE, onShakeAlarmChange);
  ArduinoCloud.addProperty(shake_event, READWRITE, ON_CHANGE, onShakeEventChange); }

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);

