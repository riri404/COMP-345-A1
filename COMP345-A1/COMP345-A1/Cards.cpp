#include <iostream>
#include <list>
#include <string>

#include "Cards.h"

using namespace std;

Cards::Cards() 
{
	//type = "name";
}

//Cards::Cards(string type)
//{
//	type = type;
//}

// Copy constructor
Cards::Cards(const Cards& c)
{
	//this->type = c.type;
	this->cardTypes = *new vector<string>(c.cardTypes);
	this->type = new string(*(c.type));
}

// Assignment operator
Cards& Cards::operator=(const Cards& c) 
{
	//this->type = c.type;
	this->cardTypes = *new vector<string>(c.cardTypes);
	this->type = new string(*(c.type));

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

}

Cards::~Cards()
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
				myDeck.push_back(cardPtr);
			}
			// Type 2 = Reinforcement
			else if (j == 1)
			{
				cardPtr->setCardType(1);
				myDeck.push_back(cardPtr);
			}
			// Type 3 = Blockage
			else if (j == 2)
			{
				cardPtr->setCardType(2);
				myDeck.push_back(cardPtr);
			}
			// Type 4 = Airlift
			else if (j == 3)
			{
				cardPtr->setCardType(3);
				myDeck.push_back(cardPtr);
			}
			// Type 5 = Diplomacy
			else if (j == 4)
			{
				cardPtr->setCardType(4);
				myDeck.push_back(cardPtr);
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


Deck::~Deck()
{
	for (int i = 0; i < myDeck.size(); i++) {
		delete myDeck[i];
	}
}

Hand::Hand()
{
	size = 6;
}

// Assignment Operator
Hand::Hand(const Hand& hand) : Cards(hand)
{
	this->cardNames = *new vector<string>(hand.cardNames);
	this->myHand = *new vector<Cards*>(hand.myHand);
	this->playCard = *new vector<Cards*>(hand.playCard);
	this->size = hand.size;
}

// Copy constructor
Hand& Hand::operator=(const Hand& hand) 
{
	this->myHand = *new vector<Cards*>(hand.myHand);
	this->playCard = *new vector<Cards*>(hand.playCard);
	this->size = hand.size;

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

bool Hand::checkSize() 
{
	if (myHand.size() > 6) {
		return false;
	} 
	
	return true;
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

Hand::~Hand()
{
	for (int i = 0; i < myHand.size(); i++)
		delete myHand[i];
}
