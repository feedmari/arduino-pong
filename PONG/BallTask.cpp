#include "BallTask.h"

BallTask::BallTask(GameController* gameController,MessageBox* messageBox){
  this->gameController = gameController;
  this->messageBox = messageBox;
  this->state = WAIT_TO_PLAY;
  showPoints = false; 
  player1Wins = false; 
  player2Wins = false; 
  player1PointsShowed = 0; 
  player2PointsShowed = 0; 
}

void BallTask::init(int period){
  Task::init(period);
}

void BallTask::tick(){
  switch(state){
    case WAIT_TO_PLAY: 
      if(play){
        state = IN_ROUND; 
        this->gameController->resetPoints();
        this->gameController->startRound();
      }
    break;
    case IN_ROUND:
      gameController->getBall()->move();
      //check the limit only if the ball is near the pads
      if(!this->gameController->launchCheck()){
        play = false;
        this->gameController->addPoint();
        player1PointsShowed = this->gameController->getPlayer1Points();
        player2PointsShowed = this->gameController->getPlayer2Points();
        if(this->gameController->checkWinner() == 0){
          state = ROUND_OVER;
          this->gameController->startRound();
          showPoints = true;
        }else if(this->gameController->checkWinner() == -1){
          messageBox->send(GAME_IS_OVER);
          state = GAME_OVER;
          player1Wins = true;
        }else if(this->gameController->checkWinner() == 1){
          messageBox->send(GAME_IS_OVER);
          state = GAME_OVER;
          player2Wins = true;
        }     
      }
    break;
   case ROUND_OVER:
    if(showPoints == false){
      play = true;
      state = IN_ROUND;
    }
   break; 
   case GAME_OVER:
    if(player1Wins == false || player2Wins == false ){
      //messageBox->send(GAME_IS_OVER);
      state = WAIT_TO_PLAY;
      player1Wins = false;
      player2Wins = false;
      player1PointsShowed = 0;
      player2PointsShowed = 0;
    }    
   break;
  }
}

