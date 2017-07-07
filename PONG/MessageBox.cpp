#include "MessageBox.h"
#include "Arduino.h"

MessageBox::MessageBox() {
  Serial.begin(9600);
}

Message* MessageBox::getMessage() const{
  //char k = Serial.read();
  //Serial.println(k);
	Message* message = new Message(Serial.read());
	return message;
}

bool MessageBox::messageAvailable() {
	return (Serial.available());
}

void MessageBox::send(char message) {
	Serial.write(message);
}

void MessageBox::clearBox(){
  while(Serial.available()){
    char c = Serial.read();
  }
}

