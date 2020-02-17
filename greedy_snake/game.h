#ifndef GAME_H
#define GAME_H
#include "map.h"

class GameControl{
public:
  GameControl(){}
  ~GameControl();
  void GameStart();
  int PlayGame();
  int Menu();
  void Game();
  int GameOver();
  void ClearScreen();
private:
  int key;
  Map board;
};

#endif
