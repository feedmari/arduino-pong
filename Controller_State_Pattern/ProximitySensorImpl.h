#ifndef __PROX_SENSOR_IMPL__
#define __PROX_SENSOR_IMPL__

#include "ProximitySensor.h"

class ProximitySensorImpl: public ProximitySensor {
public:
  ProximitySensorImpl(int trigPin, int echoPin);	
  virtual float getObjDistance();
private:
  int trigPin;
  int echoPin; 
  const float vs = 331.5 + 0.6*20;
};

#endif

