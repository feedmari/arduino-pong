#ifndef __TESTTASK__
#define __TESTTASK__

#include "Arduino.h"
#include "Task.h"

class TestTask : public Task{
  public:
    TestTask();
    void init(int period);
    void tick();
};

#endif
