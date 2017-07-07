#ifndef __PROXGAMESTATE__
#define __PROXGAMESTATE__

#include "ProximitySensor.h"
#include "Commands.h"
#include "PlayingState.h"

//Pins for player1 proximity Sensors
#define PROXIMITY_LEFT1_TRIG 2
#define PROXIMITY_LEFT1_ECHO 3
#define PROXIMITY_RIGHT1_TRIG 4
#define PROXIMITY_RIGHT1_ECHO 5

//Pins for player2 proximity Sensors
#define PROXIMITY_LEFT2_TRIG 6
#define PROXIMITY_LEFT2_ECHO 7
#define PROXIMITY_RIGHT2_TRIG 8
#define PROXIMITY_RIGHT2_ECHO 9

//MINIMUM DISTANCE FOR PROXIMITY SENSOR
#define MIN_PROX_DISTANCE 0.20

//this class implements how inputs are read by using the proximity sensors but the updateState implementation is already present in the super class
class ProxGameState : public PlayingState{

  public:
  ~ProxGameState();
  ProxGameState();
  protected:
  Command getPlayer1Command();
  Command getPlayer2Command();
  private:
  ProximitySensor* left1; //the proximity sensors used by the players
  ProximitySensor* right1;
  ProximitySensor* left2;
  ProximitySensor* right2;
  Command getCommand(ProximitySensor* left, ProximitySensor* right); //method that checks if a player is in a distance less than or equal to 0.20 and that is the actual command
  
};

#endif
