#include "Controller.h"
#include "SelectionState.h"

Controller::Controller(){
  this->state = new SelectionState();
};

void Controller::step(){
  //the update of the actual state is delegated to the ControllerState object
  ControllerState* nextState = this->state->updateState();
  //if the updateState method returns an instance of a ControllerState object it means that there was a transition to a new state
  if(nextState != NULL){
    //the actual state can now be destroyed and replaced by the new state
    delete this->state;
    this->state = nextState;
  }
};

