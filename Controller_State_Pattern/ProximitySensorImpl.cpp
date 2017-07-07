#include "ProximitySensorImpl.h"
#include "Arduino.h"

ProximitySensorImpl::ProximitySensorImpl(int trig, int echo){
  trigPin = trig;
  echoPin = echo;
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

float ProximitySensorImpl::getObjDistance(){
    digitalWrite(trigPin,LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin,LOW);
    
    float tUS = pulseIn(echoPin, HIGH);
    float t = tUS / 1000.0 / 1000.0 / 2;
    float d = t*vs;
    return d;
}
