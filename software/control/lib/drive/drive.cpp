#include <Arduino.h>
#include <Adafruit_MotorShield.h>

Adafruit_DCMotor *leftMotor;
Adafruit_DCMotor *rightMotor;

void setupDrive(Adafruit_DCMotor *iRightMotor, Adafruit_DCMotor *iLeftMotor) {
  leftMotor = iLeftMotor;
  rightMotor = iRightMotor;
}

int setSpeedLeft(int speed, int direction) {
  leftMotor->run(direction);
  leftMotor->setSpeed(speed);
  return 0;
}

int setSpeedRight(int speed, int direction) {
  rightMotor->run(direction);
  rightMotor->setSpeed(speed);
  return 0;
}

void testDrive() {
  int i;
  for(i=0; i<255; i++){
    setSpeedLeft(i, FORWARD);
    delay(10);
  }
  for(i=255; i>0; i--){
    setSpeedLeft(i, FORWARD);
    delay(10);
  }
  for(i=0; i<255; i++){
    setSpeedRight(i, FORWARD);
    delay(10);
  }
  for(i=255; i>0; i--){
    setSpeedRight(i, FORWARD);
    delay(10);
  }
}
