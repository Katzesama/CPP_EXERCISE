#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include <list>
#include "point.h"


extern enum direction{up, down, left, right};

class Snake{
public:
  Snake();
  ~Snake();
  void Move();
  void Grow();
  bool ChangeDirection(const char d);
  bool Eat();
  void InitialSnake(const int x, const int y);
  Point& getHead() { return this->head; }
  std::list<Point>& getbody(){ return this->body; }
private:
  direction direct;
  std::list<Point> body;
  Point head;
};

#endif
