#include "ProxGameState.h"
#include "ProximitySensorImpl.h"

ProxGameState::~ProxGameState(){
  delete this->left1;
  delete this->left2;
  delete this->right1;
  delete this->right2;
}

ProxGameState::ProxGameState(){
  this->left1 = new ProximitySensorImpl(PROXIMITY_LEFT1_TRIG, PROXIMITY_LEFT1_ECHO);
  this->right1 = new ProximitySensorImpl(PROXIMITY_RIGHT1_TRIG, PROXIMITY_RIGHT1_ECHO);
  this->left2 = new ProximitySensorImpl(PROXIMITY_LEFT2_TRIG, PROXIMITY_LEFT2_ECHO);
  this->right2 = new ProximitySensorImpl(PROXIMITY_RIGHT2_TRIG, PROXIMITY_RIGHT2_ECHO);
};

Command ProxGameState::getPlayer1Command(){
  return this->getCommand(this->left1, this->right1);
};

Command ProxGameState::getPlayer2Command(){
  return this->getCommand(this->left2, this->right2);
};

Command ProxGameState::getCommand(ProximitySensor* left, ProximitySensor* right){
  if(right->getObjDistance() <= MIN_PROX_DISTANCE)
  return UP;
  else if(left->getObjDistance() <= MIN_PROX_DISTANCE)
  return DOWN;
  else
  return NO_COMMAND;
};

