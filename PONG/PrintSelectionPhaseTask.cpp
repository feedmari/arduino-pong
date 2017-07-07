#include "PrintSelectionPhaseTask.h"

#define X_MODE 0
#define Y_MODE 0
#define X_STRING_MODE 0
#define Y_STRING_MODE 8
#define X_COUNTDOWN 13
#define Y_COUNTDOWN 4
#define COLOR_BUTTON_MODE matrixManager->getMatrix()->Color333(0,7,0)
#define COLOR_PROXIMITY_MODE matrixManager->getMatrix()->Color333(7,0,0)


PrintSelectionPhaseTask::PrintSelectionPhaseTask(MatrixManager* matrixManager){
  this->matrixManager = matrixManager;
  this->state = WAIT_TO_DISPLAY;
  this->counter = 0;
  this->countDown = 3;
}

void PrintSelectionPhaseTask::init(int period){
  Task::init(period);
}


void PrintSelectionPhaseTask::tick(){
  switch(state){
    case WAIT_TO_DISPLAY:
      if(selectionPhase){
        if(selectedMode == 0){
          state = DISPLAY_JOYSTICK_MODE;
        }else{
          state = DISPLAY_PROX_MODE;
        }  
        matrixManager->clearScreen();
      }
    break;
    case DISPLAY_JOYSTICK_MODE:
      matrixManager->printString(X_MODE, Y_MODE, COLOR_BUTTON_MODE, "Joyst");
      matrixManager->printString(X_STRING_MODE, Y_STRING_MODE, COLOR_BUTTON_MODE, "Mode");
      if(selectedMode == 1){
        state = DISPLAY_PROX_MODE;
        matrixManager->clearScreen();
      }
      if(selectionPhase == false){
        state = DISPLAY_COUNTDOWN;
        matrixManager->clearScreen();
      }
    break;
    case DISPLAY_PROX_MODE:
      matrixManager->printString(X_MODE, Y_MODE, COLOR_PROXIMITY_MODE, "Prox");
      matrixManager->printString(X_STRING_MODE, Y_STRING_MODE, COLOR_PROXIMITY_MODE, "Mode");
      if(selectedMode == 0){
        state = DISPLAY_JOYSTICK_MODE;
        matrixManager->clearScreen();
      }
      if(selectionPhase == false){
        state = DISPLAY_COUNTDOWN;
        matrixManager->clearScreen();
      }
    break;
    case DISPLAY_COUNTDOWN:
      matrixManager->printString(X_COUNTDOWN, Y_COUNTDOWN, COLOR_PROXIMITY_MODE, (String) countDown);
      counter++;
      if(counter == 5 || counter == 11){
        matrixManager->clearScreen();
        countDown--;
      }
      if(counter >= 17){
        play = true;
        state = WAIT_TO_DISPLAY;
        counter = 0;
        countDown = 3;
      }
      
    break;
  }
}

