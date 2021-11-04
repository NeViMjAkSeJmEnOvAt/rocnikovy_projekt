#include "MicroNMEA.h"
#include "Wire.h"

#define DEFAULT_DEVICE_ADDRESS 0x3A
#define DEFAULT_DEVICE_PORT 0xFF
#define I2C_DELAY 1

#define RESET_PIN 7

#ifdef ARDUINO_SAM_DUE
#define DEV_I2C Wire1
#endif

#ifdef ARDUINO_ARCH_STM32
#define DEV_I2C Wire
#endif

#ifdef ARDUINO_ARCH_AVR
#define DEV_I2C Wire
#endif
void setup() {¨
}

void loop() {
  // put your main code here, to run repeatedly:
}