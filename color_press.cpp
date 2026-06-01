#pragma once
#include <SPI.h>
#include <XPT2046_Touchscreen.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

extern Adafruit_ILI9341 tft;

bool red = false;
bool green = false;
bool blue = false;
bool yellow = false;

void redPress() {
  if (!red) {
    tft.fillRect(0, 0, 160, 120, ILI9341_BLACK);
  } else {
    tft.fillRect(0, 0, 160, 120, ILI9341_RED);
  }
  red = !red;
}
void greenPress() {
  if (!green) {
    tft.fillRect(160, 0, 160, 120, ILI9341_BLACK);
  } else {
    tft.fillRect(160, 0, 160, 120, ILI9341_GREEN);
  }
  green = !green;
}
void bluePress() {
  if (!blue) {
    tft.fillRect(0, 120, 160, 120, ILI9341_BLACK);
  } else {
    tft.fillRect(0, 120, 160, 120, ILI9341_BLUE);
  }
  blue = !blue;
}
void yellowPress() {
  if (!yellow) {
    tft.fillRect(160, 120, 160, 120, ILI9341_BLACK);
  } else {
    tft.fillRect(160, 120, 160, 120, ILI9341_YELLOW);
  }
  yellow = !yellow;
}
