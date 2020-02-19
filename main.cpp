#include <iostream>
using namespace std;
#include "givenFiles/DeckBuilder.hpp"
#include "GameBoard.hpp"
// TODO psarros , destructor minimata,cout ta apeira define tis izambos sto printGameStatistics
//TODO 2.2, 2.4(deyterh par)
int main(){
  GameBoard game(3);
  game.initializeGameBoard();
  game.gamePlay();
  return 0;
}
//TODO #STAMATISAME EDO# na sindesoume personalities me kartes
