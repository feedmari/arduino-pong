#ifndef __PAD__
#define __PAD__

/*This interface models a Pad. It will be able to move up, move down and reset his position*/

#include "GameObject.h"

class Pad : public GameObject {
private:
  int initialXPad; //first X pad, it will be used to reset the pad
  int initialYPad; //first Y pad, it will be used to reset the pad

public:
  Pad(int xPad, int yPad, int width);
  void moveUp(); //move the Pad one position up
  void moveDown(); //move the Pad one position down
  void resetPad(); //reset the Pad to initial position
};

#endif
