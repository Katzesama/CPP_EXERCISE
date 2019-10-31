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
#include <list>

int main(){
  Board a_board;
  Tictactoe tttgame;
  // std::cout << "Would you like to play with another player or computer?";
  // std::cout << "Please enter your choice (c for computer, p for 2nd player):;"
  Player player1('o');
  Player player2('x');
  char currentplayer = player1.get_marker();
  std::cout << "First player will be \"o\"  and the second player will be \"x\".\n";
  std::cout << "Here is the board: \n";
  while(true){
    a_board.display_board();
    int move;
    std::cout << "Please make your move(by entering 1~9): ";
    try{
      std::cin >> move;
    }
    catch(...){
      std::cout << "You entered an invalid value, please try again.\n";
      continue;
    }
    if(a_board.mark_atile(move, currentplayer)){
      if (tttgame.is_win(a_board)){
        std::cout << "Winner is " << tttgame.get_winner() << "!\n";
        if (tttgame.play_again()){
          tttgame.reset();
          a_board.clear_board();
          currentplayer = player1.get_marker();
          continue;
        }
        break;
      }
      else if(tttgame.is_tie(a_board)){
        std::cout << "Game ends. It is a tie.\n";
        if (tttgame.play_again()){
          tttgame.reset();
          a_board.clear_board();
          currentplayer = player1.get_marker();
          continue;
        }
        break;
      }
      if (currentplayer == 'x'){
        currentplayer = 'o';
      }
      else{
        currentplayer = 'x';
      }
    }
    else{
      continue;
    }

  }
  return 0;
}
