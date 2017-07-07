#include "JoystickGameState.h"

JoystickGameState::JoystickGameState(){
  this->player1 = new JoystickImpl(JOYSTICK1_SX_PIN, JOYSTICK1_SY_PIN, JOYSTICK1_BUTTON_PIN);
  this->player2 = new JoystickImpl(JOYSTICK2_SX_PIN, JOYSTICK2_SY_PIN, JOYSTICK2_BUTTON_PIN);
};

JoystickGameState::~JoystickGameState(){
  delete this->player1;
  delete this->player2;
};

Command JoystickGameState::getPlayer1Command(){
  return this->player1->getCommand();
};

Command JoystickGameState::getPlayer2Command(){
  return this->player2->getCommand();
};

