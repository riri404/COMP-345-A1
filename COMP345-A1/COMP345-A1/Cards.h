#pragma once

//#include <list>
#include <vector>
#include <string>
#include <iostream>
// Need to include Orders.h
//#include "Orders.h"
using namespace std;

#ifndef CARDS_H
#define CARDS_H

class Hand;
class Deck; 
class Player; // Needed for when play

class Cards 
{
	string type;
public:

	//CardType* type; // Type of card

	Cards();
	Cards(const Cards& card); // Copy constructor

	Cards& operator =(const Cards& card); // Assignment operatpr

	//Cards(CardType type); // Create card of a certain type

	std::string toString() const; // Output the cards into a string format.

	// Creates an Order object & places it in the Players' list of orders, removes card from Hand
	void play(Player* player, Deck* deck);

	// Stream insertion operators
	friend std::istream& operator>>(std::istream& in, const Cards& card);
	friend std::ostream& operator<<(std::ostream& out, const Cards& card);

	~Cards();
};

// Deck class
class Deck : public Cards 
{
private:
	std::list<Cards>* cards; // Collection of cards

public:
	Deck();
	Deck(const Deck& deck); // Copy constructor

	Deck& operator=(const Deck& deck); // Assignment Constructor

	void create_deck(); // Creates deck with each type of cards

	// Draw method that allows player to draw a card at random from the cards remaining in the deck
	// and place it in their hand
	Cards* draw(); 
	std::vector<Cards*> getDeck();

	int getMaxSize();

	void addCard(Cards* card); // Add specific card to deck

	// Stream insertion operators
	friend std::istream& operator>>(std::istream& in, const Deck& deck);
	friend std::ostream& operator<<(std::ostream& out, const Deck& deck);

	~Deck(); // Destructor
};


class Hand: public Cards
{
public:
	std::vector<Cards*> cards; // Collection of cards

	Hand();
	Hand(const Hand& hand); // Copy constructor

	Hand& operator=(const Hand& hand); // Assignment Constructor

	int remainingCards(); // Output remaining number of cards in the hand

	std::string* listAllCards();  // Lists all cards in the hand by outputting their type

	//void addCard(CardType& type); // Adds new card into deck
	void addCard(Cards& card); // Add specific card to deck
	
	// Removes card of specified type from the hand. Card chosen is the first card found of its type.
	//void removeCard(CardType& type); 

	~Hand(); // Destructor
};
#endif
