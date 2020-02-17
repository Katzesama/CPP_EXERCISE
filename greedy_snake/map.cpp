#include <iostream>
#include <list>
#include "map.h"

#define WIDTH 60
#define HEIGHT 30
#define BOARDER '*'
#define FOOD '@'
#define SNAKEPOINT 'o'



Map::Map(){
  height = HEIGHT;
  width = WIDTH;
  map = new char *[height];
  for(int i=0; i < height; i++){
    map[i] = new char[width];
  }
  int positionx = (int) height/2;
  int positiony = (int) width/2;
  snake.InitialSnake(positionx, positiony);
  food.ChangePosition(positionx, positiony - 3);
  SetBoarder();
  SetPoints();

}

Map::~Map(){
  for (int i = 0; i < height; i++) {
        delete [] map[i];
    }
    delete [] map;
}

void Map::SetPoints(){
  for (int i = 1; i < height-1; i++) {
        for (int j = 1; j < width-1; j++)
            map[i][j] = ' ';
  }
  map[food.GetX()][food.GetY()] = FOOD;

  Point head = snake.getHead();
  map[head.GetX()][head.GetY()] = SNAKEPOINT;
  //https://thispointer.com/c-different-ways-to-iterate-over-a-list-of-objects/
  for (std::list<Point>::iterator sbody = snake.getbody().begin(); sbody != snake.getbody().end(); sbody++)
{
	map[sbody->GetX()][sbody->GetY()] = SNAKEPOINT;
}
}

void Map::MoveSnake(const direction d){

}

void Map::Print(){
  for (int i = 0; i < height; i++){
    for (int j = 0; j < width; j++)
    {
      std::cout << map[i][j];
    }
    std::cout << "\n";
  }
}

bool Map::HitWall(){
  Point head = snake.getHead();
  return map[head.GetX()][head.GetY()] == BOARDER;
}

bool Map::HitSnake(){
  
}

void Map::SetBoarder(){
  for (int j = 0; j < width; j++){
      map[0][j] = BOARDER;
  }
  for (int j = 0; j < width; j++){
      map[height-1][j] = BOARDER;
  }
  for (int i = 0; i < height; i++){
      map[i][0] = BOARDER;
  }
  for (int i = 0; i < height; i++){
      map[i][width-1] = BOARDER;
  }
}
