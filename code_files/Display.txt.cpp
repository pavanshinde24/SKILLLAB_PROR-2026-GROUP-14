#include "Display.h"
#include "Config.h"

#if USE_OLED
#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

#define I2C_ADDRESS 0x3C 
SSD1306AsciiWire oled;
unsigned long lastScreenUpdate = 0;

void initDisplay() {
  Wire.begin();
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setFont(Adafruit5x7);
  oled.clear();
  oled.println("====================");
  oled.println("   NEXUS ROBOTICS   ");
  oled.println("====================");
}

void updateDisplay() {
  if (millis() - lastScreenUpdate > 200) {
    oled.setCursor(0, 4); 
    
    if (isCarLocked) {
      oled.println("STATE: SECURED      ");
      oled.setCursor(0, 6); 
      oled.println("SENSORS: ASLEEP     "); 
    } else {
      if (isAutopilotEnabled) {
        oled.println("STATE: AUTOPILOT    ");
      } else {
        oled.println("STATE: MANUAL       ");
      }

      oled.setCursor(0, 6); 
      oled.print("FRONT DIST: "); 
      if (distanceAhead == 250) {
        oled.println("CLEAR ");
      } else {
        oled.print(distanceAhead);
        oled.println(" cm  "); 
      }
    }
    lastScreenUpdate = millis();
  }
}
#endif