#ifndef __DRAWABLEPAD__
#define __DRAWABLEPAD__

/*This inteface extends Drawable interface, it's a specific extension that draw a pad on the matrix*/

#include "Drawable.h"

class DrawablePad : public Drawable{
public:
  DrawablePad(GameObject* obj, RGBmatrixPanel* matrix):Drawable(obj, matrix){}
  void draw(uint16_t color);
};


#endif

