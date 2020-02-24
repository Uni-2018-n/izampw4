#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_
#include "givenFiles/DeckBuilder.hpp"
#include "Player.hpp"

class GameBoard{
private:
  list<Player*>* players;
  int countOfPlayers;
  void starterPhase();
  void equipPhase();
  void battlePhase();
  void economyPhase();
  int checkWinningCondition();

public:
  GameBoard(int countOfP);
  ~GameBoard();
  void initializeGameBoard();
  void printGameStatistics();
  void gamePlay();
};
#endif
