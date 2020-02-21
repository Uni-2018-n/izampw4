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
  cout << "######################STARTER PHASE#########################"<< endl;
  starterPhase();

  cout << endl<<endl;

  cout << "######################EQUIP PHASE#########################"<< endl;
  equipPhase();

  cout << "######################BATTLE PHASE#########################"<< endl;
  battlePhase();

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
      cout<<"Choose card to buy or enter 7 to NOT buy any cards: ";
      cin >> inputHand;
      while(inputHand > (*it)->getCurrHandPl() && inputHand != 7){//TODO get currHand cardPl
        cout << "try again: ";
        cin >> inputHand;
      }
      switch(inputHand){
        case 7:
        cout<<"You did not buy any cards"<<endl;
        break;
        default:
          cout << "give input about Personality: ";
          cin >> inputArmy;
          while(inputArmy > (*it)->getCountOfPlayedPersonalityCards()){
            cout << "try again: ";
            cin >> inputArmy;
          }
          (*it)->equipCardToArmy(inputHand, inputArmy);
          break;
      }
    }else{
      cout << "No Personalities in the board, equipPhase skiped" << endl;
    }
    cout << endl;
  }
}

/////////////////////////////////////////Battle Phase
void GameBoard::battlePhase(){
  int atDefInput;
  list<Player*>::iterator it;
  for(it=players->begin(); it != players->end(); it++){
    cout << "Do you want to attack or defense this round attack=1/defense=0: ";
    cin >> atDefInput;
    list<Personality*>* currPlPersonality= (*it)->getPlayedPersonalityCards();
    {
      cout << "---Your Personalities: " << endl;
      list<Personality*>::iterator it;
      for(it=currPlPersonality->begin(); it != currPlPersonality->end(); it++){
        (*it)->printStats();
      }
    }

    {
      list<Player*>::iterator it2;
      int count=0;
      for(it2=players->begin(); it2 != players->end(); it2++){
        if(it2 != it){
          cout << "Player " << count << ": " << endl;
          (*it)->printOptionsByEnemys();
        }
        count++;
      }
    }


    if(atDefInput){//attack mode

    }else{//defense mode

    }
  }
}
