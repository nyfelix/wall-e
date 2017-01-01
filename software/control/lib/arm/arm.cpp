#include <Arduino.h>
#include <Servo.h>

// CAREFUL: STAY IN RANGE
// Range of Micro servo Tower Pro SG90: 200-1000
// Range of FITEC FS5106B: (180)200-550(570) = 180

// Define Arm as Class to instantiate a left and a right arm

#define HANDMIN   0
#define HANDMAX  65
#define ARMMIN   10 // 200 has Colissionwith Caterpillar
#define ARMMAX  110

class Arm {
  public:
    Arm(uint8_t pServoHand, uint8_t pServoArm);
    void test();
    int moveHand(int pos);
    int moveArm (int pos);
  private:
    uint8_t pServoHand;
    uint8_t pServoArm;
    Servo servoHand;
    Servo servoArm;
    int handPos;
    int armPos;
};
// our servo # counter





Arm::Arm(uint8_t pServoHand, uint8_t pServoArm) {
  servoHand.attach(pServoHand);
  servoArm.attach(pServoArm);
  handPos = HANDMIN;
  armPos = ARMMIN;
};

void Arm::test() {
  for (int pos = HANDMIN; pos <= HANDMAX; pos += 1) {
    // in steps of 1 degree
    servoHand.write(pos);
    delay(15);
  }
  for (int pos = ARMMIN; pos <= ARMMAX; pos += 1) {
    // in steps of 1 degree
    servoArm.write(pos);
    delay(15);
  }
}

// Move hand to x% between min and max
int Arm::moveHand(int pos) {
  if (pos < 0) { pos = 0; }
  if (pos > 100) { pos = 100; }
  handPos = HANDMIN + (pos * (HANDMAX - HANDMIN)/100);
  servoHand.write(handPos);
  //pwm.setPWM(servoHand, 0, handPos);
  return handPos;
}

// Move arm % between min and max
int Arm::moveArm (int pos) {
  if (pos < 0) { pos = 0; }
  if (pos > 100) { pos = 100; }
  armPos = ARMMIN + (pos * (ARMMAX - ARMMIN)/100);
  servoArm.write(handPos);
  //pwm.setPWM(servoArm, 0, armPos);
  return armPos;
}
