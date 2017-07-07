#ifndef __PLAYINGSTATE__
#define __PLAYINGSTATE__

#include "Commands.h"
#include "Messages.h"
#include "MessageBox.h"
#include "Message.h"
#include "SelectionState.h"
#include "Arduino.h"
//PlayingState models the "in game" state of the machine and based on the inputs received from the player it sends the messages to the second arduino
class PlayingState : public ControllerState{

  public:
  virtual ~PlayingState(){
    delete this->messageBox;
  }
  PlayingState(){
    this->messageBox = new MessageBox();
  }
  ControllerState* updateState(){
    //this part checks if the other arduino sent a message that says that the game is over and if it's true, the controller state goes back to the selection of the game mode
    Message* msg;
    if(this->messageBox->messageAvailable()){
      msg = messageBox->getMessage();
      if(msg->getContent() == GAME_IS_OVER){
        delete msg;
        return new SelectionState();
      }
    }
    //here the template method pattern is used for reading the inputs received from players, the template method is good here because the messages that are sent to the other
    //arduino are always the same but it differs just how the inputs are read and it depends from the game mode selected before starting the game
    Command p1 = this->getPlayer1Command();
    Command p2 = this->getPlayer2Command();
    
    switch(p1){
      case UP:
      this->messageBox->send(MOVE_UP1);
      break;
      case DOWN:
      this->messageBox->send(MOVE_DOWN1);
      break;
      default:
      break;
    }
    switch(p2){
      case UP:
      this->messageBox->send(MOVE_UP2);
      break;
      case DOWN:
      this->messageBox->send(MOVE_DOWN2);
      break;
      default:
      break;
    }
    return NULL;
  };

  protected:
  virtual Command getPlayer1Command() = 0; //these are the templates of the methods that will be overridden in concrete subclasses and will return the commands of the players
  virtual Command getPlayer2Command() = 0; //the concrete subclasses are JoystickGameState and ProxGameState
  private:
  MessageBox* messageBox;
  
};

#endif
