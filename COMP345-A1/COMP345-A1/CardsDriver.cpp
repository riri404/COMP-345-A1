#include "Cards.h"

#include <iostream>
#include <string>

using namespace std;

int main() 
{
	// Creating objects
	Deck* deck = new Deck;
	Hand* hand = new Hand;

	// Create the deck
	deck->create_deck();

	// Display amount of cards
	cout << "My deck size is " << deck->getDeck().size() << endl;
	deck->printDeck();

	/*Cards* firstDrawnCard = deck->draw();
	cout << "Card drawn is " << deck->getCardDrawn() << endl;
	cout << "My deck size is " << deck->getDeck().size() << endl;*/

	// Assign 6 random 
	for (int i = 0; i < 6; i++) {
		Cards* drawnCard = deck->draw();
		hand->addCardHand(drawnCard);
	}
	// Display amount of cards in deck & hand
	cout << "My deck size is " << deck->getDeck().size() << endl;
	hand->printHand();

	Cards* card = new Cards();
	card->play();
	//cout << "Play " << card->play() << endl;
	cout << "Deck size is " << deck->getDeck().size() << endl;
	cout << "Hand size is " << hand->getHand().size() << endl;
}