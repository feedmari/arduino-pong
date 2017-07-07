#ifndef __JOYSTICKGAMESTATE__
#define __JOYSTICKGAMESTATE__

#include "PlayingState.h"
#include "JoyStickImpl.h"

//player 1 pins
#define JOYSTICK1_SX_PIN A0
#define JOYSTICK1_SY_PIN A1
#define JOYSTICK1_BUTTON_PIN 10

//player 2 pins
#define JOYSTICK2_SX_PIN A2
#define JOYSTICK2_SY_PIN A3
#define JOYSTICK2_BUTTON_PIN 11

//this class implements how inputs are read by using the joysticks but the updateState implementation is already present in the super class
class JoystickGameState : public PlayingState{
  public:
  ~JoystickGameState();
  JoystickGameState();
  protected:
  Command getPlayer1Command();
  Command getPlayer2Command();
  private:
  JoystickImpl* player1; //the joysticks of the players
  JoystickImpl* player2;
};

#endif
