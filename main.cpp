#include <iostream>
using namespace std;
#include "givenFiles/DeckBuilder.hpp"
#include "GameBoard.hpp"
// TODO psarros , destructor minimata,cout ta apeira define tis izambos sto printGameStatistics
//TODO 1.1, 2.2
int main(){

GameBoard game(3);
game.initializeGameBoard();
game.gamePlay();

}
