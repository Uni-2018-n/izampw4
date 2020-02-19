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
  cout << "STARTER PHASE"<< endl;
  starterPhase();

  cout << endl<<endl;

  cout << "EQUIP PHASE" <<endl;
  equipPhase();

  cout << endl<<endl;


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

/////////////////////////////////////////Equip Phase
void GameBoard::equipPhase(){
  int inputHand;
  int inputArmy;
  list<Player*>::iterator it;
  for(it = players->begin(); it != players->end(); it++){
    if((*it)->getCountOfPlayedPersonalityCards() > 0){
      (*it)->printOptions();
      cout<<"Choose card to buy or enter 7 to NOT buy any cards"<< endl;
      cin >> inputHand;
      while(inputHand > 7){
        cout << "try again" << endl;
        cin >> inputHand;
      }
      switch (inputHand) {
        case 7:
        cout<<"You did not buy any cards"<<endl;
        break;
        default:
          cout << "give input about Personality" << endl;
          cin >> inputArmy;
          //TODO make function connect personality with green card and check if greencard can be bought
          break;
      }


    }else{
      cout << "No Personalities in the board, equipPhase skiped" << endl;
    }

    cout << endl;
  }
}
