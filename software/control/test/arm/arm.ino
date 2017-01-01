#include <Arduino.h>



#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// Range of Micro servo Tower Pro SG90: 200-1000
// Range of FITEC FS5106B: (180)200-550(570) = 180°
#define HANDMIN  200 
#define HANDMAX  280 
#define ARMMIN  250 // 200 has Colissionwith Caterpillar 
#define ARMMAX  450 

// our servo # counter
uint8_t servoHand= 0;
uint8_t servoArm = 1;
int handPos = HANDMIN;
int handDirection = 1;
int armPos = ARMMIN;
int armDirection = 1;

void setup() {
  Serial.begin(9600);
  Serial.println("Wall-e Arm Test");

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  yield(); 
}


void loop() {
  // Open an Close Hand
  handPos += handDirection;
  if (handPos == HANDMIN || handPos == HANDMAX) {
    handDirection = handDirection*-1;
  }  
  pwm.setPWM(servoHand, 0, handPos);
  
  armPos += armDirection;
  if (armPos == ARMMIN || armPos == ARMMAX) {
    armDirection = armDirection*-1;
  }
  pwm.setPWM(servoArm, 0, armPos);
  delay(5);
}
