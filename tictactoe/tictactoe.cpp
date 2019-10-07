#include <iostream>
#include "tictactoe.hpp"
#define board_dim 3

Board::Board(){
  clear_board();
}

Board::mark_atile(int board_index, char pmarker){
  int i = board_index - 1;
  char board_tile = board[i / board_dim][i % board_dim];
  //oops! occupied
  if ( board_tile == "x" or board_tile == "o"){
    return false;
  }
  else{
    board[i / board_dim][i % board_dim] = pmarker;
    filled += 1;
    return true;
  }
}

Board::clear_board(){
  for (int i = 0; i < board_dim*board_dim; i++){
    board[i / board_dim][i % board_dim] = '1' + i;
  }
  filled = 0;
}

Board::display_board(){
  for (int i = 0; i < board_dim; i++){
    for (int j = 0; j < board_dim; j++)
    {
      std::cout << board[i][j] << "  " ;
    }
    std::cout << "\n";
  }
}

Board::get_tile_mark(int row, int col){
  return board[row][col];
}

Board::is_full(){
  if (filled >= board_dim * board_dim){
    return true;
  }
  return false;
}

Board::~Board(){

}

Player::Player(char new_marker){
  marker = new_marker;
}

Player::get_marker(){
  return marker;
}

Player::~Player(){

}

Tictactoe::Tictactoe(){
    reset();
}

//bool
Tictactoe::is_win(Board &board){
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
Tictactoe::is_tie(Board &board){
  if (winner == 'n' && board.is_full()){
    return true;
  }
  return false;
}

//bool
Tictactoe::play_again(){

}

Tictactoe::get_winner(){
  return winner;
}

Tictactoe::reset(){
  winner = "n";
}

Tictactoe::~Tictactoe(){

}

//int
Computer_player::int play_random(){}
//int
Computer_player::play_smart(){}

Computer_player::Computer_player(){}
Computer_player::set_level(int setNaive){}
Computer_player::get_level(){}
Computer_player::~Computer_player(){}
