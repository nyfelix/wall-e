#include <drive.h>

Drive::Drive(Adafruit_DCMotor *iRightMotor, Adafruit_DCMotor *iLeftMotor) {
  leftMotor = iLeftMotor;
  rightMotor = iRightMotor;
}

int Drive::setSpeedLeft(int speed, int direction) {
  leftMotor->run(direction);
  leftMotor->setSpeed(speed);
  return 0;
}

int Drive::setSpeedRight(int speed, int direction) {
  rightMotor->run(direction);
  rightMotor->setSpeed(speed);
  return 0;
}

void Drive::test() {
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
