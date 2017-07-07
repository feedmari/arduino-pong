#include "SelectGameModeTask.h"

SelectGameModeTask::SelectGameModeTask(MessageBox* messageBox){
  this->messageBox = messageBox;
  this->state = IDLE;
  selectedMode = 0;
  selectionPhase = true;
  play = false;
}

void SelectGameModeTask::init(int period){
  Task::init(period);
}

void SelectGameModeTask::tick(){
  switch(state){
    case IDLE:
      if(selectionPhase){
        state = WAITING_INPUTS;
      }
    break;
    case WAITING_INPUTS:
      if(messageBox->messageAvailable()){   
        Message* msg = messageBox->getMessage();
        if(msg->getContent() == CHANGE_GAME_MODE){
          if(selectedMode == 0){
            selectedMode = 1;
          }else {
            selectedMode = 0;
          }
        } 
        if(msg->getContent() == SELECT_GAME_MODE){
          selectionPhase = false;
          if(selectedMode == 0){
            messageBox->send(BUTTON_GAME);
          }
          if(selectedMode == 1){
            messageBox->send(PROXIMITY_GAME);
          }
          this->state = IDLE;
        }
    }
    break;
  }
}

