#include "DrawablePad.h"

void DrawablePad::draw(uint16_t color){
  for(int i = this->obj->getY() - this->obj->getWidth() ; i <= this->obj->getY() + this->obj->getWidth(); i++){
    this->matrix->drawPixel(this->obj->getX(),i, color);
  }
}


