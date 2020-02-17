#ifndef MAP_H
#define MAP_H
#include <iostream>
#include "snake.h"
#include "point.h"

class Map{
public:
  Map();
  ~Map();
  void MoveSnake();
  void Print();
  bool HitWall();
  void SetBoarder();
private:
  char** map;
  Snake snake;
  int height, width;
  Point food;
};

#endif
