#ifndef __MESSAGE__
#define __MESSAGE__

/*This interface models a message*/

class Message {
  char content;

public:
  Message(char content){
    this->content = content;
  }
  
  char getContent(){
    return content;
  }
};

#endif
