#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_
#include "givenFiles/DeckBuilder.hpp"
#include "Player.hpp"

class GameBoard{
private:
  list<Player*>* players;
  int countOfPlayers;

  void printArena();
  void starterPhase();
  void equipPhase();
  void battlePhase();
  void economyPhase();
  void checkWinningCondition();
  
public:
  GameBoard(int countOfP);
  ~GameBoard();
  void initializeGameBoard();
  void gamePlay();
};
#endif
