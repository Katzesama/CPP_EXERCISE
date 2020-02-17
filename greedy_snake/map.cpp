#include <iostream>
#include "map.h"

#define WIDTH 60
#define HEIGHT 30
#define BOARDER '*'



Map::Map(){
  height = HEIGHT;
  width = WIDTH;
  map = new char *[height];
  for(int i=0; i < height; i++){
    map[i] = new char[width];
  }
  for (int i = 0; i < height; i++){
    for (int j = 0; j < width; j++)
    {
      map[i][j] = ' ';
    }
  }
  int positionx = (int) width/2;
  int positiony = (int) height/2;
  snake.SetHead(positionx, positiony);
  SetBoarder();

}

Map::~Map(){
  for (int i = 0; i < height; i++) {
        delete [] map[i];
    }
    delete [] map;
}

void Map::MoveSnake(){

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
