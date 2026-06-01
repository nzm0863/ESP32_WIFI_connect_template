#include <SPI.h>
#include <XPT2046_Touchscreen.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include "pins.h"
#include "wifi_manager.h"
#include "color_press.h"



Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST);
XPT2046_Touchscreen ts(T_CS, T_IRQ);


void setup() {
  Serial.begin(115200);
  wifiConnect();

  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_WHITE);

  ts.begin();
  ts.setRotation(3);

  tft.fillRect(0, 0, 160, 120, ILI9341_RED);
  tft.fillRect(160, 0, 160, 120, ILI9341_GREEN);
  tft.fillRect(0, 120, 160, 120, ILI9341_BLUE);
  tft.fillRect(160, 120, 160, 120, ILI9341_YELLOW);
}

bool touching = false;
void loop() {
  if (ts.touched()) {

    TS_Point p = ts.getPoint();

    int x = map(p.x, 280, 3655, 0, 320);
    int y = map(p.y, 280, 3655, 0, 240);

    if (!touching) {
      touching = !touching;
      if (x <= 160 && y <= 120) {
        redPress();
      } else if (x <= 320 && y <= 120) {
        greenPress();
      } else if (x <= 160 && y <= 240) {
        bluePress();
      } else if (x <= 320 && y <= 240) {
        yellowPress();
      }
    }

    tft.fillCircle(x, y, 2, ILI9341_BLACK);
  } else {
    touching = false;
  }
}