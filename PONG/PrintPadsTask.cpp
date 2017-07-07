#include "PrintPadsTask.h"
#include "Arduino.h"

PrintPadsTask::PrintPadsTask(MatrixManager* matrixManager,Drawable** drawableObjects, int arraySize){
  this->matrixManager = matrixManager;
  this->drawableObjects = drawableObjects;
  this->state = WAIT_TO_DISPLAY;
  this->arraySize = arraySize;
}

void PrintPadsTask:: init(int period){
  Task::init(period);
}

void PrintPadsTask::tick(){
  switch(state){
    case WAIT_TO_DISPLAY:
      if(play){
        state = DISPLAY_PADS;
        matrixManager->clearLeftSide();
        matrixManager->clearRightSide();
        this->drawableObjects[0]->draw(PAD1_COLOR);
        this->drawableObjects[1]->draw(PAD2_COLOR);
      }
    break;
    case DISPLAY_PADS:
      if(drawPad1){
        matrixManager->clearLeftSide();
        this->drawableObjects[0]->draw(PAD1_COLOR);
        drawPad1 = false;
      }  
      if(drawPad2){
        matrixManager->clearRightSide();
        this->drawableObjects[1]->draw(PAD2_COLOR);
        drawPad2 = false;
      }      
      if(play == false){
        state = WAIT_TO_DISPLAY;
        matrixManager->clearLeftSide();
        matrixManager->clearRightSide();
      }
    break;
  }
}

