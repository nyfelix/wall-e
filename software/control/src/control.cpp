#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Get Motors
Adafruit_DCMotor *lMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rMotor = AFMS.getMotor(2);

Arm leftArm;
String apiBuffer = "";

#include <arm.cpp>
#include <display.cpp>
//#include <drive.cpp>
//#include <serialapi.cpp>

void setup() {
  // Start serial communication
  Serial.begin(9600);
  // Start Motor Shield
  AFMS.begin();
  // Intiate components
  setupDisplay();
  dispLog("Version 0.1");
  dispLog("Init Components...");
  // Left Arm with Serov for Hand on Pin 9 and Servo for Arm on Pin 7;
  leftArm = new Arm(9, 10);
  //setupDrive(rMotor, lMotor);
  dispLog("OK");

  yield();
}

void loop() {
  // Get clients coming from server
  serialAPI();
  delay(1); // Poll every 10ms

}

void componentTest () {
  // Testing all components
  dispLog("Start Testing Components...");
  dispLog("...Arm");
  leftArm.test();
  dispLog("...Arm OK");
  dispLog("...Drive");
  testDrive();
  dispLog("...Drive OK");
  dispLog("All tests completed. READY.");
}
