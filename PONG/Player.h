#ifndef __PLAYER__
#define __PLAYER__

/* This interface models a player in game, it's able to manage his pad using Commands*/

#include "Pad.h"
enum Command { MOVE_UP, MOVE_DOWN, RESET }; //All commands that Player can use on his pad

class Player {
private:
	Pad* pad;

public:
	Player(Pad* pad);
	void managePad(Command cmd); //player can use this function to manage his pad.
	Pad* getPad(); //return the Pad
};

#endif
