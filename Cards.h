#pragma once

#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cassert>

#include "Orders.h"
#include "Player.h"

using namespace std;

void CardsDriver();

class Hand;
class Deck;
class Player;

class Cards
{
private:
	vector<string> cardTypes = { "Bomb", "Reinforcement", "Blockage", "Airlift", "Negociate" };
	string* type;

public:
	Cards();
	Cards(const Cards& c); // Copy constructor
	Cards& operator=(const Cards& c); // Assignment operator

	vector<string>* getTypePts(); // Get pointer to type
	void printType(); // To try print type
	void setCardType(int n); // Set the type of card
	string* getCardType(); // Show name of the type of card

	virtual ~Cards();
};

// Deck class
class Deck : public Cards
{
private:
	vector<Cards*> myDeck; // Collection of cards
	Cards* cardPtr;	// pointer to card
	Cards* tempCard; // For draw & remove element of vector

public:
	Deck();
	Deck(const Deck& deck);	// Assignment operator

	Deck& operator=(const Deck& deck); // Copy constructor

	void create_deck();		// Creates deck with each type of cards

	void printDeck();
	void printDeckSize();

	// Draw method that allows player to draw a card at random from the cards remaining in the deck
	// and place it in their hand
	Cards* draw();

	void addCardDeck(Cards* card);	// Add specific card to deck
	~Deck();
};

class Hand :public Cards
{
private:
	vector<Cards*> myHand;	// Collection of cards
	vector<Cards*> playCard;	// For store play cards

public:
	Hand();
	Hand(const Hand& hand);	// Assignment constructor

	Hand& operator=(const Hand& hand);	// Copy constructor

	void setHand(Cards* c);
	void printHand();
	void printPlayCard();

	void play(Cards* c, Deck* d);

	void returnToDeck(Deck* d);

	vector<Cards*>* getHand();
	vector<Cards*>* getPlayHand();

	void removePlayedCard(Cards* c);
	void clearPlayCards();

	~Hand(); // Destr
};