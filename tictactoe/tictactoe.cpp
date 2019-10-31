#include <iostream>
#include "tictactoe.hpp"
#define board_dim 3

Board::Board(){
  clear_board();
}

Board::~Board(){

}

bool Board::mark_atile(int board_index, char pmarker){
  //validate the input
  if ( board_index >= 10 || board_index <= 0 ){
    std::cout << "The number you entered is out of range.\n";
    std::cout << "Pleas try again.\n";
    return false;
  }
  int i = board_index - 1;
  char board_tile = board[i / board_dim][i % board_dim];
  //oops! occupied
  if ( board_tile == 'x' or board_tile == 'o'){
    std::cout << "Occupied!";
    return false;
  }
  else{
    board[i / board_dim][i % board_dim] = pmarker;
    filled += 1;
    return true;
  }
}

void Board::clear_board(){
  for (int i = 0; i < board_dim*board_dim; i++){
    board[i / board_dim][i % board_dim] = '1' + i;
  }
  filled = 0;
}

void Board::display_board(){
  for (int i = 0; i < board_dim; i++){
    for (int j = 0; j < board_dim; j++)
    {
      std::cout << board[i][j] << "  " ;
    }
    std::cout << "\n";
  }
}

char Board::get_tile_mark(int row, int col){
  return board[row][col];
}

bool Board::is_full(){
  if (filled >= board_dim * board_dim){
    return true;
  }
  return false;
}


Player::Player(char new_marker){
  marker = new_marker;
}

Player::~Player(){

}

char Player::get_marker(){
  return marker;
}



Tictactoe::Tictactoe(){
    reset();
}

Tictactoe::~Tictactoe(){

}

//bool
bool Tictactoe::is_win(Board &board){
  //horizontal
  for (int i = 0; i < board_dim; i++){
    if (board.get_tile_mark(i, 0) == board.get_tile_mark(i, 1) && board.get_tile_mark(i, 1) == board.get_tile_mark(i, 2)){
      winner = board.get_tile_mark(i, 0);
      return true;
    }
  }
  //vertical
  for (int i = 0; i < board_dim; i++){
    if (board.get_tile_mark(0, i) == board.get_tile_mark(1, i) && board.get_tile_mark(1, i) == board.get_tile_mark(2, i)){
      winner = board.get_tile_mark(0, i);
      return true;
    }
  }
  //diagnol
  if (board.get_tile_mark(0, 0) == board.get_tile_mark(1, 1) && board.get_tile_mark(1, 1) == board.get_tile_mark(2, 2)){
    winner = board.get_tile_mark(0, 0);
    return true;
  }
  if (board.get_tile_mark(2, 0) == board.get_tile_mark(1, 1) && board.get_tile_mark(1, 1) == board.get_tile_mark(0, 2)){
    winner = board.get_tile_mark(2, 0);
    return true;
  }

  //no winner
  return false;
}

//bool
bool Tictactoe::is_tie(Board &board){
  if (winner == 'n' && board.is_full()){
    return true;
  }
  return false;
}

//bool
bool Tictactoe::play_again(){
  std::string again;
  while (true){
    std::cout << "Do you want to play again?(y or n):";
    std::cin >> again;
    if (again == "y"){
      return true;
    }
    else if(again == "n"){
      return false;
    }
    std::cout << "Wrong input value!\n";
  }
}

char Tictactoe::get_winner(){
  return winner;
}

void Tictactoe::reset(){
  winner = 'n';
}

/*
//int
Computer_player::int play_random(){}
//int
Computer_player::play_smart(){}

Computer_player::Computer_player(){}
Computer_player::set_level(int setNaive){}
Computer_player::get_level(){}
Computer_player::~Computer_player(){}
*/
