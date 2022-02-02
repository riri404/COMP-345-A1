#include <iostream>
#include <list>
#include <string>

#include "Cards.h"

using namespace std;

Cards::Cards() 
{
	type = "name";
}

Cards::Cards(const Cards& card)
{
}

Cards& Cards::operator=(const Cards& card)
{
	// TODO: insert return statement here
}

//Cards::Cards(CardType type)
//{
//}

std::string Cards::toString() const
{
	return std::string();
}

void Cards::play(Player* player, Deck* deck)
{
}

Cards::~Cards()
{
}

std::istream& operator>>(std::istream& in, const Cards& card)
{
	// TODO: insert return statement here
}

std::ostream& operator<<(std::ostream& out, const Cards& card)
{
	// TODO: insert return statement here
}

std::istream& operator>>(std::istream& in, const Deck& deck)
{
	// TODO: insert return statement here
}

std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
	// TODO: insert return statement here
}

Deck::Deck()
{
}

Deck::Deck(const Deck& deck)
{
}

Deck& Deck::operator=(const Deck& deck)
{
	// TODO: insert return statement here
}

void Deck::create_deck() {

}
Cards* Deck::draw()
{
}

std::vector<Cards*> Deck::getDeck() 
{

}

int Deck::getMaxSize() 
{

}

void Deck::addCard(Cards* card)
{
}


Deck::~Deck()
{
}

Hand::Hand()
{
}

Hand::Hand(const Hand& hand)
{
}

Hand& Hand::operator=(const Hand& hand)
{
	// TODO: insert return statement here
}

int Hand::remainingCards()
{
	return 0;
}

std::string* Hand::listAllCards()
{
	return nullptr;
}

//void Hand::addCard(CardType& type)
//{
//}

void Hand::addCard(Cards& card)
{
}

//void Hand::removeCard(CardType& type)
//{
//}

Hand::~Hand()
{
}
