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
  cout<<"-_-_-_-_-_Game is Starting-_-_-_-_-_"<<endl;
  players->sort();
  cout << "######################STARTER PHASE#########################"<< endl;
  starterPhase();

  cout << endl<<endl;

  cout << "######################EQUIP PHASE#########################"<< endl;
  equipPhase();

  cout << "######################BATTLE PHASE#########################"<< endl;
  battlePhase();

  cout << "######################ECONOMY PHASE#########################"<< endl;
  economyPhase();

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
      do{
        (*it)->printOptions();
        cout<<"Choose card to buy or enter 7 to NOT buy any cards: ";
        cin >> inputHand;
        while(inputHand < 0 || (inputHand > (*it)->getCurrHandPl()-1 && inputHand != 7)){
          cout << "try again: ";
          cin >> inputHand;
        }
        if(inputHand == 7){
          cout<<"You did not buy any cards"<<endl;
          break;
        }else{
          cout << "give input about Personality: ";
          cin >> inputArmy;
          while(inputArmy < 0 || inputArmy > (*it)->getCountOfPlayedPersonalityCards()-1){
            cout << "try again: ";
            cin >> inputArmy;
          }
          (*it)->equipCardToArmy(inputHand, inputArmy);
        }
      }while(true);
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

  list<Player*>::iterator currPlayer;
  for(currPlayer=players->begin(); currPlayer != players->end(); currPlayer++){


    if((*currPlayer)->getCountOfPlayedPersonalityCards() >0){
      cout << "Do you want to attack or defend this round attack=1/defense=0: ";
      cin >> atDefInput;
      while(atDefInput != 0 && atDefInput != 1){
        cout << "Try again: ";
        cin >> atDefInput;
      }
      if(atDefInput){//attack mode
        list<Personality*>* attackingPersonalityCards= new list<Personality*>();//kartes pou tha xrisimopoithoun gia attack se ena province
        list<Personality*>* currPersonalities= (*currPlayer)->getPlayedPersonalityCards();
        {//print currPlayers personalities
          int currPersonalityCount=0;
          cout << "---Your Personalities: " << endl;

          list<Personality*>::iterator it;
          for(it=currPersonalities->begin(); it != currPersonalities->end(); it++){
            cout << currPersonalityCount << ": ";
            (*it)->printStats();
            currPersonalityCount++;
          }
          cout << endl << endl;
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
        cout << "Choose Enemy to attack: ";//choose enemy
        int currEnemyI;
        cin >> currEnemyI;//get Index of Enemy Player
        while(currEnemyI < 0 || currEnemyI > countOfPlayers-1 || currEnemyI == currPlayerI){
          cout << "Try again: ";
          cin >> currEnemyI;
        }
        list<Player*>::iterator currEnemy;
        {
          int count=0;
          for(currEnemy= players->begin(); currEnemy != players->end(); currEnemy++){
            if(count == currEnemyI){
              break;//an mpeis edw tote to currEnemy einai o enemy poy 8eloume na epite8oume
            }
            count++;
          }
        }//from here currEnemy is our attacking enemy


        cout << "Choose Enemy's province to attack: ";//choose province to attack
        int currEnemyProvinceI;
        cin >> currEnemyProvinceI;//get Index of Enemy's province
        while(currEnemyProvinceI < 0 || currEnemyProvinceI > (*currEnemy)->getCountOfProvinces()-1){
          cout << "Try again: ";
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
        }//from here currEnemyProvince is our attacking province

        int totalDefense=0;
        //totalDefense=(*currEnemyProvince)->getDefense();//gia na prostheso meta mono ta defense ton paikton
        {
          list<Personality*>::iterator it;
          for(it=(*currEnemyProvince)->getDefendingCards()->begin();it!=(*currEnemyProvince)->getDefendingCards()->end();it++){
            totalDefense +=(*it)->getDefense();
          }
        }//from here totalDefense has the full defense of the province


        int currPersonalityI;
        cout << "Choose Personality to attack: ";
        cin >> currPersonalityI;//pare to index
        while(true){
          bool currPersonalityIsTapped= true;

          list<Personality*>::iterator currPersonality;//get currPlayer's selected Personality Card
          {
            int count;
            list<Personality*>* temp= (*currPlayer)->getPlayedPersonalityCards();
            do{
              while(currPersonalityI < -1 ||  currPersonalityI >= (*currPlayer)->getCountOfPlayedPersonalityCards()){
                cout << "Try again: ";
                cin >> currPersonalityI;
              }
              if(currPersonalityI != -1){
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
                  cout << "Personality Card Is Tapped Please Choose Another Card: ";
                  cin >> currPersonalityI;
                }
              }else{
                if(attackingPersonalityCards->size() == 0){
                  currPersonalityIsTapped = true;
                  cout << "Try again: ";
                  cin >> currPersonalityI;
                }else{
                  currPersonalityIsTapped = false;
                }
              }
            }while(currPersonalityIsTapped);//if yes repeat the prossess for a diffrent personality card

            if(currPersonalityI == -1){
              break;
            }

            attackingPersonalityCards->push_back((*currPersonality));
            (*currPlayer)->getPlayedPersonalityCards()->erase(currPersonality);//tis diagrafo oste ama pethanoun na min prepei na tis diagrafo kai apo tis dio listes kai ama epiviosoun tis ksanaantigrafo

            {//print currPlayers personalities
              int currPersonalityCount=0;
              cout << "---Your Personalities: " << endl;

              list<Personality*>::iterator it;
              for(it=currPersonalities->begin(); it != currPersonalities->end(); it++){
                cout << currPersonalityCount << ": ";
                (*it)->printStats();
                currPersonalityCount++;
              }
              cout << endl << endl;
            }

            cout << "Choose another Personality to attack (-1 to stop): ";
            cin >> currPersonalityI;
            if(currPersonalityI == -1){
              cout << "Choosing done" << endl;
              break;
            }
          }
        }//apo edw kai katw exoyme mia lista thn attackingPersonalityCards h opoia exei oles tis kartes poy 8eloume na epite8oume sto syggekrimeno Province

        int totalAttack=0;
        {
          list<Personality*>::iterator it;
          for(it= attackingPersonalityCards->begin(); it != attackingPersonalityCards->end(); it++){
            totalAttack += (*it)->getAttack();
          }
        }//from here exoume to full attack power apo ola ta personality cards mazemena

        //HERE START ATTACKING OPTIONS
        if(totalAttack-totalDefense>((*currEnemyProvince)->getDefense())){//1i periptosi, thelo mono attack prosopikotiton  meion defense aminas kai prosopikotiton
          (*currEnemy)->destroyCards(*currEnemyProvince);
          (*currEnemy)->destroyProvince(currEnemyProvinceI);
        }else if(totalAttack>totalDefense){
          (*currEnemy)->destroyCards(*currEnemyProvince);
          {
            list<Personality*>::iterator it;
            for(it= attackingPersonalityCards->begin(); it != attackingPersonalityCards->end(); it++){
              if((totalAttack-totalDefense)<(*it)->getAttack()){
                attackingPersonalityCards->erase(it);
              }else{
                (*it)->reduceHonor();
              }
            }
          }
          //TODO oses epiviosoun na tis ksanavalo sto playedPersonalityCards
        }else if(totalAttack==totalDefense){
          (*currEnemy)->destroyCards(*currEnemyProvince);
          {
            list<Personality*>::iterator it;
            for(it= attackingPersonalityCards->begin(); it != attackingPersonalityCards->end(); it++){//gia na pethanoun oles oi kartes epithesis
              attackingPersonalityCards->erase(it);
            }
          }
        }else{
          {
            list<Personality*>::iterator it;
            for(it= attackingPersonalityCards->begin(); it != attackingPersonalityCards->end(); it++)//gia na pethanoun oles oi kartes epithesis
            attackingPersonalityCards->erase(it);
          }

          {
            list<Personality*>::iterator it;
            for(it= (*currEnemyProvince)->getDefendingCards()->begin(); it != (*currEnemyProvince)->getDefendingCards()->end(); it++){//gia na pethanoun oles oi kartes epithesis
              if((totalDefense-totalAttack)<(*it)->getAttack()){
                (*currEnemyProvince)->getDefendingCards()->erase(it);
              }else{
                (*it)->reduceHonor();
              }
            }
          }
        }

        {
          //adding cards that survived back to played personality cards
          list<Personality*>::iterator it;
          for(it= attackingPersonalityCards->begin(); it != attackingPersonalityCards->end(); it++){//gia na pethanoun oles oi kartes epithesis
            (*it)->setIsTapped(true);
            if((*it)->getPossibleItem() != NULL){
              (*it)->getPossibleItem()->setDurability(((*it)->getPossibleItem()->getDurability()-1));
            }else if((*it)->getpossibleFollower()){
              (*it)->getpossibleFollower()->setIsTapped(true);
            }
            (*currPlayer)->getPlayedPersonalityCards()->push_back(*it);
          }
        }
      }else{//defense mode
        list<Personality*>* currPersonalities= (*currPlayer)->getPlayedPersonalityCards();
        {//print currPlayers personalities
          int currPersonalityCount=0;
          cout << "---Your Personalities: " << endl;

          list<Personality*>::iterator it;
          for(it=currPersonalities->begin(); it != currPersonalities->end(); it++){
            cout << currPersonalityCount << ": ";
            (*it)->printStats();
            currPersonalityCount++;
          }
          cout << endl << endl;
        }

        list<Provinces*>* currProvinces = (*currPlayer)->getProvinces();
        {//print currPlayer's provinces
          int currProvinceCount = 0;
          cout << "---Your Provinces: " << endl;
          list<Provinces*>::iterator it;
          for(it=currProvinces->begin(); it != currProvinces->end(); it++){
            cout << currProvinceCount << ": ";
            (*it)->print();
            currProvinceCount++;
          }
          cout << endl << endl;
        }

        cout << "Choose province to defend: ";
        int currProvinceI;
        cin >> currProvinceI;//get Index of province
        while(currProvinceI < 0 ||  currProvinceI > (*currPlayer)->getCountOfProvinces()-1){
          cout << "Try again: ";
          cin >> currProvinceI;
        }
        list<Provinces*>::iterator currProvince;
        {
          int count=0;
          list<Provinces*>* temp= (*currPlayer)->getProvinces();
          for(currProvince= temp->begin(); currProvince != temp->end(); currProvince++){
            if(currProvinceI == count){
              break;//an mpeis edw tote to currProvince einai to province poy 8eloume na kanoume defense
            }else{
              count++;
            }
          }
        }//from here currProvince is our defense province kai currProvinceI einai to index tou province

        int currPersonalityI;
        cout << "Choose Personality to defend: ";
        cin >> currPersonalityI;//pare to index
        while(true){
          bool currPersonalityIsTapped= true;

          list<Personality*>::iterator currPersonality;//get currPlayer's selected Personality Card
          {
            int count;
            // list<Personality*>* temp= (*currPlayer)->getPlayedPersonalityCards();
            do{
              while(currPersonalityI < -1 ||  currPersonalityI >= (*currPlayer)->getCountOfPlayedPersonalityCards()){
                cout << "Try again: ";
                cin >> currPersonalityI;
              }
              if(currPersonalityI != -1){
                count=0;
                for(currPersonality = currPersonalities->begin(); currPersonality != currPersonalities->end(); currPersonality++){
                  if(currPersonalityI == count){
                    break;//an mpeis edw tote to currPersonality exei thn personality poy 8eloyme
                  }else{
                    count++;
                  }
                }
                currPersonalityIsTapped = (*currPersonality)->getIsTapped();//check if card is tapped
                if(currPersonalityIsTapped){
                  cout << "Personality Card Is Tapped Please Choose Another Card: ";
                  cin >> currPersonalityI;
                }
              }else{
                if((*currProvince)->getDefendingCards()->size() == 0){
                  currPersonalityIsTapped = true;
                  cout << "Try again: ";
                  cin >> currPersonalityI;
                }else{
                  currPersonalityIsTapped = false;
                }
              }
            }while(currPersonalityIsTapped);//if yes repeat the prossess for a diffrent personality card
            //if you go here currPersonality is the personality the player wants
            if(currPersonalityI == -1){
              break;
            }
            (*currProvince)->getDefendingCards()->push_back(*currPersonality);
            (*currPlayer)->getPlayedPersonalityCards()->erase(currPersonality);

            {//print currPlayers personalities
              int currPersonalityCount=0;
              cout << "---Your Personalities: " << endl;

              list<Personality*>::iterator it;
              for(it=currPersonalities->begin(); it != currPersonalities->end(); it++){
                cout << currPersonalityCount << ": ";
                (*it)->printStats();
                currPersonalityCount++;
              }
              cout << endl << endl;
            }

            cout << "Choose another personality to defense? (-1 to stop): ";
            cin >> currPersonalityI;
            if(currPersonalityI == -1){
              cout << "Choosing done" << endl;
              break;
            }
          }
        }//apo edw kai katw exoyme mia lista thn (*currProvince)->defendingCards h opoia exei oles tis kartes poy 8eloume na kanoun defense sto syggekrimeno Province
        //currProvince, currProvince->defendingCards(list of the chosen personality cards)


        //performSeppuku
        list<Personality*>::iterator it;
        for(it=(*currPlayer)->getPlayedPersonalityCards()->begin(); it != (*currPlayer)->getPlayedPersonalityCards()->end(); it++){
          if((*it)->getHonor()==0){
            cout<<"I am about to do what is called a Pro Gamer Move. *commits suicide*"<<endl;
            (*currPlayer)->getPlayedPersonalityCards()->erase(it);
          }
        }
        //###########end of battle phase




      }
    }else{
      cout << "\t No personalities available! Battle Phase Skiped" << endl;
    }
  }
}

