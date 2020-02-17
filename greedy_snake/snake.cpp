#include <iostream>
#include "snake.h"

#define SLENGTH 2

Snake::Snake(){
  direct = left;
}

Snake::~Snake(){

}

void Snake::Move(){

}

bool Snake::ChangeDirection(const char d){

}


bool Snake::Eat(){

}

void Snake::Grow(){

}

void Snake::InitialSnake(const int x, const int y){
  head.ChangePosition(x, y);
  for (int i = 1; i <= SLENGTH; i++){
    body.push_back(Point(x, y+i));
  }
}
