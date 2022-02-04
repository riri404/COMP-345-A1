#include <iostream>
#include <list>
#include <string>

#include "Cards.h"

using namespace std;

Cards::Cards() 
{
	type = "name";
}

Cards::Cards(string type)
{
	type = type;
}

// Copy constructor
Cards::Cards(const Cards& c)
{
	this->type = c.type;
	this->cardTypes = *new vector<string>(c.cardTypes);
	this->cardType = new string(*(c.cardType));
}

// Assignment operator
Cards& Cards::operator=(const Cards& c) 
{
	this->type = c.type;
	this->cardTypes = *new vector<string>(c.cardTypes);
	this->cardType = new string(*(c.cardType));

	return *this;
}

string Cards::getCardType()
{
	return type;
}

string Cards::play()
{
	//Player* p = this->player;
	cout << "You player card " << getCardType() << endl;

	this->theDeck->addCardDeck(this);

	this->theHand->remove(this);
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
	for (int i = 0; i < 8; i++) {
		myDeck.push_back(new Cards("Bomb"));
	}

	for (int i = 0; i < 8; i++) {
		myDeck.push_back(new Cards("Reinforcement"));
	}

	for (int i = 0; i < 8; i++) {
		myDeck.push_back(new Cards("Blockage"));
	}

	for (int i = 0; i < 8; i++) {
		myDeck.push_back(new Cards("Airlift"));
	}

	for (int i = 0; i < 8; i++) {
		myDeck.push_back(new Cards("Diplomacy"));
	}

	cout << "Deck has been created" << endl;

}

// Removes the card from the Deck and returns that card
Cards* Deck::draw()
{
	Cards* card = myDeck[0];
	myDeck.erase(myDeck.begin());

	return card;
}

std::vector<Cards*> Deck::getDeck() 
{
	return myDeck;
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
	
	myHand.erase(it);

	return card;
}

Hand::~Hand()
{
	for (int i = 0; i < myHand.size(); i++)
		delete myHand[i];
}
