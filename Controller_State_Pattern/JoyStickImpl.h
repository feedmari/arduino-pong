#ifndef __JOYSTICKIMPL__
#define __JOYSTICKIMPL__

#include "Joystick.h"
#include "Commands.h"
#include "Arduino.h"

#define MIN_JOYSTICK_RANGE 300
#define MAX_JOYSTICK_RANGE 700

class JoystickImpl : public Joystick{
public:
  JoystickImpl(int sXPin, int sYPin, int buttPin);
  int getSX();
  int getSY();
  Command getCommand(); //comodity method that checks where the joystick position is and if it's in a range of tollerance (to avoid false inputs) and returns the associated command
  bool isPressed();

private:
  int sXPin;
  int sYPin;
  int buttPin;
};

#endif
