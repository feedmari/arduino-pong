#include "MatrixManager.h"

MatrixManager::MatrixManager(){
  this->matrix = new RGBmatrixPanel(A,B,C,CLK,LAT,OE,false);
  this->matrix->begin();
}

RGBmatrixPanel* MatrixManager::getMatrix(){
  return this->matrix;
}

void MatrixManager::resetMatrix(){
  delete this->matrix;
  this->matrix = new RGBmatrixPanel(A,B,C,CLK,LAT,OE,false);
  this->matrix->begin();
}

void MatrixManager::printString(int x, int y, uint16_t color, String str){
  this->matrix->setTextColor(color);
  this->matrix->setCursor(x,y);
  this->matrix->print(str);
  
}

void MatrixManager::clearScreen(){
  this->matrix->fillScreen(0);
}

void MatrixManager::clearLeftSide(){
  this->matrix->drawLine(0,0,0,15,0);
}

void MatrixManager::clearRightSide(){
  this->matrix->drawLine(31,0,31,15,0);
}

void MatrixManager::clearBallPlayGround(){
  this->matrix->fillRect(1,0,30,16,0);
}

