#include "GameBoard.hpp"

using namespace std;

GameBoard::GameBoard(int countOfP){
  countOfPlayers=countOfP;
  cout<<"Constructor for GameBoard called"<<endl;
}

GameBoard::~GameBoard(){
  cout<<"End my misery"<<endl;
}

/////////////Prints
void GameBoard::printArena(){
  int count=0;
  list<Player*>::iterator it;
  for(it=players->begin();it != players->end(); it++){
    cout << "##Player " << count++ << ": " << endl;
    (*it)->printArmy();
    (*it)->printHoldings();
  }
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


void GameBoard::gamePlay(){
  cout<<"-_-_-_-_-_Game is Starting-_-_-_-_-_"<<endl;
  players->sort();

  while(countOfPlayers > 0){
    cout << "######################STARTER PHASE#########################"<< endl;
    starterPhase();

    cout << endl<<endl;

    cout << "######################EQUIP PHASE#########################"<< endl;
    equipPhase();

    cout << "######################BATTLE PHASE#########################"<< endl;
    battlePhase();

    cout << "######################ECONOMY PHASE#########################"<< endl;
    economyPhase();

    cout << "######################FINAL PHASE#########################"<< endl;
    cout << "//##//##//Arena//##//##//" << endl;
    printArena();
    cout << "//##//##//All statistics for players//##//##//" << endl;
    {//print printCurrState for players
      list<Player*>::iterator it;
      int count=0;
      for(it= players->begin(); it != players->end(); it++){
        cout << "###Player" << count++ << ": " << endl;
        (*it)->printCurrState();
        cout << endl;
      }
    }
    checkWinningCondition();

    cout << "######################ROUND DONE#########################"<< endl;
    cout << "Next Round(write anything)" << endl;
    getchar();
    getchar();
  }
  cout << "Game finished, winner player: " << endl;
  players->front()->printCurrState();
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
void GameBoard::equipPhase(){//users buy green cards from hand and use them in Army
  int inputHand;
  int inputArmy;
  list<Player*>::iterator it;
  for(it = players->begin(); it != players->end(); it++){
    if((*it)->getCountOfPlayedPersonalityCards() > 0){
      do{
        (*it)->printOptions();//print hand cards and army
        cout<<"Choose card to buy or enter 7 to NOT buy any cards: ";//get input from user
        cin >> inputHand;
        while(inputHand < 0 || (inputHand > (*it)->getCurrHandPl()-1 && inputHand != 7)){//fail safe
          cout << "try again: ";
          cin >> inputHand;
        }
        if(inputHand == 7){//if user dosent want to buy cards
          cout<<"You did not buy any cards"<<endl;
          break;
        }else{
          cout << "give input about Personality: ";//if user wants to buy a card, get input about personality
          cin >> inputArmy;
          while(inputArmy < 0 || inputArmy > (*it)->getCountOfPlayedPersonalityCards()-1){//fail safe
            cout << "try again: ";
            cin >> inputArmy;
          }
          (*it)->equipCardToArmy(inputHand, inputArmy);//equips green card to army card, also checks about money
        }
      }while(true);
    }else{
      cout << "No Personalities in the board, equipPhase skiped" << endl;
    }
    cout << endl;
  }
}

/////////////////////////////////////////Battle Phase
void GameBoard::battlePhase(){//users choose to attack or defense and they choose the cards they want to attack/defend with
  int atDefInput;
  int currPlayerI;

  list<Player*>::iterator currPlayer;
  for(currPlayer=players->begin(); currPlayer != players->end(); currPlayer++){
    if((*currPlayer)->getCountOfPlayedPersonalityCards() >0){
      cout << "Do you want to attack or defend this round attack=1/defense=0: ";//get input from user
      cin >> atDefInput;
      while(atDefInput != 0 && atDefInput != 1){//fail safe
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
        while(currEnemyI < 0 || currEnemyI > countOfPlayers-1 || currEnemyI == currPlayerI){//fail safe
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

        cout << "Choose Enemy's province to attack: ";//get input about enemy province
        int currEnemyProvinceI;//index
        cin >> currEnemyProvinceI;
        while(currEnemyProvinceI < 0 || currEnemyProvinceI > (*currEnemy)->getCountOfProvinces()-1){//fail safe
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
        {//calculate total defense of enemy's province
          list<Personality*>::iterator it;
          for(it=(*currEnemyProvince)->getDefendingCards()->begin();it!=(*currEnemyProvince)->getDefendingCards()->end();it++){
            totalDefense +=(*it)->getDefense();
          }
        }//from here totalDefense has the full defense of the province

        int currPersonalityI;//index
        cout << "Choose Personality to attack: ";
        cin >> currPersonalityI;
        while(true){
          bool currPersonalityIsTapped= true;

          list<Personality*>::iterator currPersonality;//get currPlayer's selected Personality Card
          {
            int count;
            list<Personality*>* temp= (*currPlayer)->getPlayedPersonalityCards();
            do{
              while(currPersonalityI < -1 ||  currPersonalityI >= (*currPlayer)->getCountOfPlayedPersonalityCards()){//fail safe
                cout << "Try again: ";
                cin >> currPersonalityI;
              }
              if(currPersonalityI != -1){//incase of user wants to use more than one personality cards to atack
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
                if(attackingPersonalityCards->size() == 0){//if no personality is chosen re-do process
                  currPersonalityIsTapped = true;
                  cout << "Try again: ";
                  cin >> currPersonalityI;
                }else{
                  currPersonalityIsTapped = false;
                }
              }
            }while(currPersonalityIsTapped);//if yes repeat the prossess for a diffrent personality card

            attackingPersonalityCards->push_back((*currPersonality));//add to our list
            (*currPlayer)->getPlayedPersonalityCards()->erase(currPersonality);//tis diagrafo oste ama pethanoun na min prepei na tis diagrafo kai apo tis dio listes kai ama epiviosoun tis ksanaantigrafo

            {//print currPlayers personalities
              int currPersonalityCount=0;
              cout << "---Your Personalities: " << endl;
              if(currPersonalities->size() == 0){//check if there are any personalities to choose from
                cout << "You have no personalities to choose from" << endl;
                cout << "Choosing done" << endl;
                break;
              }else{
                list<Personality*>::iterator it;
                for(it=currPersonalities->begin(); it != currPersonalities->end(); it++){
                  cout << currPersonalityCount << ": ";
                  (*it)->printStats();
                  currPersonalityCount++;
                }
                cout << endl << endl;
              }
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
              if(currPersonalities->size() == 0){
                cout << "You have no personalities to choose from" << endl;
                cout << "Choosing done" << endl;
                break;
              }else{
                list<Personality*>::iterator it;
                for(it=currPersonalities->begin(); it != currPersonalities->end(); it++){
                  cout << currPersonalityCount << ": ";
                  (*it)->printStats();
                  currPersonalityCount++;
                }
                cout << endl << endl;
              }

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
      }
    }else{
      cout << "\t No personalities available! Battle Phase Skiped" << endl;
    }
  }
}

////////////////////////////economyPhase
// TODO molis agorazei mia karta na elegxei gia alisides
void GameBoard::economyPhase(){
  list<Player*>::iterator currPlayer;
  int plCount=0;
  for(currPlayer=players->begin(); currPlayer != players->end(); currPlayer++){
    cout << "###Player" << plCount++ << ":" << endl;
    cout << "Player $$: " << (*currPlayer)->getMoney() << endl;
    cout << "Top of provinces: " << endl;
    (*currPlayer)->printTopOfProvince();

    int currTopOfProvinceI;//index
    cout << "Choose top of province to buy: ";//get input about topOfProvince to buy
    cin >> currTopOfProvinceI;

    list <Personality*>::iterator itPersonality;//potential personality card chosen
    list <Holding*>::iterator itHolding;//potential holding card chosen
    bool perOrHolding;//TRUE IF HOLDING IS CHOSEN, FALSE IF PERSONALITY IS CHOSEN
    {//get chosen topOfProvince
      bool donePurchase= true;
      do{
        while(currTopOfProvinceI < -1 || currTopOfProvinceI > (*currPlayer)->getTopOfProvinceCount()-1){//fail safe for wrong input
          cout << "Try again: ";
          cin >> currTopOfProvinceI;
        }
        if(currTopOfProvinceI == -1){
          break;
        }

        //scan both lists to find currTopOfProvince
        int count=0;
        list <Personality*>::iterator it;
        bool found = false;
        {
          for(it= (*currPlayer)->getTopOfProvincePersonality()->begin(); it != (*currPlayer)->getTopOfProvincePersonality()->end(); it++){
            if(count == currTopOfProvinceI){
              found = true;
              break;//if you are here then currTopOfProvinceI is a personality card saved in iterator it
            }else{
              count++;
            }
          }
        }

        if(!found){//if card havent found in personality list then check holding list
          list <Holding*>::iterator it;
          for(it= (*currPlayer)->getTopOfProvinceHolding()->begin(); it != (*currPlayer)->getTopOfProvinceHolding()->end(); it++){
            if(count == currTopOfProvinceI){
              found = true;
              break;
            }else{
              count++;
            }
          }
          itHolding = it;
          perOrHolding = true;
        }else{
          itPersonality = it;
          perOrHolding = false;
        }
        if(perOrHolding){//check if money is enough to buy
          if((*currPlayer)->getMoney() >= (*itHolding)->getCost()){
            (*currPlayer)->setMoney((*currPlayer)->getMoney() - (*itHolding)->getCost());//do everything you need
            (*currPlayer)->getPlayedHoldingCards()->push_back(*itHolding);
            (*currPlayer)->getTopOfProvinceHolding()->erase(itHolding);
            donePurchase=true;
          }else{
            cout << "Not enough money" << endl;
            donePurchase=false;
          }
        }else{
          if((*currPlayer)->getMoney() >= (*itPersonality)->getCost()){
            (*currPlayer)->setMoney((*currPlayer)->getMoney() - (*itPersonality)->getCost());//do everything you need
            (*currPlayer)->getPlayedPersonalityCards()->push_back(*itPersonality);
            (*currPlayer)->getTopOfProvincePersonality()->erase(itPersonality);
            donePurchase=true;
          }else{
            cout << "Not enough money" << endl;
            donePurchase=false;
          }
        }
        if(!donePurchase){
          cout << "Choose again: ";
          cin >> currTopOfProvinceI;
        }
      }while(!donePurchase);
      if(currTopOfProvinceI == -1){
        {//eprepe na baloume goto :(
          // loop tis playedHoldingCards gia na auksiso to money tou paikti analoga me to harvestValue ton karton tou
          int totalHarvest=0;
          cout<<"Player money before harvestValues added : "<<(*currPlayer)->getMoney()<<endl;
          list <Holding*>::iterator it;//GOLD_MINE
          (*currPlayer)->increaseMoney(5);//money from stronghold
          totalHarvest += 5;
          for(it= (*currPlayer)->getPlayedHoldingCards()->begin(); it != (*currPlayer)->getPlayedHoldingCards()->end(); it++){
            totalHarvest+=(*it)->getHarvestValue();
            cout<<"HarvestValue is : "<<(*it)->getHarvestValue()<<endl;
            (*currPlayer)->increaseMoney((*it)->getHarvestValue());
          }
          cout<<"Total Money harvested = "<< totalHarvest <<endl;
          cout<<"Player money after harvestValue added : "<< (*currPlayer)->getMoney()<<endl;

          cout << endl;
          while((*currPlayer)->getTopOfProvinceCount() < (*currPlayer)->getCountOfProvinces()){//if topOfProvince bought replace it with a new black card
            if((*currPlayer)->fillTopOfProvince((*currPlayer)->getDynastyDeck()->front())){
              (*currPlayer)->getDynastyDeck()->pop_front();
            }
          }
        }
        continue;
      }
    }

    if(perOrHolding){//EDW AN TO CHOSEN TOP OF CARD EINAI HOLDING
      //chains
      cout<<"HarvestValue before creation of chain "<<((*itHolding)->getHarvestValue())<<endl;
      if((*itHolding)->getCategory()=="MINE"&&(*itHolding)->getHasUpperHolding()==0){//an eimai se mine horis upperholding
        //psaxno ti lista na vro an iparxei GOLD_MINE xoris subholding
        list <Holding*>::iterator it;
        for(it= (*currPlayer)->getPlayedHoldingCards()->begin(); it != (*currPlayer)->getPlayedHoldingCards()->end(); it++){
          if((*it)->getSubcategory()=="GOLD_MINE"&&(*it)->getHasSubHolding()==0){
            (*it)->changeSubHoldingStatus();//make GOLD_MINE int hassubholding=1
            (*itHolding)->changeUpperHoldingStatus();//make MINE int hasUpperHolding=1
            (*it)->increaseHarvestValue(4);//auksano harvestValue tou GOLD_MINE
            (*itHolding)->increaseHarvestValue(2);//auksano harvestValue tou mine
          }
        }//for end
        cout<<"Current HarvestValue is : "<<((*itHolding)->getHarvestValue())<<endl;
      }
      if((*itHolding)->getSubcategory()=="GOLD_MINE"&&(*itHolding)->getHasSubHolding()==0){//an eimai se GOLD_MINE xoris subholding
        list <Holding*>::iterator it;//MINE
        for(it= (*currPlayer)->getPlayedHoldingCards()->begin(); it != (*currPlayer)->getPlayedHoldingCards()->end(); it++){
          if((*it)->getSubcategory()=="MINE"&&(*it)->getHasUpperHolding()==0){
            (*it)->changeUpperHoldingStatus();//make GOLD_MINE int hassubholding=1
            (*itHolding)->changeSubHoldingStatus();//make MINE int hasUpperHolding=1
            (*it)->increaseHarvestValue(2);//auksano harvestValue tou MINE
            (*itHolding)->increaseHarvestValue(4);//auksano harvestValue tou GOLD_MINE
          }
        }//for end
      }
      if((*itHolding)->getCategory()=="GOLD_MINE"&&(*itHolding)->getHasUpperHolding()==0){//an eimai se GOLD_MINE horis upperholding
        //psaxno ti lista na vro an iparxei CRYSTAL_MINE xoris subholding
        list <Holding*>::iterator it;//CRYSTAL_MINE
        for(it= (*currPlayer)->getPlayedHoldingCards()->begin(); it != (*currPlayer)->getPlayedHoldingCards()->end(); it++){
          if((*it)->getSubcategory()=="CRYSTAL_MINE"&&(*it)->getHasSubHolding()==0){
            (*it)->changeSubHoldingStatus();//make CRYSTAL_MINE int hassubholding=1
            (*itHolding)->changeUpperHoldingStatus();//make GOLD_MINE int hasUpperHolding=1
            (*it)->increaseHarvestValue((*it)->getHarvestValue());//thelo na diplasiaso to harvestValue opote apla to auksano me ton eauto tou
            (*itHolding)->increaseHarvestValue(5);//auksano harvestValue tou GOLD_MINEmine
          }
          //elegxo an einai telia alisiada tote na triplasiaso to harvestValue tou CRYSTAL_MINE
          if((*itHolding)->getHasSubHolding()==1&&(*itHolding)->getHasUpperHolding()==1){
            (*it)->increaseHarvestValue((*it)->getHarvestValue());//thelo na triplasiaso to harvestValue opote afou to xo diplasiasei idi mia fora sto proto if to prostheto alli mia fora ston eauto tou
          }
        }//for end
      }
      if((*itHolding)->getSubcategory()=="CRYSTAL_MINE"&&(*itHolding)->getHasSubHolding()==0){
        list <Holding*>::iterator it;//GOLD_MINE
        for(it= (*currPlayer)->getPlayedHoldingCards()->begin(); it != (*currPlayer)->getPlayedHoldingCards()->end(); it++){
          if((*it)->getSubcategory()=="GOLD_MINE"&&(*it)->getHasUpperHolding()==0){
            (*it)->changeUpperHoldingStatus();//make CCrystal_MINE int hassubholding=1
            (*itHolding)->changeSubHoldingStatus();//make GOLD_MINE int hasUpperHolding=1
            (*it)->increaseHarvestValue(5);//auksano harvestValue tou GOLD_MINE
            (*itHolding)->increaseHarvestValue((*itHolding)->getHarvestValue());//auksano harvestValue tou CRYSTAL_MINE
          }
        }//for end
      }
      //chains end
    }else{//EDW AN TO CHOSEN TOP OF CARD EINAI PERSONALITY

    }
    //eprepe na baloume edw to goto :(
    {
      // loop tis playedHoldingCards gia na auksiso to money tou paikti analoga me to harvestValue ton karton tou
      int totalHarvest=0;
      cout<<"Player money before harvestValues added : "<<(*currPlayer)->getMoney()<<endl;
      list <Holding*>::iterator it;//GOLD_MINE
      (*currPlayer)->increaseMoney(5);//money from stronghold
      totalHarvest += 5;
      for(it= (*currPlayer)->getPlayedHoldingCards()->begin(); it != (*currPlayer)->getPlayedHoldingCards()->end(); it++){
        totalHarvest+=(*it)->getHarvestValue();
        cout<<"HarvestValue is : "<<(*it)->getHarvestValue()<<endl;
        (*currPlayer)->increaseMoney((*it)->getHarvestValue());
      }
      cout<<"Total Money harvested = "<< totalHarvest <<endl;
      cout<<"Player money after harvestValue added : "<< (*currPlayer)->getMoney()<<endl;

      cout << endl;
      while((*currPlayer)->getTopOfProvinceCount() < (*currPlayer)->getCountOfProvinces()){//if topOfProvince bought replace it with a new black card
        if((*currPlayer)->fillTopOfProvince((*currPlayer)->getDynastyDeck()->front())){
          (*currPlayer)->getDynastyDeck()->pop_front();
        }
      }
    }
  }
}

////////////////////////////////////////Final Phase
void GameBoard::checkWinningCondition(){
  int count=0;
  for(int i=0;i<countOfPlayers; i++){//loop for every player
    list<Player*>::iterator currPlayer;
    for(currPlayer=players->begin(); currPlayer != players->end(); currPlayer++){
      //discardSurplusFateCards already taken care of
      if((*currPlayer)->getProvinces()->size()==0){//check if player must die
        cout<<"Deleting Player: " << count << endl;//if yes delete him
        count++;
        players->erase(currPlayer);//TODO Check if this is correct paizei na bgalei segme, prepei na to treksoume kai na teleiwsei to paixnidi gia to 100%
        break;//and stop the loop
      }//else go to the next one
      count++;
    }
  }
  countOfPlayers= (int)players->size();//refresh the countOfPlayers
}
