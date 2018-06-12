#include <ESP8266WiFi.h>
#include "ChangeMac.hpp"
#include "heltecLCD.h"
const char* ssid     = " ";
const char* password = "8044578669";
#define LCD
unsigned int counter=0;
void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.println();
#ifdef LCD
  heltecLCDsetup();
  heltecDrawBC();
  delay(500);
  heltecDrawGhost();
  delay(3000);
  
  
  heltecLCDClear();
#endif
  uint8_t mac[6];
  while (true) {
    counter++;
  makeRandomMac(mac);
  changeMac(mac);
  if (counter > 500){

    String stringCOne =  String("Counter:[ ");                
    String stringCTwo =  String(stringCOne + String(counter));
    String stringCThree =  String(stringCTwo + " ]");
    heltecDisplayMsg(stringCThree,0,1,true);
    
    String stringMOne =  String("MAC:[ "); 

    for (int i = 0; i < 6; i++)  {
      stringMOne =  String(stringMOne + String(mac[i],HEX));  
      if (i < 5) {
        stringMOne =  String(stringMOne + String(":"));
      }
    }
    String stringMThree =  String(stringMOne + " ]");
    heltecDisplayMsg(stringMThree,0,2,false);
    delay(5000);
    heltecLCDClear();
    counter=0;
  }
  Serial.print("MAC address is ");
  Serial.println(WiFi.macAddress());
  WiFi.hostname("MACGhoster");
  WiFi.begin(ssid, password);
  delay(50);
  }
}

void loop() {
}
