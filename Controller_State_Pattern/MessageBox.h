#ifndef _MESSAGEBOX_
#define _MESSAGEBOX_

#include "Message.h"

class MessageBox {

public:
  MessageBox();
  Message* getMessage() const; //returns the message in the index position
  bool messageAvailable(); //returns whether or not the message box has a pending message
  void send(char message); //sends a message towards the serial port
};

#endif
