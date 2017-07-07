#ifndef __DRAWABALE__
#define __DRAWABALE__

/* This interface is used to define a drawable object that can be showed on the matrix*/

#include <Adafruit_GFX.h>  
#include <RGBmatrixPanel.h>

#include "GameObject.h"

class Drawable{
protected:
  GameObject* obj; //object to print on the matrix
  RGBmatrixPanel* matrix;

public: 
  Drawable(GameObject* newObj,RGBmatrixPanel* matrix){
    this->obj = newObj;
    this->matrix = matrix;
  }
  virtual void draw(uint16_t color) = 0; //this method will be overwritted to draw different gameobjects on the matrix
  
};

#endif
