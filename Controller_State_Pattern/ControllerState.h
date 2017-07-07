#ifndef __CONTROLLERSTATE__
#define __CONTROLLERSTATE__

//the general interface for all possible states that the controller can be in and is used for implementing the state machines by using the state pattern by the GoF
class ControllerState{
  public:
  virtual ~ControllerState() {}
  virtual ControllerState* updateState() = 0; //this method is called by controller every tick of timer 
};

#endif

