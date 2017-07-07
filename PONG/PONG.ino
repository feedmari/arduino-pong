#include "MessageBox.h"
#include "Task.h"
#include "TestTask.h"
#include "PrintSelectionPhaseTask.h"
#include "SelectGameModeTask.h"
#include "Scheduler.h"
#include "MatrixManager.h"
#include "PrintBallTask.h"
#include "PadTask.h"
#include "BallTask.h"
#include "GameController.h"
#include "Drawable.h"
#include "DrawableBall.h"
#include "DrawablePad.h"
#include "PrintPadsTask.h"
#include <Adafruit_GFX.h>  
#include <RGBmatrixPanel.h>
#include <TimerFlag.h>

MessageBox* messageBox;
Scheduler scheduler;
MatrixManager* matrixManager;
Pad* p1;
Pad* p2;
Ball* b;
Player* player1;
Player* player2;
GameController* gameController;
Drawable *drawableBall;
Drawable *drawablePads[2];

void setup() {

  matrixManager = new MatrixManager();  

  p1 = new Pad(0, 7, 2);
  p2 = new Pad(31, 7, 2);
  b = new Ball(16, 32, -1, 0);
  player1 = new Player(p1);
  player2 = new Player(p2);
  gameController = new GameController(player1,player2,b,3);

  drawableBall = new DrawableBall(b, matrixManager->getMatrix());
  drawablePads[0] = new DrawablePad (p1, matrixManager->getMatrix());
  drawablePads[1] = new DrawablePad (p2, matrixManager->getMatrix());

  messageBox = new MessageBox();
  
  scheduler.init();
 
  Task* selectGameModeTask = new SelectGameModeTask(messageBox);
  selectGameModeTask->init(175);
  
  Task* printSelectionPhaseTask = new PrintSelectionPhaseTask(matrixManager);
  printSelectionPhaseTask->init(175);

  Task* padTask = new PadTask(gameController, messageBox);
  padTask->init(75);

  Task* ballTask = new BallTask(gameController, messageBox);
  ballTask->init(25);

  Task* printBallTask = new PrintBallTask(matrixManager,drawableBall);
  printBallTask->init(25);

  Task* printPadsTask = new PrintPadsTask(matrixManager,drawablePads,2);
  printPadsTask->init(75);

  scheduler.addTask(padTask);
  scheduler.addTask(ballTask);
  scheduler.addTask(selectGameModeTask);
  scheduler.addTask(printBallTask);
  scheduler.addTask(printPadsTask);
  scheduler.addTask(printSelectionPhaseTask);

}

void loop() {
  scheduler.schedule();
}
