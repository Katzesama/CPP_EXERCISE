#include <iostream>
#include "point.h"

Point::Point(const int x, const int y){
  this->x = x;
  this->y = y;
}

void Point::ChangePosition(const int x, const int y){
  this->x = x;
  this->y = y;
}

Point::~Point(){

}
