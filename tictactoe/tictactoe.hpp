#include <iostream>

#define board_dim 3

class Tictactoe{
char winner;
public:
  Tictactoe();
  bool is_win(Board &board, Player &player);
  bool is_tie(Board &board, Player &player);
  bool play_again();
  char get_winner();
  void reset();
  ~Tictactoe();
};

class Board{
  char board[board_dim][board_dim];
  int filled;
public:
  Board();
  // check valid move when change the tile
  bool mark_atile(int board_ibdex, char pmarker);
  void clear_board();
  void display_board();
  char get_tile_mark(int row, int col);
  bool is_full();
  //void get_empty_spot();
  ~Board();

};

class Player{
  char marker;

public:
  Player(char new_marker);
  char get_marker();
  ~Player();

};

class Computer_player{
  int ifNaive;
private:
  int play_random();
  int play_smart();

public:
  Computer_player();
  void set_level(int setNaive);
  int get_level();
  ~Computer_player();
};
