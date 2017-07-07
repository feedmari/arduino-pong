#ifndef __PROX_SENSOR__
#define __PROX_SENSOR__

class ProximitySensor {
public:
  virtual float getObjDistance() = 0;
};

#endif

