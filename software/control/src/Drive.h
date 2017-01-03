#include <Arduino.h>
#include <Adafruit_MotorShield.h>
#include <Modular.h>

#ifndef Drive_h
#define Drive_h

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
class Drive : Component
{
  public:
    Drive(Adafruit_DCMotor *iRightMotor, Adafruit_DCMotor *iLeftMotor);
    int setSpeedLeft(int speed, int direction);
    int setSpeedRight(int speed, int direction);
    void test();

  private:
    Adafruit_DCMotor *leftMotor;
    Adafruit_DCMotor *rightMotor;
};

#endif
