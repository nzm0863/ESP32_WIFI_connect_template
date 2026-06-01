  #include <SPI.h>
  #include <XPT2046_Touchscreen.h>
  #include <Adafruit_GFX.h>
  #include <Adafruit_ILI9341.h>
  #include "pins.h"
  #include "wifi_manager.h"


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

  bool red = false;
  bool green = false;
  bool blue = false;
  bool yellow = false;
  bool touching = false;

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


      // if(x<=160&&y<=120){
      //   tft.fillRect(0, 0, 160, 120, ILI9341_GREEN);
      // }else if(x<=320&&y<=120){
      //   tft.fillRect(160, 0, 160, 120, ILI9341_BLUE);
      // }else if(x<=160&&y<=240){
      //   tft.fillRect(0, 120, 160, 120, ILI9341_YELLOW);
      // }else if(x<=320&&y<=240){
      //   tft.fillRect(160, 120, 160, 120, ILI9341_RED);
      // }

      tft.fillCircle(x, y, 2, ILI9341_BLACK);
    } else {
      touching = false;
    }
  }