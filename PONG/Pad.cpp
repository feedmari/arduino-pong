#include "Pad.h"

Pad::Pad(int xPad, int yPad, int width) {
  this->x = xPad;
  this->y = yPad;
  this->width = width;
  this->initialXPad = xPad;
  this->initialYPad = yPad;
}

void Pad::resetPad() {
  this->x = this->initialXPad;
  this->y = this->initialYPad;
}

void Pad::moveUp() {
  //Check if the next position will be out of top bound
  if ((this->y - width) - 1 >= 0) {
    this->y--;
  }
}

void Pad::moveDown() {
  //Check if the next position will be out of bottom bound
  if ((this->y + width) + 1 <= 15) {
    this->y++;
  }
}

