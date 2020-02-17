#include <iostream>
#include "game.h"


GameControl::~GameControl(){
}


int GameControl::PlayGame(){
  ClearScreen();
  board.Print();
  
  while (!GameOver()){

  }
}

int GameControl::Menu(){
  std::cout << "********************************\n";
  std::cout << "Welcome to Greedy Snake Game!\n";
  std::cout << "1). Start the game\n";
  std::cout << "2). Exit the game\n";
  std::cout << "********************************\n";
  std::cout << "Enter your choice and press return: ";
  char choice;
  std::cin >> choice;
  do{
    switch (choice)
    {
    case '1':
      return 1;
    case '2':
      return 2;
    default:
      std::cin.clear();
      std::cout << "Not a Valid Choice. \n";
      std::cout << "Choose again.\n";
      std::cin >> choice;
      break;
    }
  }while (choice != '1' || choice != '2');


}

void GameControl::Game(){
    int choice = Menu();
    switch (choice)
      {
      case 1:
        PlayGame();
        break;
      case 2:
        break;
      }

}

bool GameControl::GameOver(){
  if (board.HitWall()){
    return true;
  }
  if (board.HitSnake()){
    return true;
  }
  return false;
}

void GameControl::ClearScreen(){
  //https://stackoverflow.com/questions/35813318/how-to-refresh-terminal-page-in-c
  //Thomas Dickey
  std::cout << "\033[2J\033[H";
}

int main(){
  GameControl gsnake;
  gsnake.Game();
}
