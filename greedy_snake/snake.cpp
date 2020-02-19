#include <iostream>
#include "snake.h"

#define SLENGTH 2

Snake::Snake(){
  direct = left;
}

Snake::~Snake(){

}

Point Snake::Move(){
  int pointx, pointy;
  pointx = head.GetX();
  pointy = head.GetY();
  int tempx = pointx;
  int tempy = pointy;
  switch(direct){
    case up:
      pointx -= 1;
      break;
    case down:
      pointx += 1;
      break;
    case left:
      pointy -= 1;
      break;
    case right:
      pointy += 1;
      break;
  }
  head.ChangePosition(pointx, pointy);
  pointx = tempx;
  pointy = tempy;
  for(std::list<Point>::iterator bo = body.begin(); bo != body.end(); bo++){
    tempx = bo->GetX();
    tempy = bo->GetY();
    bo->ChangePosition(pointx, pointy);
    pointx = tempx;
    pointy = tempy;
  }

  return Point(pointx, pointy);

}

bool Snake::ChangeDirection(const char d){
  switch(d){
    case 'w':
    case 'W':
      if (direct != down){
        direct = up;
      }
      break;
    case 's':
    case 'S':
      if (direct != up){
        direct = down;
      }
      break;
    case 'a':
    case 'A':
      if (direct != right){
        direct = left;
      }
      break;
    case 'd':
    case 'D':
      if (direct != left){
        direct = right;
        std::cout << direct << '\n';
      }
      break;
  }
  return true;
}


bool Snake::Eat(Point food){
  if (head == food){return true;}
  return false;
}

void Snake::Grow(Point growth){
  body.push_back(growth);
}

void Snake::InitialSnake(const int x, const int y){
  head.ChangePosition(x, y);
  for (int i = 1; i <= SLENGTH; i++){
    body.push_back(Point(x, y+i));
  }
}
