#ifndef __DRAWABLEBALL__
#define __DRAWABLEBALL__

/*This interface extends Drawable interface, it's a specific extension to draw a ball 2x2 on the matrix*/

#include "Drawable.h"
#include <Adafruit_GFX.h>  
#include <RGBmatrixPanel.h>

class DrawableBall : public Drawable{
public:
  DrawableBall(GameObject* obj, RGBmatrixPanel* matrix):Drawable(obj, matrix){
  }
  void draw(uint16_t color);
};


#endif
