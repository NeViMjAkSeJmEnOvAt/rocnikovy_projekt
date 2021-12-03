#include "heltec.h"
#include "TinyGPS++.h"
#include "HardwareSerial.h"
#include "ArduinoJson.h"
#define PASMO 434E6                      //LoRa pasmo pro Evropu
unsigned long GPSMillis, LoRaMillis = 0; //uloží čas pro GPS a LoRA
const long intervalGPS = 2000;           //interval ve kterém se bude funkce spouštět pro GPS
const long intervalLoRa = 3000;          //interval ve kterém se bude funkce spouštět pro odesílání LoRa

TinyGPSPlus gps;
HardwareSerial SerialGPS(1);
DynamicJsonDocument doc(1024);


void setup()
{
  Serial.begin(115200);
  SerialGPS.begin(9600, SERIAL_8N1, 16, 17);                                                                                                        //nastaveni portu RX-17 TX-16
  Heltec.begin(false /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, PASMO /*long BAND*/); //nastaveni hardwaru
}
void loop()
{
  unsigned long TedMillis = millis(); //uloží momentální čas

  if (TedMillis - GPSMillis >= intervalGPS) //pokud už uběhl čas od posledního spuštění GPS
  {
    while (SerialGPS.available() > 0) //pokud je GPS signál dostupný
    {
      gps.encode(SerialGPS.read()); //přelož GPS signál
    }
    GPSMillis = TedMillis; //nastaví se momentální čas, aby se mohlo určit poslední spuštění funkce
  }
  if (TedMillis - LoRaMillis >= intervalLoRa)
  {
    Serial.print("LAT=");
    Serial.println(gps.location.lat(), 7); //vypise se 7 pozic cisla
    Serial.print("LONG=");
    Serial.println(gps.location.lng(), 7);
    Serial.print("ALT=");
    Serial.println(gps.altitude.meters());
    Serial.print("SAT=");
    Serial.println(gps.satellites.value());

    doc["lat"] = gps.location.lat();
    doc["lon"] = gps.location.lng();
    doc["alt"] = gps.altitude.meters();
    doc["hour"] = gps.time.hour();
    doc["min"] = gps.time.minute();
    doc["sec"] = gps.time.second();
    doc["day"] = gps.date.day();
    doc["mon"] = gps.date.month();
    doc["year"] = gps.date.year();
    doc["sat"] = gps.satellites.value();
    serializeJson(doc, Serial);

    LoRa.beginPacket();
    LoRa.println(serializeJson(doc, Serial));
    LoRa.endPacket();
    LoRaMillis = TedMillis;
  }
}
