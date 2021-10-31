#include "heltec.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "Wire.h"
#include "string.h"
#include "stdio.h"


#define PASMO 868E6
#define OLED_RST 16
#define OLED_SDA 4
#define OLED_SCL 15
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);


void setup() {
  Serial.begin(115200);
  Heltec.begin(false /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, PASMO /*long BAND*/); //nastaveni hardwaru
    
   ////////////////display////////////////////
  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, LOW);
  delay(20);
  digitalWrite(OLED_RST, HIGH);
  ////////////////////////////////////////
  Wire.begin(OLED_SDA, OLED_SCL);
      if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false)) { // Adresa 0x3C pro 128x32
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Nepůjde do nekonečna
    }

}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Received packet '");
    while (LoRa.available()) {
	  LoRa.read();
    }
    Serial.print("prijato");
    Serial.print(" with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}