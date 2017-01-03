#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Adafruit_PWMServoDriver.h>
#include <Arm.h>
#include <Display.h>
#include <Drive.h>
#include <API.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Get Motors
Adafruit_DCMotor *lMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rMotor = AFMS.getMotor(2);

Arm *leftArm;
Display *display;
Drive *drive;
API *api;
//String apiBuffer = "";
//#include <drive.cpp>
//#include <serialapi.cpp>

void componentTest () {
  // Testing all components
  display->dispLog("Start Testing Components...");
  display->dispLog("...Arm");
  leftArm->test();
  display->dispLog("...Arm OK");
  display->dispLog("...Drive");
  drive->test();
  display->dispLog("...Drive OK");
  display->dispLog("All tests completed. READY.");
}

void setup() {
  // Start serial communication
  Serial.begin(9600);
  // Start Motor Shield
  AFMS.begin();
  // Intiate components
  display = new Display();
  display->dispLog("Version 0.1");
  display->dispLog("Init Components...");
  // Left Arm with Serov for Hand on Pin 9 and Servo for Arm on Pin 7;
  leftArm = new Arm(9, 10);
  drive = new Drive(lMotor, rMotor);
  api = new API(leftArm, drive, display);
  //setupDrive(rMotor, lMotor);
  display->dispLog("OK");
  componentTest();
  yield();
}

void loop() {
  // Get clients coming from server
  api->run();
  delay(1); // Poll every 1ms
}
