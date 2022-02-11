#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Cards.h"

using namespace std;

Cards::Cards() 
{
	//type = "name";
}

// Copy constructor
//Cards::Cards(const Cards& c)
//{
//	this->player = nullptr;
//	this->theDeck = nullptr;
//	this->theHand = nullptr;
//	//this->type = c.type;
//	this->cardTypes = *new vector<string>(c.cardTypes);
//	this->type = new string(*(c.type));
//}

// Assignment operator
Cards& Cards::operator=(const Cards& c) 
{
	if (&c != this)
	{
		this->player = c.player;
		this->theDeck = c.theDeck;
		this->theHand = c.theHand;
	}
	//this->player = c.player;
	//this->theDeck = c.theDeck;
	//this->theHand = c.theHand;
	////this->type = c.type;
	//this->cardTypes = *new vector<string>(c.cardTypes);
	//this->type = new string(*(c.type));

	return *this;
}

vector<string>* Cards::getTypePtr() 
{
	return &cardTypes;
}

void Cards::printType()
{
	cout << "The card types are: " << endl;
	for (int i = 0; i < cardTypes.size(); i++)
	{
		cout << cardTypes.at(i) << endl;
	}
}

void Cards::setCardType(int n)
{
	type = &cardTypes.at(n);
}

string* Cards::getCardType()
{
	return type;
}

// Creates an Order object & places it in the Players' list of orders, removes card from hand
// & places it back in deck
void Cards::play()
{
	Player* p = this->player;

}

Cards::~Cards()
{
	this->player = nullptr;
	this->theDeck = nullptr;
	this->theHand = nullptr;
}

// Orders
/*
* Bomb Card
*/
BombCard::BombCard()
{
}

BombCard& BombCard::operator =(const BombCard& c)
{
	if (&c != this)
	{
		this->Cards::operator=(c);
	}
	return *this;
}

void BombCard::play()
{
	Player* p = this->player;

	//Bomb* bOrder = new Bomb();

	//p->getOrdersList()->addToListOfOrders(bOrder);
	this->theDeck->addCardDeck(this);
	cout << "Bomb has been added to deck" << endl;

	p = nullptr;
	this->player = nullptr;
}

string BombCard::getType()
{
	return "Bomb card";
}

BombCard::~BombCard()
{
}

/*
* Reinforcement Card
*/

ReinforcementCard::ReinforcementCard()
{
}

void ReinforcementCard::play()
{
	Player* p = this->player;

	ReinforcementCard* rOrder = new ReinforcementCard();
	//p->getOrdersList()->addToListOfOrders(rOrder);
	
	this->theDeck->addCardDeck(this);
	cout << "Reinforcement added to deck" << endl;

	p = nullptr;
	this->player = nullptr;
}

string ReinforcementCard::getType()
{
	return "Reinforcement card";
}


ostream& operator<<(ostream& out, const ReinforcementCard& c)
{
	out << "Reinforcement Card";
	return out;
}


ReinforcementCard& ReinforcementCard::operator=(const ReinforcementCard& c)
{
	if (&c != this)
	{
		this->Cards::operator=(c);
	}
	return *this;
}

ReinforcementCard::~ReinforcementCard()
{
}

/*
* Blockage Card
*/

BlockageCard::BlockageCard()
{
}

ostream& operator << (ostream& out, const BlockageCard& c)
{

}

BlockageCard& BlockageCard::operator=(const BlockageCard& c)
{
	// TODO: insert return statement here
}

void BlockageCard::play()
{
	Player* p = this->player;

	BlockageCard* blockOrder = new BlockageCard();
	//p->getOrdersList()->addToListOfOrders(blockOrder);

	this->theDeck->addCardDeck(this);
	cout << "Blockage card has been added to the deck." << endl;

	blockOrder = nullptr;
	p = nullptr;
	this->player = nullptr;
}

string BlockageCard::getType()
{
	return "Blockage card";
}

BlockageCard::~BlockageCard()
{
}

/*
* Airlift Card
*/
AirliftCard::AirliftCard()
{
}

ostream& operator << (ostream& out, const AirliftCard& c)
{
	out << "AirliftCard";
	return out;
}

