#include "SelectionState.h"
#include "Messages.h"
#include "Message.h"
#include "JoystickGameState.h"
#include "ProxGameState.h"

SelectionState::SelectionState(){
  this->selector = new JoystickImpl(JOYSTICK1_SX_PIN, JOYSTICK1_SY_PIN, JOYSTICK1_BUTTON_PIN);
  this->messageBox = new MessageBox();
};

SelectionState::~SelectionState(){
  delete this->selector;
  delete this->messageBox;
};

ControllerState* SelectionState::updateState(){
  Message* msg;
  Command cmd = this->selector->getCommand();
  switch(cmd){
    case LEFT:
    case RIGHT:
    this->messageBox->send(CHANGE_GAME_MODE);
    return NULL;
    case UP:
    case DOWN:
    this->messageBox->send(SELECT_GAME_MODE);
    //this part is blocking for synchronization purpose and to create a rendez vous, when this arduino sends the message SELECT_GAME_MODE, the other answers with the game mode that has been selected
    while(!this->messageBox->messageAvailable()){} 
    msg = this->messageBox->getMessage();
    //by checking the message received, the right game mode state is created, and the state of the controller changes accordingly
    if(msg->getContent() == BUTTON_GAME){
      delete msg;
      return new JoystickGameState();
    }else{
      delete msg;
      return new ProxGameState();
    }
    case NO_COMMAND:
    return NULL;
    default:
    return NULL;
  }
  
};

