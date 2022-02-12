#include "Cards.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	Deck* deck = new Deck;
	Hand* hand = new Hand;

	deck->create_deck();
	cout << "Creating Deck." << endl;

	// Display amount of cards in deck
	cout << "Deck size is : " << deck->getDeck().size() << endl;
	
	string answer;
	cout << "Do you wish to see the cards in the deck? (y/n)" << endl;
	cin >> answer;

	if (answer == "y")
	{
		deck->printDeck();
	}
	
	// Assign 6 random cards
	cout << "Let's assign you 6 random cards. " << endl;
	for (int i = 0; i < 6; i++)
	{
		Cards* drawnCard = deck->draw();
		hand->addCardHand(drawnCard);
	}

	cout << "Your 6 cards have been assigned. Do you wish to see them?(y/n)" << endl;
	cin >> answer;

	if (answer == "y")
	{
		hand->printHand();
	}

	cout << "The deck size is now of " << deck->getDeck().size() << " cards." << endl;

	// Show play
	cout << "Testing play. " << endl;
	

}