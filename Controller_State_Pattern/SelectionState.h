#ifndef __SELECTIONSTATE__
#define __SELECTIONSTATE__

#include "ControllerState.h"
#include "JoyStickImpl.h"
#include "MessageBox.h"

//this class models the selection of the game mode state (proximity or joystick)
class SelectionState : public ControllerState{
  public:
  SelectionState();
  ~SelectionState();
  ControllerState* updateState();
  private:
  JoystickImpl* selector; //by default (at the moment) the selection of the game mode is done by using the joystick of the first player
  MessageBox* messageBox; //the update state method sends messages to second arduino, based on the inputs received from the joystick of the first player
};

#endif

