#include "Player.h"

Player::Player(Pad* pad) {
	this->pad = pad;
}

void Player::managePad(Command cmd) {
	switch (cmd)
	{
	case MOVE_UP:
		this->pad->moveUp();
		break;
	case MOVE_DOWN:
		this->pad->moveDown();
		break;
	case RESET:
		this->pad->resetPad();
		break;
	}
}

Pad* Player::getPad() {
	return this->pad;
}

