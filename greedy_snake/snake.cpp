#include <iostream>
#include "snake.h"


Snake::Snake(){
  direct = left;
}

Snake::~Snake(){

}

void Snake::Move(){

}

bool Snake::ChangeDirection(){

}

bool Snake::HitSelf(){

}

bool Snake::Eat(){

}

void Snake::SetHead(const int x, const int y){
  head.ChangePosition(x, y);
}
