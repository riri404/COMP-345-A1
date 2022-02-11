#include "Cards.h"

#include <iostream>
#include <string>

using namespace std;

int main() 
{
	// Creating objects
	Cards* cards;
	Deck* deck = new Deck();
	Hand* hand = new Hand;

	cout << "Creating Deck: " << endl;
	// Create the deck
	deck->create_deck();

	// Display amount of cards
	cout << "My deck size is " << deck->getDeck().size() << endl;
	//deck->printDeck();

	// Assign 6 random cards to the hand
	for (int i = 0; i < 6; i++) {
		Cards* drawnCard = deck->draw();
		hand->addCardHand(drawnCard);
	}
	// Display amount of cards in deck & hand
	cout << "My deck size is " << deck->getDeck().size() << endl;
	hand->printHand();

	/*while (hand->getHand().size() > 0)
	{
		hand->play();
	}*/
	//cout << "Play " << card->play() << endl;
	cout << "Deck size is " << deck->getDeck().size() << endl;
	cout << "Hand size is " << hand->getHand().size() << endl;
}