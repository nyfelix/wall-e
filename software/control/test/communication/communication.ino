#include <Arduino.h>

/*
  Wall-e API

  Possible commands created in this shetch:

  "/arduino/set/arm/10"         -> Set the Arm betwoon 0 and 100% (100% is full up)
  "/arduino/set/hand/10"        -> Set the Arm betwoon 0 and 100% (100% is full open)
  "/arduino/set/speedleft/20"   -> Set the speed of left catapilar betwoon 0 and 100% (100% is max speed)
  "/arduino/set/speedright/20"  -> Set the speed of left catapilar betwoon 0 and 100% (100% is max speed)

*/

#include <Bridge.h>
#include <BridgeServer.h>
#include <BridgeClient.h>

// Listen to the default port 5555, the Yún webserver
// will forward there all the HTTP requests you send
BridgeServer server;

void setup() {
  // Bridge startup
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();

  // Listen for incoming connection only from localhost
  // (no one from the external network could connect)
  server.listenOnLocalhost();
  server.begin();
}

void loop() {
  // Get clients coming from server
  BridgeClient client = server.accept();

  // There is a new client?
  if (client) {
    // Process request
    process(client);

    // Close connection and free resources.
    client.stop();
  }

  delay(50); // Poll every 50ms
}

void process(BridgeClient client) {
  // read the command
  String command = client.readStringUntil('/');

  // is "digital" command?
  if (command == "set") {
    setCommand(client);
  }

}

void setCommand(BridgeClient client) {
  String subCommand = client.readStringUntil('/');
  int value = client.parseInt();
  if (value > 100) { value = 100; }
  if (value < 0) { value = 0; }
  
  // Send feedback to client
  client.print(F("Command: "));
  client.print(subCommand);
  client.print(F(" set to "));
  client.println(value);
}


