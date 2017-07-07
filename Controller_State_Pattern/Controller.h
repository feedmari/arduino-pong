#ifndef __CONTROLLER__
#define __CONTROLLER__

#include "ControllerState.h"

//this class models the controller that sends inputs received from joysticks or proximity sensors
class Controller{
  public:
  Controller();
  void step(); //step is called every timer tick and updates the actual state of the controller by delegating the update state to the state object
  private:
  ControllerState* state; //the actual state of the controller
};

#endif