AirliftCard& AirliftCard::operator=(const AirliftCard& c)
{
	if (&c != this)
	{
		//this->Cards
	}
}

void AirliftCard::play()
{
	Player* p = this->player;

	AirliftCard* aOrder = new AirliftCard();

	//p->getOrdersList()->addToListOfOrders(aOrder);

	this->theDeck->addCardDeck(this);
	cout << "Airlift card has been added to the deck." << endl;

	aOrder = nullptr;
	p = nullptr;
	this->player = nullptr;
}

string AirliftCard::getType()
{
	return "Airlift card";
}

AirliftCard::~AirliftCard()
{
}

/*
* Negociate Card
*/
NegociateCard::NegociateCard()
{
	this->enemy = nullptr;
}

NegociateCard::NegociateCard(Player* e)
{
	this->enemy = e;
}

void NegociateCard::play()
{
	Player* p = this->player;

	NegociateCard* dOrder = new NegociateCard();
	
	//p->getOrdersList()->addToListOfOrders(dOrder);
	this->theDeck->addCardDeck(this);

	dOrder = nullptr;
	p = nullptr;
	this->theDeck = nullptr;
}

string NegociateCard::getType()
{
	return "Negociate card";
}

void NegociateCard::setEnemy(Player* e)
{
	this->enemy = e;
}

Player* NegociateCard::getEnemy()
{
	return this->enemy;
}


ostream& operator<<(ostream& out, const NegociateCard& c)
{
	out << "NegociateCard";
	return out;
}

NegociateCard& NegociateCard::operator=(const NegociateCard& c)
{
	if (&c != this)
	{
		this->Cards::operator=(c);
		this->enemy = c.enemy;
	}

	return *this;
}

NegociateCard::~NegociateCard()
{
}

Deck::Deck()
{
	maxSize = 40;
}

// Assignment operator
Deck::Deck(const Deck& deck) : Cards(deck)
{
	this->maxSize = deck.maxSize;
	this->myDeck = *new vector<Cards*>(deck.myDeck);
	this->cardPtr = new Cards(*(deck.cardPtr));
	this->tempCard = new Cards(*(deck.tempCard));
}

// Copy constructor
Deck& Deck::operator=(const Deck& deck)
{
	this->maxSize = deck.maxSize;
	this->myDeck = *new vector<Cards*>(deck.myDeck);
	this->cardPtr = new Cards(*(deck.cardPtr));
	this->tempCard = new Cards(*(deck.tempCard));

	return *this;
}

void Deck::create_deck() 
{
	// Assign 40 cards in deck vector, each type has 8 cards, 5 types
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cardPtr = new Cards;

			// Type 1 = Bomb
			if (j == 0)
			{
				cardPtr->setCardType(0);
				myDeck.push_back(new BombCard());
			}
			// Type 2 = Reinforcement
			else if (j == 1)
			{
				cardPtr->setCardType(1);
				myDeck.push_back(new ReinforcementCard());
			}
			// Type 3 = Blockage
			else if (j == 2)
			{
				cardPtr->setCardType(2);
				myDeck.push_back(new BlockageCard());
			}
			// Type 4 = Airlift
			else if (j == 3)
			{
				cardPtr->setCardType(3);
				myDeck.push_back(new AirliftCard());
			}
			// Type 5 = Diplomacy
			else if (j == 4)
			{
				cardPtr->setCardType(4);
				myDeck.push_back(new NegociateCard());
			}
		}
	}
}

// Removes the card from the Deck and returns that card
Cards* Deck::draw()
{
	// Draw a random card from the deck
	srand(time(NULL));

	int tempSize = myDeck.size();
	int temp = (rand() % tempSize);

	tempCard = myDeck.at(temp);
	tempCardName = *myDeck.at(temp)->getCardType();

	// Remove card from the deck
	myDeck.erase(myDeck.begin() + temp);
	
	return tempCard;
}

void Deck::drawC(Player* p)
{
	//Hand* h = p->getHand();
	Hand* h;
	srand(time(nullptr));

	int randCard = rand() % (this->myDeck.size() - 1) + 0;

	Cards* c = this->myDeck.at(randCard);

	c->player = p;
	h->myHand.push_back(c);

	this->myDeck.erase(this->myDeck.begin() + randCard);

	h = nullptr;
	c = nullptr;
}

