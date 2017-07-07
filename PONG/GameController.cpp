#include "GameController.h"
#include "Arduino.h"

GameController::GameController(Player* player1, Player* player2, Ball* ball, int goal) {
	this->player1 = player1;
	this->player2 = player2;
	this->ball = ball;
	this->player1Points = 0;
	this->player2Points = 0;
	this->goal = goal;
}

void GameController::startRound() {
	this->player1->managePad(RESET);
	this->player2->managePad(RESET);
	this->ball->reset();
}

Player* GameController::getPlayer(int playerNumber){
  if(playerNumber == 1){
    return this->player1;
  }else if(playerNumber == 2){
    return this->player2;
  }
}

Ball* GameController::getBall(){
  return this->ball;
}

bool GameController::launchCheck(){
  //check if the ball collided with the left pad player
  if((this->ball->getX() == this->player1->getPad()->getX()+1)){
    int randSmall = rand()%(2-1 + 1) + 1;
    int randBig = rand()%(3-1 + 1) + 1;
    //check if the Y ball is in left pad range
    if((this->ball->getY() >= this->player1->getPad()->getY() -4) && (this->ball->getY() <= this->player1->getPad()->getY() + 3)){
      //all possible collision's cases on left side
      if(this->ball->getY() == this->player1->getPad()->getY() + 3 && this->ball->getSpeedY() < 0) {
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        //this->ball->setSpeedY(2);
        this->ball->setSpeedY(randBig);
        return true;
      }
      if(this->ball->getY() == this->player1->getPad()->getY() + 2) {
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        //this->ball->setSpeedY(2);
        this->ball->setSpeedY(randSmall);
        return true;
      }
      if(this->ball->getY() == this->player1->getPad()->getY() + 1) {
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        this->ball->setSpeedY(1);
        return true;
      }
      if (this->ball->getY() == this->player1->getPad()->getY()){
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        this->ball->setSpeedY(0);
        return true;
      }
      if (this->ball->getY() == this->player1->getPad()->getY() - 1) {
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        this->ball->setSpeedY(-1);
        return true;
      }
      if(this->ball->getY() == this->player1->getPad()->getY() - 2 ) {
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        //this->ball->setSpeedY(-1);
        this->ball->setSpeedY(-1* randSmall);
        return true;
      }
      if( this->ball->getY() == this->player1->getPad()->getY() - 3){
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        //this->ball->setSpeedY(-2);
        this->ball->setSpeedY(-1* randSmall);
        return true;
      }
      if(this->ball->getY() == this->player1->getPad()->getY() - 4 && this->ball->getSpeedY() > 0){
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        //this->ball->setSpeedY(-3);
        this->ball->setSpeedY(-1 * randBig);
        return true;
      }
    }
    return false;
  }
  //check if the ball collided with the right pad player
  if((this->ball->getX() +2  == this->player2->getPad()->getX())){
    int randSmall = rand()%(2-1 + 1) + 1;
    int randBig = rand()%(3-1 + 1) + 1;
    //check if the Y ball is in right pad range
    if((this->ball->getY() >= this->player2->getPad()->getY() -4) && (this->ball->getY() <= this->player2->getPad()->getY() + 3)){

      //all possible collision's cases on left side
      if(this->ball->getY() == this->player2->getPad()->getY() + 3 && this->ball->getSpeedY() < 0) {
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        //this->ball->setSpeedY(2);
        this->ball->setSpeedY(randBig);
        return true;
      }
      if(this->ball->getY() == this->player2->getPad()->getY() + 2) {
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        //this->ball->setSpeedY(2);
        this->ball->setSpeedY(randSmall);
        return true;
      }
      if(this->ball->getY() == this->player2->getPad()->getY() + 1) {
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        this->ball->setSpeedY(1);
        return true;
      }
      if (this->ball->getY() == this->player2->getPad()->getY()){
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        this->ball->setSpeedY(0);
        return true;
      }
      if (this->ball->getY() == this->player2->getPad()->getY() - 1) {
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        this->ball->setSpeedY(-1);
        return true;
      }
      if(this->ball->getY() == this->player2->getPad()->getY() - 2) {
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        //this->ball->setSpeedY(-1);
         this->ball->setSpeedY(-1 * randSmall);
        return true;
      }
      if(this->ball->getY() == this->player2->getPad()->getY() - 3){
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        //this->ball->setSpeedY(-2);
         this->ball->setSpeedY(-1* randSmall);
        return true;
      }
      if(this->ball->getY() == this->player2->getPad()->getY() - 4 && this->ball->getSpeedY() > 0){
        this->ball->setSpeedX(this->ball->getSpeedX() * -1);
        //this->ball->setSpeedY(-3);
        this->ball->setSpeedY(-1* randBig);
        return true;
      }
    }
    return false;
  }
}

void GameController::addPoint(){
  if(this->ball->getX() - this->player1->getPad()->getX() == 1){
    this->player2Points++;
  }else{
    this->player1Points++;
  }
}

int GameController::checkWinner(){
  if(this->player1Points == goal){
    return -1;
  }else if(this->player2Points == goal){
    return 1;
  }else{
    return 0;
  }
}

int GameController::getPlayer1Points(){
  return this->player1Points;
}

int GameController::getPlayer2Points(){
  return this->player2Points;
}

void GameController::resetPoints(){
  this->player1Points = 0;
  this->player2Points = 0;
  
}

