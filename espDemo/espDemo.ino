#include <ESP8266WiFi.h>
const char* ssid = "G iphone";
const char* password  = "justinsucks";


void setup() {
  // put your setup code here, to run once:

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
}
