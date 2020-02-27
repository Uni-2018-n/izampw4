#include <iostream>
using namespace std;
#include "GameBoard.hpp"
int main(){
  GameBoard game(3);
  game.initializeGameBoard();
  game.gamePlay();
  return 0;
}
