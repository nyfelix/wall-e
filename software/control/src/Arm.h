
#include <Arduino.h>
#include <Servo.h>
#include <Modular.h>

// CAREFUL: STAY IN RANGE
// Range of Micro servo Tower Pro SG90: 200-1000
// Range of FITEC FS5106B: (180)200-550(570) = 180

// Define Arm as Class to instantiate a left and a right arm
#ifndef Arm_h
#define Arm_h

#define HANDMIN   0
#define HANDMAX  65
#define ARMMIN   10 // 200 has Colissionwith Caterpillar
#define ARMMAX  110

class Arm : Component
{
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

#endif
