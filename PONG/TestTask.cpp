#include "TestTask.h"

TestTask::TestTask(){
  
}

void TestTask::init(int period){
  Task::init(period);
}

void TestTask::tick(){
  Serial.println("1 sec");
}

