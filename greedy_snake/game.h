#ifndef GAME_H
#define GAME_H
#include "map.h"

class GameControl{
public:
  GameControl(){}
  ~GameControl();
  int PlayGame();
  int Menu();
  void Game();
  bool GameOver();
  void ClearScreen();
private:
  char key;
  Map board;
};

#endif
