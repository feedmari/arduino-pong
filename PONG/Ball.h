#ifndef __BALL__
#define __BALL__

#include "GameObject.h"

/* This interface is used to model the ball in game*/

class Ball : public GameObject{
private:
	int speedX; //X velocity of the ball
	int speedY; //Y velocity of the ball
	int initialSpeedX; //initial ball speed on X axix
	int initialSpeedY; //initial ball speed on Y axis
	int widthMatrix; //widthMatrix of the matrix
	int heightMatrix; //height of the matrix

public:
	Ball(int heightMatrix, int widthMatrix, int speedX, int speedY);
	void move(); //move the ball in the Playground
	void reset(); //resume the position of the ball to initial X and Y
  int getSpeedX(); //return speedX
  int getSpeedY(); //return speedY
  void setSpeedX(int speedX); //set speedX
  void setSpeedY(int speedY); //set speedY
};

#endif
