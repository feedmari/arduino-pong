#include "Ball.h"
#include "Arduino.h"
#define BALL_SIZE 3
#define PAD_SIZE 5

Ball::Ball(int heightMatrix, int widthMatrix, int speedX, int speedY) {
	this->heightMatrix = heightMatrix;
	this->widthMatrix = widthMatrix;
	this->x = widthMatrix/2;
	this->y= heightMatrix/2;
	this->speedX = speedX;
	this->speedY = speedY;
	this->initialSpeedX = speedX;
	this->initialSpeedY = speedY;
  this->width = 2;
}

void Ball::move() {
	this->x += this->speedX;
	this->y += this->speedY;

	//Check left wall
	if(this->y + 1 >= this->heightMatrix) {
		this->speedY *= -1;
		this->y = this->heightMatrix - 2 ;
	}
	//check right wall
	if (this->y + 1 <= 0) {
		this->speedY *= -1;
		this->y = 1;
	}
}



void Ball::reset() {
	this->x = widthMatrix / 2;
	this->y = heightMatrix / 2;
	this->speedX = initialSpeedX;
	this->speedY = initialSpeedY;
}

int Ball::getSpeedX() {
  return this->speedX;
}
int Ball::getSpeedY() {
  return this->speedY;
}

void Ball::setSpeedX(int speedX){
  this->speedX = speedX;
}

void Ball::setSpeedY(int speedY){
  this->speedY = speedY;
}




