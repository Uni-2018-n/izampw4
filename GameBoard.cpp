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
  int currPlayerI;
  int playerIndex=0;

  list<Player*>::iterator currPlayer;
  for(currPlayer=players->begin(); currPlayer != players->end(); currPlayer++){
    cout << "Player " << playerIndex << ":" << endl;
    if((*currPlayer)->getCountOfPlayedPersonalityCards() >0){
      list<Personality*>* currPersonalities;
      currPersonalities= (*currPlayer)->getPlayedPersonalityCards();
      {//print currPlayers personalities
        int currPersonalityCount=0;
        cout << "---Your Personalities: " << endl;

        list<Personality*>::iterator it;
        for(it=currPersonalities->begin(); it != currPersonalities->end(); it++){
          cout << currPersonalityCount << ": ";
          (*it)->printStats();
          currPersonalityCount++;
        }
      }

      {//print Provinces of players except currPlayer
        list<Player*>::iterator it;
        int count=0;
        for(it=players->begin(); it != players->end(); it++){
          if(it != currPlayer){
            cout << "Player " << count << ": " << endl;
            (*it)->printOptionsByEnemys();
          }else{
            currPlayerI=count;
          }
          count++;
        }
      }

      cout << "Do you want to attack or defend this round attack=1/defense=0: ";
      cin >> atDefInput;
      if(atDefInput){//attack mode
        int currPersonalityI;
        bool currPersonalityIsTapped= true;

        list<Personality*>::iterator currPersonality;//get currPlayer's selected Personality Card
        {
          int count;
          list<Personality*>* temp= (*currPlayer)->getPlayedPersonalityCards();
          cout << "Choose Personality to attack: ";
          do{
            cin >> currPersonalityI;//pare to index
            while(currPersonalityI > (*currPlayer)->getCountOfPlayedPersonalityCards()){
              cout << "try again: ";
              cin >> currPersonalityI;
            }
            count=0;
            for(currPersonality = temp->begin(); currPersonality != temp->end(); currPersonality++){
              if(currPersonalityI == count){
                break;//an mpeis edw tote to currPersonality exei thn personality poy 8eloyme
              }else{
                count++;
              }
            }
            currPersonalityIsTapped = (*currPersonality)->getIsTapped();//check if card is tapped
            if(currPersonalityIsTapped){
              cout << "Personality Card Is Tapped Please Choose An Other Card: ";
            }
          }while(currPersonalityIsTapped);//if yes repeat the prossess for a diffrent personality card
        }


        cout << "Choose Enemy to attack: ";
        int currEnemy;
        cin >> currEnemy;//get Index of Enemy Player
        while(currEnemy > countOfPlayers-1 || currEnemy == currPlayerI){
          cout << "try again: ";
          cin >> currEnemy;
        }
        list<Player*>::iterator enemyPlayer;
        {
          int count=0;
          for(enemyPlayer= players->begin(); enemyPlayer != players->end(); enemyPlayer++){
            if(count == currEnemy){
              break;//an mpeis edw tote to enemyPlayer einai o enemy poy 8eloume na epite8oume
            }
            count++;
          }
        }


        cout << "Choose Enemy's province to attack: ";
        int currEnemyProvinceI;
        cin >> currEnemyProvinceI;//get Index of Enemy's province
        while(currEnemyProvinceI > (*enemyPlayer)->getCountOfProvinces()-1){
          cout << "try again: ";
          cin >> currEnemyProvinceI;
        }
        list<Provinces*>::iterator currEnemyProvince;
        {
          int count=0;
          list<Provinces*>* temp= (*currPlayer)->getProvinces();
          for(currEnemyProvince= temp->begin(); currEnemyProvince != temp->end(); currEnemyProvince++){
            if(currEnemyProvinceI == count){
              break;//an mpeis edw tote to currEnemyProvince einai to province poy 8eloume na epite8oume
            }else{
              count++;
            }
          }
        }
        //currPersonality(to personality poy 8elei na epite8ei o paikths), enemyPlayer(o antipalos poy 8elei na epite8ei o paikths), currEnemyProvince(to province poy 8elei na epite8ei o paikths)



      }else{//defense mode

      }




    }else{
      cout << "\t No personalities available Battle Phase Skiped" << endl;
    }
    playerIndex++;
  }
}
