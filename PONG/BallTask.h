#ifndef __BALLTASK__
#define __BALLTASK__

/* This interface is used to model the Task that will manage the ball movement on the playground, the roundover phase and the gameover phase*/

//Commands sent from this arduino to the other one
#define GAME_IS_OVER 'm'

#include "Task.h"
#include "GameController.h"
#include "MessageBox.h"
#include "PointsVariables.h"
#include "PlayVariables.h"

class BallTask : public Task{
private:
  GameController* gameController; //the gamecontroller used to manage ball, pads and collisions
  MessageBox* messageBox;
  enum {WAIT_TO_PLAY, IN_ROUND, ROUND_OVER, GAME_OVER} state; 

public:
  BallTask(GameController* gameController,MessageBox* messageBox);
  void init(int period);
  void tick();
};

#endif
