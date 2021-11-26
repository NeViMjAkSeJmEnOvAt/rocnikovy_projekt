#include "WiFi.h"
#include "heltec.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "ESPAsyncWebServer.h"
#include "SoftwareSerial.h"
#include "SPIFFS.h"
#include "Wire.h"
#include "string.h"
#include "stdio.h"

#define PASMO 434E6 //pasmo pro Evropu
#define OLED_RST 16
#define OLED_SDA 4
#define OLED_SCL 15
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

const char *ssid = "MK 2.4GHz"; //nazev wifi, na kterou se zařízení připojí
const char *password = "MK12345678";         //heslo k wifi
char VyslednyText[2];
String VypisovanyText;
String VypisovanyText2;

AsyncWebServer server(80);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);

String parser(String gps, int x)
{
  switch (x)
  {
  case 1: //longitude
    return (gps.substring(0, 10));
    break;
  case 2: //latitude
    return (gps.substring(10, 20));
    break;
  case 3: //altitude
    return (gps.substring(20, 26));
    break;
  case 4: //cas
    return (gps.substring(26, 34));
    break;
  case 5: //datum
    return (gps.substring(34, 44));
    break;
  }
}

String processor(const String &var)
{
  Serial.println(var);
  if (var == "GPS_LON")
  { //pokud se webserver zeptá na identifikátor GPS, bude mu poslán VyslednyText
    Serial.println(parser(VypisovanyText2, 1));
    return (parser(VypisovanyText2, 1));
  }
  else if (var == "GPS_LAT")
  { //pokud se webserver zeptá na identifikátor GPS, bude mu poslán VyslednyText
    Serial.println(parser(VypisovanyText2, 2));
    return (parser(VypisovanyText2, 2));
  }
  else if (var == "GPS_ALT")
  { //pokud se webserver zeptá na identifikátor GPS, bude mu poslán VyslednyText
    Serial.println(parser(VypisovanyText2, 3));
    return (parser(VypisovanyText2, 3));
  }
  else if (var == "GPS_TIME")
  { //pokud se webserver zeptá na identifikátor GPS, bude mu poslán VyslednyText
    Serial.println(parser(VypisovanyText2, 4));
    return (parser(VypisovanyText2, 4));
  }
  else if (var == "GPS_DATE")
  { //pokud se webserver zeptá na identifikátor GPS, bude mu poslán VyslednyText
    Serial.println(parser(VypisovanyText2, 5));
    return (parser(VypisovanyText2, 5));
  }
  return String();
}
void setup()
{
  Serial.begin(115200);
  Heltec.begin(false /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, PASMO /*long BAND*/); //nastaveni hardwaru

  ////////////////display////////////////////

  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, LOW);
  delay(20);
  digitalWrite(OLED_RST, HIGH);

  Wire.begin(OLED_SDA, OLED_SCL);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false))
  { // Adresa 0x3C pro 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Nepůjde do nekonečna
  }

  //////////////////////////pripojeni wifi////////////////////////////

  if (!SPIFFS.begin(true))
  { //inicializace SPIFFsu
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
  WiFi.begin(ssid, password); //připojení k wifi
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(2000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println(WiFi.localIP()); //vypíše IP adresu zařízení

  /////////////////////////////////////////////////////////////////

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) { //cesta pro root / webové stránky
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request) { //cesta pro .css soubor
    request->send(SPIFFS, "/style.css", "text/css");
  });
  server.begin(); //zapne server
}
void loop()
{
  VypisovanyText == "";
  int velikostPaketu = LoRa.parsePacket();
  if (velikostPaketu)
  { //pokud se nejaký packet přijme spustí se funkce
    while (LoRa.available())
    { //prevedeni textu do jednoho stringu
      VypisovanyText += (VyslednyText + strlen(VyslednyText), "%c", (char)LoRa.read());
    }
    VypisovanyText2 = VypisovanyText; //vypsany text se uloží do druhé proměnné, aby se mohl načíst nový a s proměnnou stále pracovat
    Serial.println(parser(VypisovanyText2, 1));
    Serial.println(parser(VypisovanyText2, 2));
    Serial.println(parser(VypisovanyText2, 3));
    Serial.println(parser(VypisovanyText2, 4));
    Serial.println(parser(VypisovanyText2, 5));
    Serial.println(parser(VypisovanyText2, 6));
    display.setCursor(0, 0);
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.println(WiFi.localIP());
    display.println("Prijata Zprava: ");
    display.println(VypisovanyText);
    display.print("o sile (RSSI): ");
    display.println(LoRa.packetRssi());
    display.display();
    delay(100);
  }
  VypisovanyText = ""; //vynuluje vypisovaný text aby se nestakoval
}