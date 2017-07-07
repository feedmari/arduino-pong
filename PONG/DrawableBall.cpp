#include "DrawableBall.h"


void DrawableBall::draw(uint16_t color){
  for(int x = this->obj->getX(); x <= this->obj->getX()+ this->obj->getWidth() - 1; x++){
    for(int y = this->obj->getY(); y <= this->obj->getY()+this->obj->getWidth() - 1; y++){
      this->matrix->drawPixel(x,y, color);
    }
  }
}





