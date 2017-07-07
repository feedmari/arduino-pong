#ifndef __PRINTPADSTASK__
#define __PRINTPADSTASK__

/*This interface models the task able to print pads on the matrix*/

#include <Adafruit_GFX.h>  
#include <RGBmatrixPanel.h>
#include "Task.h"
#include "MatrixManager.h"
#include "Drawable.h"
#include "SelectionPhaseVariables.h"
#include "PadsVariables.h"
#include "PlayVariables.h"

#define PAD1_COLOR matrixManager->getMatrix()->Color333(7,0,0)
#define PAD2_COLOR matrixManager->getMatrix()->Color333(0,7,0)

class PrintPadsTask : public Task{
private:
  MatrixManager* matrixManager;
  Drawable** drawableObjects; //array of pointers to drawable objects. They will be both pads.
  int arraySize; //the size of drawable objects array size.
  enum {WAIT_TO_DISPLAY, DISPLAY_PADS} state;

public:
  PrintPadsTask(MatrixManager* matrixManager,Drawable** drawableObjects, int arraySize);
  void init(int period);
  void tick();
  
};

#endif
