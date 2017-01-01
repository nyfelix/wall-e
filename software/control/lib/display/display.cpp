#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_HX8357.h>

// These are 'flexible' lines that can be changed
#define TFT_CS 9
#define TFT_DC 10
#define TFT_RST -1 // RST can be set to -1 if you tie it to Arduino's reset

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);

// SoftSPI - note that on some processors this might be *faster* than hardware SPI!
// Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, MOSI, SCK, TFT_RST, MISO);

void setupDisplay() {
  tft.begin(HX8357D);
  tft.setRotation(0);
  tft.fillScreen(HX8357_BLUE);
  tft.setCursor(2, 2);
  tft.setTextColor(HX8357_WHITE);
  tft.setTextSize(3);
  tft.println("Hi, I'm Wall-e!");
  tft.setTextSize(1);
  tft.println();
}

void dispLog(String msg) {
  tft.println(msg);
  if (tft.getCursorY() > 380) {
    tft.fillScreen(HX8357_BLUE);
    tft.setCursor(2, 2);
  }
}
