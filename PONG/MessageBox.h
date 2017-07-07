#ifndef _MESSAGEBOX_
#define _MESSAGEBOX_

/*This interface models a messagebox, it's used to comunicate towards the Serial monitor*/

#include "Message.h"

class MessageBox {

public:
  MessageBox();
  Message* getMessage() const; //returns the message 
  bool messageAvailable(); //returns whether or not the message box has a pending message
  void send(char message); //sends a message towards the serial port
  void clearBox(); //clear the messageBox
};

#endif
