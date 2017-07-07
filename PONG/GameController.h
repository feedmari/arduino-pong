#ifndef __GAMECONTROLLER__
#define __GAMECONTROLLER__

/* This interface models the gamecontroller, this controller is composed from 2 players and 1 ball and can manage them*/

#include "Ball.h"
#include "Player.h"

class GameController {
private:
	int goal; //Indicate the goal to reach to win the match
	int player1Points; //Indicate the points gained from Player 1, it has to be on the Left side
	int player2Points; //Indicate the points gained from Player 2, it has to be on the Right side
	Player* player1; 
	Player* player2;
	Ball* ball;


public:
	GameController(Player* player1, Player* player2, Ball* ball, int goal);
	void addPoint(); //add 1 point to the correct player, it's based on the ball's position when the round is over
	void startRound(); //reset ball position and player's pads.
  Player* getPlayer(int playerNumber); //return the player, to manage it from the tasks
  Ball* getBall(); //return the ball, to manage  it from the tasks.
  bool launchCheck(); //return true if checkCollision can be called, it can be called only if the Ball is in pad Range
  int checkWinner(); //check if players have reached the goal, return -1 if player 1 won,  0 if the game is not finished yet (goal not reached), 1 if player 2 won
  int getPlayer1Points(); //return player 1 points
  int getPlayer2Points();  //return player 2 points
  void resetPoints(); //reset points, used when is starting a new game
};

#endif
