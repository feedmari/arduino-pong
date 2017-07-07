#ifndef __SELECTGAMEMODETASK__
#define __SELECTGAMEMODETASK__

/*This interface models the Task able to manage the selection of game mode. (Proximity or joystick)*/

#include "Task.h"
#include "MessageBox.h"
#include "SelectionPhaseVariables.h"
#include "PlayVariables.h"

//Messages sent from the controller Arduino to this one.
#define CHANGE_GAME_MODE 'a'
#define SELECT_GAME_MODE 'b'
#define BUTTON_GAME 'g'
#define PROXIMITY_GAME 'h'


class SelectGameModeTask : public Task{
private:
  MessageBox* messageBox;
  enum {IDLE, WAITING_INPUTS} state;
  
public:
  SelectGameModeTask(MessageBox* messageBox);
  void init(int period);
  void tick();
};

#endif
