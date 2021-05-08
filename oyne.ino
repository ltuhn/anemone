#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
  
const unsigned char oye[] PROGMEM = {
  //fylles med bitmap av øynene
};


void setup() 
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.drawBitmap(0, 0, oye, 128, 64, WHITE);
  display.display();
}

void loop() 
{}
