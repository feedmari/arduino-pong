#ifndef __MESSAGES__
#define __MESSAGES__

//COMMANDS SENT FROM THIS ARDUINO TO THE OTHER ONE
#define CHANGE_GAME_MODE 'a'
#define SELECT_GAME_MODE 'b'
#define MOVE_UP1 'c'
#define MOVE_DOWN1 'd'
#define MOVE_UP2 'e'
#define MOVE_DOWN2 'f'

//COMMANDS SENT FROM THE OTHER ARDUINO TO THIS ARDUINO
#define BUTTON_GAME 'g'
#define PROXIMITY_GAME 'h'
#define ROUND_IS_OVER 'i'
#define IN_ROUND 'l'
#define GAME_IS_OVER 'm'
#define RESTART_GAME 'n'

#endif