////////////////////////////economyPhase
// TODO molis agorazei mia karta na elegxei gia alisides
void GameBoard::economyPhase(){
  int inputBlack,inputGreen;
  list<Player*>::iterator currPlayer;

  for(currPlayer=players->begin(); currPlayer != players->end(); currPlayer++){
    while(true){
    (*currPlayer)->printBuyingOptionsBlack();
    do{
      cout<<"Choose card to buy or Enter[-1] to not buy any"<<endl;
      cin>>inputBlack;
    }while((inputBlack >=-1) && (inputBlack < (int)(*currPlayer)->getAvailableDynastyCards()->size()));//gia na min fame segmentation ama dosei noumero megalitero apo oti plithos karton exoume
    if(inputBlack==-1){
      break;//not breaking properly
    }
    else{

      //na afairei apo top of province,na metaferei sto played black card kai na travaei kainourgia unrevealed

    }//else

  }//while true


while(true){//for green cards
  (*currPlayer)->printBuyingOptionsGreen();
  do{
    cout<<"Choose card to buy or Enter[-1] to not buy any"<<endl;
    cin>>inputGreen;
  }while(inputGreen>=-1&&inputGreen<7);//TODO needs fixing. If user gives wrong input has segme
  if(inputGreen==-1){
    break;
  }
  else{
    //edo vale na antigrafei tin karta stin antistoixi played list
    (*currPlayer)->removeHandCard(inputGreen);
  }

}




}//for currplayer
}