// Returns name of card drawn
string Deck::getCardDrawn()
{
	return tempCardName;
}

vector<Cards*> Deck::getDeck() 
{
	return myDeck;
}

void Deck::printDeck()
{
	cout << "Deck contains " << myDeck.size() << "cards." << endl;
	for (int i = 0; i < myDeck.size(); i++) {
		cout << i << " card is " << *myDeck.at(i)->getCardType() << endl;
	}
}

int Deck::getMaxSize() 
{
	return maxSize;
}

void Deck::addCardDeck(Cards* card)
{
	myDeck.push_back(card);
}

ostream& operator<<(ostream& out, const Deck& d) 
{
	for (Cards* c : d.myDeck)
	{
		out << c->getType() << ", ";
	}
	out << "\b\b.";
	return out;
}

istream& operator>>(istream& in, const Deck& d)
{
	return in;
}


Deck::~Deck()
{
	for (int i = 0; i < myDeck.size(); i++) {
		delete this->myDeck[i];
		this->myDeck[i] = nullptr;
	}
	this->myDeck.clear();
}

Hand::Hand()
{
	vector<Cards*> myHand;
}

Hand::Hand(Player* player)
{
	vector<Cards*> myHand;
	this->player = player;
}

Hand::Hand(Hand& player)
{
	this->player = player.player;
	this->myHand = player.myHand;
}
// Assignment Operator
Hand::Hand(const Hand& hand) : Cards(hand)
{
	this->cardNames = *new vector<string>(hand.cardNames);
	this->myHand = *new vector<Cards*>(hand.myHand);
	this->playCard = *new vector<Cards*>(hand.playCard);
	//this->size = hand.size;
}

Hand::Hand(Player* pName, vector<Cards*> pCards)
{
	this->player = pName;
	//this->player->setHand(this);
	this->myHand = pCards;
}

// Copy constructor
Hand& Hand::operator=(const Hand& hand) 
{
	/*if (&hand != this)
	{
		this->player = hand.player;
		for (Cards* c : hand.myHand)
		{
			this->myHand.push_back(c);
		}
	}*/

	this->myHand = *new vector<Cards*>(hand.myHand);
	this->playCard = *new vector<Cards*>(hand.playCard);
	//this->size = hand.size;

	return *this;
}

vector<Cards*> Hand::getHand()
{
	return myHand;
}

void Hand::printHand()
{
	cout << "Hand contains " << myHand.size() << " cards." << endl;
	for (int i = 0; i < myHand.size(); i++)
	{
		cout << i << " card is " << *myHand.at(i)->getCardType() << endl;
	}
}

// Play 1st card in hand & removes it from hand
void Hand::play()
{
	this->myHand.at(0)->play();
	
	// or do
	/*auto removeCard = find(this->myHand.begin(), this->myHand.end(), this->myHand.at(0));
	this->myHand.erase(removeCard);*/

	this->remove(myHand.at(0));
}

void Hand::play(int index)
{
	this->myHand.at(index)->play();
	// Or do
	/*auto removeCard = find(this->myHand.begin(), this->myHand.end(), this->myHand.at(index));
	this->myHand.erase(removeCard);*/
	
	this->remove(myHand.at(index));
}


void Hand::addCardHand(Cards* card)
{
	myHand.push_back(card);
}

Cards* Hand::remove(Cards* card)
{
	vector<Cards*>::iterator it = find(myHand.begin(), myHand.end(), card);
	
	cout << "card removed is " << card->getCardType() << endl;

	myHand.erase(it);

	return card;
}

void Hand::deleteCard()
{
	auto removeCard = find(this->myHand.begin(), this->myHand.end(), this->myHand.at(0));
	this->myHand.erase(removeCard);
}

// Returns all the cards in the hand
ostream& operator<<(ostream& out, const Hand& h)
{
	for (Cards* c : h.myHand)
	{
		out << c->getType() << ", ";
	}
	out << "\b\b.";
	
	return out << endl;
}
istream& operator>>(istream& in, const Hand& h)
{
	return in;
}

Hand::~Hand()
{
	for (int i = 0; i < myHand.size(); i++)
		delete myHand[i];
}
