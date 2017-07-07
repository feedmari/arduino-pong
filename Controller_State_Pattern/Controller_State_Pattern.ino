#include "Controller.h"
#include "Timer.h"

Controller* controller;
Timer timer;

void setup() {
  controller = new Controller();
  timer.setupPeriod(175);
}

void loop() {
  timer.waitForNextTick();
  controller->step();
}
