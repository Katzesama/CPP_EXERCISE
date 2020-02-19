#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include <list>
#include "point.h"


enum direction{up, down, left, right};

class Snake{
public:
  Snake();
  ~Snake();
  Point Move();
  void Grow(Point growth);
  bool ChangeDirection(const char d);
  bool Eat(Point food);
  void InitialSnake(const int x, const int y);
  Point& getHead() { return this->head; }
  std::list<Point>& getbody(){ return this->body; }
private:
  direction direct;
  std::list<Point> body;
  Point head;
};

#endif
