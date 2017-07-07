#ifndef __JOYSTICK__
#define __JOYSTICK__

class Joystick{
public: 
  virtual int getSX() = 0;
  virtual int getSY() = 0;
  virtual bool isPressed() = 0;
};

#endif
