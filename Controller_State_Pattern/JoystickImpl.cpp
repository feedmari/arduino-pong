#include "JoystickImpl.h"
#include "Arduino.h"



JoystickImpl::JoystickImpl(int sXPin, int sYPin, int buttPin){
  this->sXPin = sXPin;
  this->sYPin = sYPin;
  this->buttPin = buttPin;
  pinMode(sXPin, INPUT);
  pinMode(sYPin, INPUT);
  pinMode(buttPin, INPUT);
}

int JoystickImpl::getSX(){
  return analogRead(sXPin);
}

Command JoystickImpl::getCommand(){
  int x = this->getSX();
  int y = this->getSY();
  if(x <= MIN_JOYSTICK_RANGE){
    return LEFT;
  }
  if(x >= MAX_JOYSTICK_RANGE){
    return RIGHT;
  }
  if(y <= MIN_JOYSTICK_RANGE){
    return DOWN;
  }
  if(y >= MAX_JOYSTICK_RANGE){
    return UP;
  }
  return NO_COMMAND;
}

int JoystickImpl::getSY(){
  return analogRead(sYPin);
}

bool JoystickImpl::isPressed(){
  return digitalRead(buttPin);
}



