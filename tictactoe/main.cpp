//http://www.cplusplus.com/forum/articles/12974/
//Tic Tac Toe
//Requires:
//variables, data types, and numerical operators
//basic input/output
//logic (if statements, switch statements)
//loops (for, while, do-while)
//arrays

//Make a two player tic tac toe game.

//★ Modify the program so that it will announce when a player has won the game (and which player won, x or o)

//★★ Modify the program so that it is a one player game against the computer (with the computer making its moves randomly)

//★★★★ Modify the program so that anytime the player is about to win (aka, they have 2 of 3 x's in a row, the computer will block w/ an o)

#include <iostream>
#include "tictactoe.hpp"

int main(){
  Board a_board;
  // std::cout << "Would you like to play with another player or computer?";
  // std::cout << "Please enter your choice (c for computer, p for 2nd player):;"
  Player player1('o');
  Player player2('x');
  /*while(true){
    std::cout << "First player will be \"o\"  and the second player will be \"x\"";
    a_board.display_board();
  }*/
  return 0;
}
