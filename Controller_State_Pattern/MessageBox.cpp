#include "MessageBox.h"
#include "Arduino.h"

MessageBox::MessageBox() {
  Serial.begin(9600);
}

Message* MessageBox::getMessage() const{
	Message* message = new Message(Serial.read());
	return message;
}

bool MessageBox::messageAvailable() {
	return (Serial.available());
}

void MessageBox::send(char message) {
	Serial.print(message);
}

