#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

/* This interface models an object in game.*/

class GameObject{
protected:
  int x,y, width; 
public:
  int getX(){
    return x;
  }
  int getY(){
    return y;
  }
  int getWidth(){
    return width;
  }
  void setX(int newX){
    x = newX;
  }
  void setY(int newY){
    y = newY;
  }
  void setWidth(int newWidth){
    width = newWidth;
  }
};

#endif
