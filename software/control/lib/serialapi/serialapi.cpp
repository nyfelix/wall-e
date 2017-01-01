#include <Arduino.h>
String apiBuffer = "";

void handleSerialInstruction(String task, String value) {
   // Handle Task instructions
    String msg = "Done: " +task + " -> "+value;
    //DEBUG
    int rval = value.toInt();;
    if (task == "hand") {
      dispLog(msg);
      int val = value.toInt();
      int rval = moveHand(val);
      Serial.println("{comp:hand,value:"+ (String)rval + "}");
    }
    if (task == "arm") {
      dispLog(msg);
      int val = value.toInt();
      int rval = moveArm(val);
      Serial.println("{comp:arm,value:" + (String)rval + "}");
    }
}

void serialAPI() {
  while (Serial.available() > 0) {
    //workstate:'workstate',rate:'blinkrate'\n
    //workstate:1, rate:30\n

    if (Serial.available() > 0) {
         char c = Serial.read();
         apiBuffer += c;
         //Serial.println(apiBuffer);
        if (c == ';') {
          Serial.println("Task revieced: " + apiBuffer);
          String order = apiBuffer.substring(0, apiBuffer.length() - 1);
          int j = order.indexOf(':');
          String task = order.substring(0, j);
          String value = order.substring(j+1);
          task.trim();
          value.trim();
          handleSerialInstruction(task, value);
          apiBuffer = "";
        }
    }
  }
}
