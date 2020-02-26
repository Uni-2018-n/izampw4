MADE BY sdi1800056 & sdi18000216
 ANTONIS KALAMAKIS & IOANNIS PSARROS

Compilation and Execution: make

=>Card.cpp/.hpp

We created  4 enums one for each card category , and for each card there are
some subcategories.

Class Card{
  Contains the basic data for every card and some basic functions.
  string category:Contains the type of the card[FOLLOWER,ITEM,HOLDING,PERSONALITY]
  string subcategory:Contains the name of the subcategories of each card's category used in Holdings.
}

Class GreenCard{
  Subclass of Class Card.
  Contains the necessary variables and some basic functions.
  [cardText is unused.Normally it provides additional information about the cards]
}

Class BlackCard{
  Subclass of Class Card.
  Contains the necessary variables and some basic functions.
}

  -->GreenCard subClasses:
  =>Follower.cpp/.hpp
  Class Follower{
    Subclass of Class GreenCard.
    Constructor initialized all values in parent classes.
  }

  =>Item.cpp/.hpp
  Class Item{
    Subclass of Class GreenCard.
    Constructor initialized all values in parent classes and in class Item.
  }

  -->Black subClasses:
  =>Holding.cpp/.hpp

  class Holding{
    Subclass of Class BlackCard.
    Constructor initialized all values in parent classes.
    Functions change....HoldingStatus() change the value of variable has....Holding to 1;
    Function increaseHarvestValue increases the harvestValue by a [a== amount given as a parameter]
    In order to print the data of a Holding card we use 2 functions,printStats(bool a) if the user
    needs to know the data and the cost of the card and printStats() to print the data of the Holding.
  }

  class Personality{
    Subclass of Class BlackCard.
    Constructor initialized all values in parent classes.
    Contains the necessary variables and some basic functions.  
    Class Personality has a Follower and an Item which are used to attach cards to it.
    In order to print the data of a Personalit card we use 2 functions,printStats(bool a) if the user
    needs to know the data and the cost of the card and printStats() to print the data of the Personality.
  }

  class Stronghold{
    Subclass of Class BlackCard.
    Stronghold provides the starting values for the player[harvest,money ,etc]
  }

  class Hand{
    Contains 2 lists, one for each card category.
    Constructor initializes those lists and adds 4 starter cards from fateDeck
    Function addToHand(GreenCard*) is used to add 1 card to the necessary lists
    Function currPl() returns the count of all Cards in players hand
    Function print() prints all the cards and their data.
    Function getCardFromIndex(int cardIndex) returns the card from the index given as a parameter
    Function removeCard(int cardIndex) removes the card from the index given as a parameter
  }

  class Player{
     Contains 1 Stronghold,1 dynasty deck,1 fate deck,1 list topOfProvincePersonalities,
     1 list topOfProvinceHolding,1 list for the provincies,the amount of provinces,
     the Hand of a player and 2 lists which contain the played Black Cards(playedPersonalityCards
     and playedHoldingCards
------->
     Constructor initializes the lists, initializes variables from the Stronghold,
     initializes provinces with 4 BlackCards, uses fillTopOfProvince to fill the the BlackCards that the
     player is able to buy and finally it initializes the Hand.

     For function fillTopOfProvince it fills with BlackCards the lists for topOfProvince(personality, holding).
     For function getTopOfProvinceCount returns the count of topOfProvince cards
     For function printTopOfProvince it prints the BlackCards inside the topOfProvince lists.

     Starter Phase:
     Function printCurrState prints every data for player
     Function untapEverything untaps every card in the player
     Function revealProvinces it reveals every players province
     Function drawFateCard it draws a sigle card from fate deck and adds it to the currHand

     Equip Phase:
     Function printOptions prints the players hand and army(personalities)
     Function equipCardToArmy checks if the money of the player is enough to buy a selected card(index given from
     parameter) and if yes, it checks if the specific personality card already contains a green card, if everything
     is ok it buys it and equips it to the personality and then it asks the player if he wants to buy the bonus
     effect for the card.
     Function remove hand card removes the card, given index from parameter, in the players hand

     Battle Phase:
     Function printOptionsByEnemys is the options that an enemy is able to see(only provinces)
     Function destroyProvince destroys a provinces in index given from parameter
     Function destroyCards destroys the cards that are used to defend the province given from parameter

     Chains:
      Function findMine is called by a GOLD_MINE and finds a MINE without an upperholding in order to create a chain
      Function findGoldMineWithoutUpper is called by a CRYSTAL_MINE and finds a GOLD_MINE without an
       upperholding in order to create a chain
      Function findGoldMineWithoutSub is called by a MINE and finds a GOLD_MINE without a subholding in order to create
      a chain
      Function findCrystalMine is called by a GOLD_MINE and finds a CRYSTAL_MINE without a subholding in order to create a chain
    }

    class GameBoard{
      Contains 1 list containing the players and a variable which is defined in gameplay()
      which defines the number of players.
      Constructor gets as parameter the count of players played in the match.
      Function initializeGameBoard initializes the players
      Function gamePlay loops the game Phases until there is only one player left
      Function printArena() prints the played cards of each player.

      Function starterPhase() does everything the constructions require

      Function equipPhase() prints every card in players hand, also it prints the player's played personalies.
      Then he choose the GreenCard he wants to attach to a specific personality and with the help of function
      equipCardToArmy it calculates if its possible to buy the card and does it if yes.

      Function battlePhase() for each player it gives the option to attack between attacking or defending,
      if the player chooses to attack, it prints his personalities and all the enemy's provinces and he chooses
      everything. Then the function calculates the total defense of the choosen province and does the math to check
      the outcome of the attack(lose-lose, win-lose, lose-win) also the player has the ability to use multiple
      personality cards to attack with.
      If the player chooses to defend, it prints the personalities of the player and his provinces, and then lets the user to
      choose which personality to choose to defend a specific province then it adds the personality cards to the province's
      list called defendingCards.
      for every input for this phase it has a fail safe so no wrong input is allowed.
      finaly it checks for every players personality card to see if their honor is 0, if yes the card performs Seppuku

      Function economyPhase() prints the money, topOfProvinces the player has and it gives the ability for the player to choose
      to buy a BlackCard, then the function checks if its possible for the player to buy the card and if yes it buys it.
      Incase the bought card was a holding: If he buys a MINE,GOLD_MINE,CRYSTAL_MINE they will automatically create a chain
      increasing his harvestValue per round. And finaly it adds it to the playedHoldingCards
      Incase the bought card was a personality: it just adds it to the playedPersonalityCards list.
      finaly when the loop for the player is done, it calculates the total harvest value from the holdings and the
      stronghold harvest, prints the before and after money and continues with the next player.
      There is a grouped part in this function used twice, its necessary for the loop to finish.(Next possible fix was goto propably).

      Final phase:
      prints the arena and every statistic possible for the players also it calls checkWinningCondition().

      Function checkWinningCondition() is called at the end of every loop in order to remove players with
      provinces == 0.

      after every round the user must press enter to continue to the next round.(easier to read)

      when the game is finished it prints the coresponding message and prints the winning-player's statistics.
    }
