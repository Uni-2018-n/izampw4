#include <iostream>
using namespace std;
#include "givenFiles/DeckBuilder.hpp"
#include "Player.hpp"
#include "Card.hpp"


//TODO 1.1, 2.2
int main(){
	DeckBuilder* deck= new DeckBuilder();
	Player player_1(*deck);
	player_1.printCurrState();

	cout << endl << endl;

	Player player_2(*deck);
	player_2.printCurrState();

	cout << endl << endl;

	Player player_3(*deck);
	player_3.printCurrState();
	return 0;
}
