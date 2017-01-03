#include <display.h>

Display::Display() {
   tft = new Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);
   // SoftSPI - note that on some processors this might be *faster* than hardware SPI!
   // Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, MOSI, SCK, TFT_RST, MISO);
   tft->begin(HX8357D);
   tft->setRotation(0);
   tft->fillScreen(HX8357_BLUE);
   tft->setCursor(2, 2);
   tft->setTextColor(HX8357_WHITE);
   tft->setTextSize(3);
   tft->println("Hi, I'm Wall-e!");
   tft->setTextSize(1);
   tft->println();
}

void Display::dispLog(String msg) {
  tft->println(msg);
  if (tft->getCursorY() > 380) {
    tft->fillScreen(HX8357_BLUE);
    tft->setCursor(2, 2);
  }
}
