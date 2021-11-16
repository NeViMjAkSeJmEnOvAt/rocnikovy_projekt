#include "heltec.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "Wire.h"
#include "Adafruit_GPS.h"

//gps
#define GPSSerial Serial2
#define PASMO 434E6

//display
#define OLED_RST 16
#define OLED_SDA 4
#define OLED_SCL 15
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define CAS 0

//inicializace
int pocet = 0;
int x = 0;
Adafruit_GPS GPS(&GPSSerial);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);

void setup()
{

  Serial.begin(115200);
  GPSSerial.begin(9600);
  GPS.begin(9600);
  Heltec.begin(false /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, PASMO /*long BAND*/); //nastaveni hardwaru
  uint32_t updateTime = 100;

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
  ////////////////////////////////////////
}

void loop()
{
  display.setTextColor(WHITE);
  display.setTextSize(2);
  /*for (x; x < CAS; x++)
  {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Nacitam.");
    display.setCursor(0, 20);
    display.println("GPS / LoRa");
    display.display();
    delay(500);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Nacitam..");
    display.setCursor(0, 20);
    display.println("GPS / LoRa");
    display.display();
    delay(500);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Nacitam...");
    display.setCursor(0, 20);
    display.println("GPS / LoRa");
    display.display();
    delay(500);
  }*/
  GPS.read();
  if (GPS.newNMEAreceived())
  {
    GPS.parse(GPS.lastNMEA());
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(1);
    /////////////vypsani casu////////////////
    display.print(GPS.day);
    display.print(".");
    display.print(GPS.month);
    display.print(".");
    display.print(GPS.year);
    display.print("   ");
    display.print(GPS.hour + 1);
    display.print(":");
    display.print(GPS.minute);
    display.print(":");
    display.print(GPS.seconds);
    display.setCursor(0, 20);
    ////////////////vypis souradnic/////////////////////
    display.println("-Aktualni GPS pozice-");
    display.print(GPS.latitude_fixed);
    display.println(" Z. Sirky");
    display.print(GPS.longitude_fixed);
    display.println(" Z. Delky");
    display.display();
    Serial.println(GPS.satellites);
    //////////////odeslani informaci///////////////////////////
    LoRa.beginPacket();
    LoRa.print(GPS.latitude_fixed);
    LoRa.print(GPS.longitude_fixed);
    LoRa.endPacket();
  }
  else{
    LoRa.beginPacket();
    LoRa.print("50.0933888");
    LoRa.print("17.5258640");
    LoRa.endPacket();
  }
  delay(500);
  Serial.println(GPS.satellites);
}
