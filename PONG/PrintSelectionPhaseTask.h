#ifndef __PRINTSELECTIONPHASETASK__
#define __PRINTSELECTIONPHASETASK__

/* This interface models the Task that will show the selection phase on the matrix.*/

#include <Adafruit_GFX.h>  
#include <RGBmatrixPanel.h>
#include "Task.h"
#include "MatrixManager.h"
#include "SelectionPhaseVariables.h"
#include "PlayVariables.h"

class PrintSelectionPhaseTask : public Task{
private:
  MatrixManager* matrixManager;
  enum {WAIT_TO_DISPLAY, DISPLAY_JOYSTICK_MODE, DISPLAY_PROX_MODE, DISPLAY_COUNTDOWN} state;
  int counter; //counter for the countdown
  int countDown; //countdown variable

public:
  PrintSelectionPhaseTask(MatrixManager* matrixManager);
  void init(int period);
  void tick();
  
};

#endif
