

#include <API.h>

API::API(Arm *iArm, Drive *iDrive, Display *iDisplay) : SerialAPI() {
  arm = iArm;
  drive = iDrive;
  display = iDisplay;
};

void API::handleSerialInstruction(String task, String value) {
   // Implemnation need to be done in the derived class for now
   String msg = "Execute: " +task + " -> "+value;
   display->dispLog(msg);
   //DEBUG
   int rval = value.toInt();;
   if (task == "hand") {

     int val = value.toInt();
     int rval = arm->moveHand(val);
     Serial.println("{comp:hand,value:"+ (String)rval + "}");
   }
   if (task == "arm") {

     int val = value.toInt();
     int rval = arm->moveArm(val);
     Serial.println("{comp:arm,value:" + (String)rval + "}");
   }

   if (task == "driveLeft") {
     int val = value.toInt();
     int rval = drive->setSpeedLeft(val, FORWARD);
     Serial.println("{comp:driveLeft,value:" + (String)rval + "}");
   }

   if (task == "driveRight") {
     int val = value.toInt();
     int rval = drive->setSpeedRight(val, FORWARD);
     Serial.println("{comp:driveRight,value:" + (String)rval + "}");
   }


}
