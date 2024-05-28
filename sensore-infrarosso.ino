int LED = 3; 
int isObstaclePin = 2;  
int isObstacle = HIGH;  

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(isObstaclePin, INPUT);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); 
  //delay(500);
  }

void loop(){
  //Blynk.run();
  isObstacle = digitalRead(isObstaclePin);
  if (isObstacle == LOW)
  {
    digitalWrite(LED, HIGH);
    delay(500);
  }
  else {
    digitalWrite(LED, LOW);
  }
}
