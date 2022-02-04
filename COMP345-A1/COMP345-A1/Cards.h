#pragma once

#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cassert>
// Need to include Player.h, Orders.h
//#include "Order.h"
//#include "Player.h"
using namespace std;

#ifndef CARDS_H
#define CARDS_H

class Hand;
class Deck; 
class Player; // Needed for when play

class Cards 
{
	vector<string> cardTypes = { "Bomb", "Reinforcement", "Blockage", "Airlift", "Diplomacy" };
	string* cardType;
	string type;
public:
	
	Player* player;
	Deck* theDeck;
	Hand* theHand;
	
	Cards();
	Cards(string type);

	Cards(const Cards& c); // Copy constructor

	Cards& operator=(const Cards& c); // Assignment operator


	string getCardType(); // Show the name of the type of card

	// Creates an Order object & places it in the Players' list of orders, removes card from Hand
	string play();
	//void play(Cards* card, Deck* deck, Hand* hand);
	
	virtual ~Cards();
};

// Deck class
class Deck : public Cards 
{
	int maxSize; // Limit deck size
	vector<Cards*> myDeck; // Collection of cards
	Cards* cardPtr; // pointer to card
	Cards* tempCard; // for draw & remove element of vector

public:
	
	Deck();
	Deck(const Deck& deck); // Assignment operator

	Deck& operator=(const Deck& deck); // Copy constructor

	void create_deck(); // Creates deck with each type of cards

	// Draw method that allows player to draw a card at random from the cards remaining in the deck
	// and place it in their hand
	Cards* draw(); 
	vector<Cards*> getDeck();

	int getMaxSize();

	void addCardDeck(Cards* card); // Add specific card to deck

	~Deck(); // Destructor
};


class Hand : public Cards
{
	vector<Cards*> myHand; // Collection of cards
	vector<Cards*> playCard; // For store play cards
	int size;

public:

	Hand();
	Hand(const Hand& hand); // Assignment Constructor

	Hand& operator=(const Hand& hand);  // Copy constructor

	vector<Cards*> getHand();


	
	// If false, means have more than 6 cards. Else, have 6 cards or less
	bool checkSize(); 

	void addCardHand(Cards* card); // Add specific card to deck
	
	Cards* remove(Cards* card);

	~Hand(); // Destructor
};
#endif
