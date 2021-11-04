#include <Adafruit_GPS.h>
#define GPSSerial Serial2
Adafruit_GPS GPS(&GPSSerial);
#define GPSECHO  true

void setup()
{
  GPSSerial.begin(9600, SERIAL_8N1,16,17);
  Serial.begin(115200);
  delay(1000);
  Serial.println("Adafruit GPS logging data dump!");
  // 9600 NMEA is the default baud rate for MTK - some use 4800
  GPS.begin(9600);
  delay(1000);
  Serial.println("----------------------------------------------------");

  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_ALLDATA);
}


uint32_t updateTime = 1000;

void loop(){
  GPS.read();
  if(GPS.newNMEAreceived()){
      GPS.parse(GPS.lastNMEA());
      Serial.println(GPS.day);
  }
  
  delay(100);
}