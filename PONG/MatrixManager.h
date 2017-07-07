#ifndef __MATRIXMANAGER__
#define __MATRIXMANAGER__

/*This interface models the matrix manager. It's able to print strings on the matrix, clear pads sides, clear the ball playground and clear the whole matrix*/

#include <Adafruit_GFX.h>  
#include <RGBmatrixPanel.h>


#define CLK 8
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2


class MatrixManager{
private:
  RGBmatrixPanel* matrix;

public:
  MatrixManager();
  void resetMatrix(); //reset the Matrix
  RGBmatrixPanel* getMatrix(); //return the matrix
  void printString(int x, int y, uint16_t color, String str); // this method will print a string on the matrix in position x,y
  void clearScreen(); //this method clear the matrix
  void clearLeftSide(); //clear left side (padLeft side)
  void clearRightSide(); // clear right side (padRight side)
  void clearBallPlayGround(); //clear ball playground
};


#endif
