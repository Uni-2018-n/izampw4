#include "DeckBuilder.hpp"

using namespace std;

DeckBuilder::DeckBuilder()
{
	black = new list<BlackCard *>();
	green = new list<GreenCard *>();
	srand(unsigned(time(NULL)));
}

DeckBuilder::~DeckBuilder()
{
	list<BlackCard *>::iterator it;
	list<GreenCard *>::iterator it2;
	for (it = black->begin(); it != black->end(); it++)
	{
		black->remove((*it));
		delete *it;
		it = black->begin();
	}
	for (it = green->begin(); it != green->end(); it++)
	{
		green->remove((*it));
		delete *it;
		it = green->begin();
	}
	delete black;
	delete green;
}

list<GreenCard *> *DeckBuilder::createFateDeck()
{
	int i;
	for (i = 0; i < NO_FOOTSOLDIER; i++)
		green->push_back(new Footsoldier("Peasants"));
	for (i = 0; i < NO_ARCHER; i++)
		green->push_back(new Archer("Elite Troops"));
	for (i = 0; i < NO_SIEGER; i++)
		green->push_back(new Sieger("Immortal Bushi"));
	for (i = 0; i < NO_CAVALRY; i++)
		green->push_back(new Cavalry("Unicorn Horses"));
	for (i = 0; i < NO_NAVAL; i++)
		green->push_back(new Atakebune("Yomi Ships"));
	for (i = 0; i < NO_BUSHIDO; i++)
		green->push_back(new Bushido("7 Samurai"));

	for (i = 0; i < NO_KATANA; i++)
		green->push_back(new Katana("Daijtso"));
	for (i = 0; i < NO_BOW; i++)
		green->push_back(new Bow("Yumi"));
	for (i = 0; i < NO_SPEAR; i++)
		green->push_back(new Spear("Kama"));
	for (i = 0; i < NO_NINJATO; i++)
		green->push_back(new Ninjato("Butterfly Dagger"));
	for (i = 0; i < NO_WAKIZASHI; i++)
		green->push_back(new Wakizashi("Kusanagi"));

	return green;
}

list<BlackCard *> *DeckBuilder::createDynastyDeck()
{
	int i;
	//Create Personalities
	//NO_DEFENSIVE 10
	for (i = 0; i < NO_DEFENSIVE; i++)
		black->push_back(new Personalities("Footsoldiers",DEFENDER));
	//NO_ATTACKING 10
	for (i = 0; i < NO_ATTACKING; i++)
		black->push_back(new Personalities("Steadfast bushi",ATTACKER));
	//NO_SHOGUN	2
	black->push_back(new Personalities("Akodo Kaneka",SHOGUN));
	black->push_back(new Personalities("Isawa Shi en",SHOGUN));
	//NO_CHANCELLOR 2
	black->push_back(new Personalities("Hida Shoze ",CHANCELLOR));
	black->push_back(new Personalities("Mirimuto Enishi",CHANCELLOR));
	//NO_CHAMPION 1
	black->push_back(new Personalities("Hida Kisada",CHAMPION));
	//Create holdings
	for (i = 0; i < NO_PLAIN; i++)
		black->push_back(new Holdings("Rice Fields",PLAIN));
	for (i = 0; i < NO_FARMS; i++)
		black->push_back(new Holdings("Fish Farms",FARMLAND));
	for (i = 0; i < NO_MINE; i++)
		black->push_back(new Holdings("Ashio Copper Mine",MINE));
	for (i = 0; i < NO_GOLD_MINE; i++)
		black->push_back(new Holdings("Konomai Gold Mine",GOLD_MINE));
	for (i = 0; i < NO_CRYSTAL_MINE; i++)
		black->push_back(new Holdings("Ichinokawa Crystal Mine",CRYSTAL_MINE));
	for (i = 0; i < NO_SOLO; i++)
		black->push_back(new Holdings("Gifts and Favors",SOLO));

	return black;
}

void DeckBuilder::deckShuffler(list<BlackCard *> *black)
{
	vector<BlackCard *> vect;
	list<BlackCard *>::iterator it;
	for (it = black->begin(); it != black->end(); it++)
		vect.push_back((*it));

	random_shuffle(vect.begin(), vect.end());

	black->clear();

	vector<BlackCard *>::iterator it2;
	for (it2 = vect.begin(); it2 != vect.end(); it2++)
		black->push_back((*it2));
}

void DeckBuilder::deckShuffler(list<GreenCard *> *green)
{
	vector<GreenCard *> vect;
	list<GreenCard *>::iterator it;
	for (it = green->begin(); it != green->end(); it++)
		vect.push_back((*it));

	random_shuffle(vect.begin(), vect.end());

	green->clear();

	vector<GreenCard *>::iterator it2;
	for (it2 = vect.begin(); it2 != vect.end(); it2++)
		green->push_back((*it2));
}
