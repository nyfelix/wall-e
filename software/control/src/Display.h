#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_HX8357.h>
#include <Modular.h>

#ifndef Display_h
#define Display_h

// These are 'flexible' lines that can be changed
#define TFT_CS 6
#define TFT_DC 7
#define TFT_RST -1 // RST can be set to -1 if you tie it to Arduino's reset

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
class Display : Component
{
  public:
    Display();
    void dispLog(String msg);

  private:
    Adafruit_HX8357 *tft;
};

#endif
