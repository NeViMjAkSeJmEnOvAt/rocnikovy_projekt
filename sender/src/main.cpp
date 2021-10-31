#include "heltec.h"
#define BAND 868E6 
#define Open_LED  12

int counter = 0;
void setup() {
  
  Heltec.begin(false /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
	pinMode(Open_LED,INPUT);
    digitalWrite(Open_LED,LOW);
	LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
  
}

void loop() {
	if(digitalRead(Open_LED)){
	  Serial.print("Sending packet: OpenLED\r\n");
	  // send packet
	  LoRa.beginPacket();
	  LoRa.print("OpenLED");
	  LoRa.endPacket();
	  digitalWrite(Open_LED,LOW);                       
	}
	delay(1000);  
}