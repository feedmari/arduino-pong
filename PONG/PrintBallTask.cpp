#include "PrintBallTask.h"

#define X_PLAYER1 5
#define Y_PLAYER1 4
#define X_PLAYER2 21
#define Y_PLAYER2 4
#define PLAYER1_COLOR matrixManager->getMatrix()->Color333(7,0,0)
#define PLAYER2_COLOR matrixManager->getMatrix()->Color333(0,7,0)
#define WINNER_X 10
#define WINNER_Y 0
#define WIN_X_TEXT 9
#define WIN_Y_TEXT 8

PrintBallTask::PrintBallTask(MatrixManager* matrixManager, Drawable* drawableObject){
  this->matrixManager = matrixManager;
  this->drawableObject = drawableObject;
  this->state = WAIT_TO_DISPLAY;
  this->counter = 0;
}

void PrintBallTask::init(int period){
  Task::init(period);
}

void PrintBallTask::tick(){
  switch(state){
    case WAIT_TO_DISPLAY:
      if(play){
        state = DISPLAY_GAME;
      }
    break;
    case DISPLAY_GAME:
      matrixManager->clearBallPlayGround();
      this->drawableObject->draw(BALL_COLOR);
      if(showPoints){
        state = DISPLAY_POINTS;
        this->matrixManager->clearScreen();
      }else if(player1Wins){
        state = DISPLAY_PLAYER1_WINS;
        this->matrixManager->clearScreen();
      }else if(player2Wins){
        state = DISPLAY_PLAYER2_WINS;
        this->matrixManager->clearScreen();
      }
    break;
    case DISPLAY_POINTS:
      this->matrixManager->printString(X_PLAYER1, Y_PLAYER1, PLAYER1_COLOR, (String)player1PointsShowed);
      this->matrixManager->printString(X_PLAYER2, Y_PLAYER2, PLAYER2_COLOR, (String)player2PointsShowed);
      if(counter++ >= 60){
        this->matrixManager->clearScreen();
        showPoints = false;
        state = DISPLAY_GAME;
        counter = 0;
      }    
      
    break;
    case DISPLAY_PLAYER1_WINS:
      this->matrixManager->printString(WINNER_X, WINNER_Y, PLAYER1_COLOR, "P1");
      this->matrixManager->printString(WIN_X_TEXT, WIN_Y_TEXT, PLAYER1_COLOR, "WINS!");
      if(counter++ == 60){
        this->matrixManager->clearScreen();
        matrixManager->resetMatrix();
        state = WAIT_TO_DISPLAY;
        player1Wins = false;
        selectionPhase = true;
        counter = 0;
      
      }
    break;
    case DISPLAY_PLAYER2_WINS:
      this->matrixManager->printString(WINNER_X, WINNER_Y, PLAYER1_COLOR, "P2");
      this->matrixManager->printString(WIN_X_TEXT, WIN_Y_TEXT, PLAYER1_COLOR, "WINS!");
      if(counter++ == 60){
        this->matrixManager->clearScreen();
        matrixManager->resetMatrix();
        state = WAIT_TO_DISPLAY;
        player2Wins = false;
        selectionPhase = true;
        counter = 0;
      }
    break;
  }
}


