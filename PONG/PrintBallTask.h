#ifndef __PRINTBALLTASK__
#define __PRINTBALLTASK__

/* This interface models the Task able to print the ball on the matrix. This task can also print the round over and the gameover phase*/

#include <Adafruit_GFX.h>  
#include <RGBmatrixPanel.h>
#include "Task.h"
#include "MatrixManager.h"
#include "Drawable.h"
#include "SelectionPhaseVariables.h"
#include "PointsVariables.h"
#include "PlayVariables.h"

#define BALL_COLOR matrixManager->getMatrix()->Color333(7,0,0)

class PrintBallTask : public Task{
private:
  MatrixManager* matrixManager;
  Drawable* drawableObject;
  enum {WAIT_TO_DISPLAY, DISPLAY_GAME, DISPLAY_PLAYER1_WINS, DISPLAY_PLAYER2_WINS, DISPLAY_POINTS} state;
  int counter;
  

public: 
  PrintBallTask(MatrixManager* matrixManagerPrinter, Drawable* drawableObject);
  void init(int period);
  void tick();
};

#endif
