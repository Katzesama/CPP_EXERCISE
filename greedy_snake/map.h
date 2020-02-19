#ifndef MAP_H
#define MAP_H
#include <iostream>
#include "snake.h"
#include "point.h"

class Map{
public:
  Map();
  ~Map();
  void SetPoints();
  void MoveSnake(char key);
  void Print();
  bool is_Eat();
  bool HitWallorSnake();
  void SetBoarder();
private:
  char** map;
  Snake snake;
  int height, width;
  Point food;
};

#endif
