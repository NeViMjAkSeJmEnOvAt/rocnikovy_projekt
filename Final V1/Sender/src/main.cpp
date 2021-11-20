#include "heltec.h"
#include "TinyGPS++.h"
#include "HardwareSerial.h"
#define PASMO 434E6 //pasmo pro Evropu

TinyGPSPlus gps;
HardwareSerial SerialGPS(1);

void setup()
{
  Serial.begin(115200);
  SerialGPS.begin(9600, SERIAL_8N1, 16, 17);                                                                                                        //nastaveni portu RX-17 TX-16
  Heltec.begin(false /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, PASMO /*long BAND*/); //nastaveni hardwaru
}
void loop()
{
  while (SerialGPS.available() > 0)
  {
    gps.encode(SerialGPS.read());
  }

  Serial.print("LAT=");
  Serial.println(gps.location.lat(), 7); //vypise se 7 pozic cisla
  Serial.print("LONG=");
  Serial.println(gps.location.lng(), 7); //vypise se 7 pozic cisla
  Serial.print("ALT=");
  Serial.println(gps.altitude.meters());

  LoRa.beginPacket();
  LoRa.println(gps.location.lng(), 7);
  LoRa.println(gps.location.lat(), 7);
  LoRa.endPacket();
  delay(500);
}
