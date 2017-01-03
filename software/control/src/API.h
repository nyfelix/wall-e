#include <Arduino.h>
#include <patterns/SerialAPI.h>
#include <Arm.h>
#include <Drive.h>
#include <Display.h>

#ifndef API_h
#define API_h
/*
  Implementation of SerialAPI for Wall-e. This kind if implementaiton could later also be genralized
  if the Maschin wouls hava a collection of components with keys accoring to the api calls
*/

class API : public SerialAPI
{
  public:
    API(Arm *arm, Drive *drive, Display *display);
    void handleSerialInstruction(String task, String value);
  private:
    Arm *arm;
    Drive *drive;
    Display *display;
};

#endif
