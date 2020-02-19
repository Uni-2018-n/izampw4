#include "GameBoard.hpp"
using namespace std;

GameBoard::GameBoard(int countOfP){
  countOfPlayers=countOfP;
  cout<<"Constructor for GameBoard called"<<endl;
}
GameBoard::~GameBoard(){
  cout<<"End my misery"<<endl;
}

void GameBoard::initializeGameBoard(){
  DeckBuilder *deck=new DeckBuilder();
  int counter;
  players=new list<Player*>();
  for(counter=0;counter<countOfPlayers;counter++){
    players->push_back(new Player(*deck));
  }
  //TODO orismos plithos diaforon katigorion


}

void GameBoard::printGameStatistics(){
  list<Player *>::iterator it;
  for(it = players->begin(); it != players->end(); it++){
      (*it)->printCurrState();
      cout<<endl;
    }

  }

void GameBoard::gamePlay(){
  cout<<"Prepare your anus for the game to start"<<endl;
  players->sort();
  starterPhase();

}


/////////////////////////////////////////Starter Phase
void GameBoard::starterPhase(){
  list<Player*>::iterator it;
  for(it = players->begin(); it != players->end(); it++){
    (*it)->untapEverything();
    (*it)->drawFateCard();
    (*it)->revealProvinces();
    (*it)->printCurrState();

    cout << endl;
  }
}
