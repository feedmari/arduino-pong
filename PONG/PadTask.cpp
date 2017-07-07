#include "PadTask.h"
#include "Arduino.h"

PadTask::PadTask(GameController* gameController,MessageBox* messageBox){
  this->gameController = gameController;
  this->messageBox = messageBox;
  this->state = WAIT_TO_PLAY;
  drawPad1 = false;
  drawPad2 = false;
}

void PadTask::init(int period){
  Task::init(period);
}

void PadTask::tick(){
  switch(state){
    case WAIT_TO_PLAY:
      if(play){
        state = MANAGE_INPUTS;
        messageBox->clearBox();
      }
    break;
    case MANAGE_INPUTS:
      if(messageBox->messageAvailable()){   
        Message* msg = messageBox->getMessage();
        if(msg->getContent() == MOVE_UP1){
          gameController->getPlayer(1)->managePad(MOVE_UP);
          drawPad1 = true;
        }
        if(msg->getContent() == MOVE_DOWN1){
          gameController->getPlayer(1)->managePad(MOVE_DOWN);
          drawPad1 = true;
        }
        if(msg->getContent() == MOVE_UP2){
          gameController->getPlayer(2)->managePad(MOVE_UP);
          drawPad2 = true;
        }
        if(msg->getContent() == MOVE_DOWN2){
          gameController->getPlayer(2)->managePad(MOVE_DOWN);
          drawPad2 = true;
        }   
      }
      if(play == false){
        state = WAIT_TO_PLAY;
      }
      
    break;
  }
}

