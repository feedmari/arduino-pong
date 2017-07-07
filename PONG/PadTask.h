#ifndef __PADTASK__
#define __PADTASK__

/*This interface models the Task that will manage pads.*/

//Messages received from the other Arduino
#define MOVE_UP1 'c'
#define MOVE_DOWN1 'd'
#define MOVE_UP2 'e'
#define MOVE_DOWN2 'f'

#include "Task.h"
#include "GameController.h"
#include "MessageBox.h"
#include "PadsVariables.h"
#include "PlayVariables.h"

class PadTask : public Task{
private:
  GameController* gameController;
  MessageBox* messageBox;
  enum {WAIT_TO_PLAY, MANAGE_INPUTS} state;

public:
  PadTask(GameController* gameController,MessageBox* messageBox);
  void init(int period);
  void tick();
  
};

#endif
