#pragma once

#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cassert>
// Need to include Player.h, Orders.h
//#include "Orders.h"
//#include "Player.h"
using namespace std;

class Hand;
class Deck;
class Player; // Needed for when play

class Cards
{
	vector<string> cardTypes = { "Bomb", "Reinforcement", "Blockage", "Airlift", "Diplomacy" };
	//string* cardType;
	string* type;
	vector<string*> decks;
	vector<string*> hands;

public:

	Player* player;
	Deck* theDeck;
	Hand* theHand;

	Cards();
	//Cards(string type);

	Cards(const Cards& c); // Copy constructor

	Cards& operator=(const Cards& c); // Assignment operator


	vector<string>* getTypePtr(); // get pointer to the type
	void printType(); // To try print type
	void setCardType(int n); // Set the type of card
	string* getCardType(); // Show the name of the type of card

	// Creates an Order object & places it in the Players' list of orders, removes card from Hand
	// & places it back in Deck
	virtual void play();
	//void play(Cards* card, Deck* deck, Hand* hand);
	virtual string getType();

	virtual ~Cards();
};

// Orders
class BombCard : public Cards
{
public:
	BombCard();

	friend ostream& operator << (ostream& out, const BombCard& c);
	BombCard& operator =(const BombCard& c);

	void play();
	string getType();

	~BombCard();

};

class ReinforcementCard : public Cards
{
public:
	ReinforcementCard();

	void play();
	string getType();

	friend ostream& operator << (ostream& out, const ReinforcementCard& c);
	ReinforcementCard& operator =(const ReinforcementCard& c);

	~ReinforcementCard();
};

class BlockageCard : public Cards
{
public:
	BlockageCard();

	friend ostream& operator << (ostream& out, const BlockageCard& c);
	BlockageCard& operator=(const BlockageCard& c);

	void play();
	string getType();

	~BlockageCard();
};

class AirliftCard :public Cards
{
private:
	//Territory* current;
public:
	AirliftCard();

	friend ostream& operator << (ostream& out, const AirliftCard& c);
	AirliftCard& operator=(const AirliftCard& c);

	void play();
	string getType();

	~AirliftCard();
};

class NegociateCard :public Cards
{
private:
	Player* enemy;
public:
	NegociateCard();
	NegociateCard(Player* e);

	friend ostream& operator << (ostream& out, const NegociateCard& c);
	NegociateCard& operator =(const NegociateCard& c);

	void play();
	string getType();

	void setEnemy(Player* e);
	Player* getEnemy();

	~NegociateCard();
};


// Deck class
class Deck : public Cards
{
	int maxSize; // Limit deck size
	vector<Cards*> myDeck; // Collection of cards
	Cards* cardPtr; // pointer to card
	Cards* tempCard; // for draw & remove element of vector
	string tempCardName;

public:

	Deck();
	Deck(const Deck& deck); // Assignment operator

	Deck& operator=(const Deck& deck); // Copy constructor

	void create_deck(); // Creates deck with each type of cards

	// Draw method that allows player to draw a card at random from the cards remaining in the deck
	// and place it in their hand
	Cards* draw();
	string getCardDrawn();
	vector<Cards*> getDeck();

	void printDeck();

	int getMaxSize();

	void addCardDeck(Cards* card); // Add specific card to deck
	~Deck(); // Destructor
};

class Hand : public Cards
{
	vector<string> cardNames; // Names of cards in hand
	vector<Cards*> myHand; // Collection of cards
	vector<Cards*> playCard; // For store play cards
	int size;

public:


	Hand();
	Hand(const Hand& hand); // Assignment Constructor

	Hand& operator=(const Hand& hand);  // Copy constructor

	vector<Cards*> getHand();

	void play(int i);

	void printHand();

	// If false, means have more than 6 cards. Else, have 6 cards or less
	bool checkSize();
	void addCardHand(Cards* card); // Add specific card to deck

	Cards* remove(Cards* card);
	~Hand(); // Destructor
};
