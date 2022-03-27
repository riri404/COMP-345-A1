#include "Player.h"
#include "Map.h"
#include "Cards.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Player::Player()
{
	name = new string("");
	reinforcementPool = new int(0);
	playerID = new int(-1);
	territoryList = *(new vector<Territory*>);
	handCards = new Hand();
  // list = (*new vector<Order>);
	orderList = new OrdersList();
}

Player::Player(int* playerID, int* reinforcementPool, string* name, vector<Territory*> territoryList, Hand* cards, OrdersList* orderlist)
{
	this->playerID = playerID;
	this->reinforcementPool = reinforcementPool;
	this->name = name;
	this->territoryList = territoryList;
	this->handCards = cards;
	this->orderList = orderlist;
}

Player::Player(const Player& p)
{
	this->playerID = p.playerID;
	this->reinforcementPool = p.reinforcementPool;
	this->name = p.name;
	this->territoryList = p.territoryList;
	this->handCards = p.handCards;
	this->orderList = p.orderList;
}

Player::~Player()
{
	delete playerID;
	playerID = nullptr;
	delete name;
	name = nullptr;
	delete handCards;
	handCards = nullptr;
	delete reinforcementPool;
	reinforcementPool = nullptr;
	delete orderList;
	orderList = nullptr;
	for (auto p : territoryList)
	{
		delete p;
	}
	territoryList.clear();

	// Added by Justine & Jennifer
	/*for (auto l : list) {
		delete l;
	}
	list.clear();*/

	/*for (auto n : playerNegociate) {
		delete n;
	}
	playerNegociate.clear();*/

	/*delete deck;
	deck = nullptr;*/

	/*for (auto lp : listOfPlayers) {
		delete lp;
	}
	listOfPlayers.clear();*/
}

Player& Player::operator=(const Player& p)
{
	this->playerID = p.playerID;
	this->name = p.name;
	this->reinforcementPool = p.reinforcementPool;
	this->territoryList = p.territoryList;
	this->handCards = p.handCards;
	this->orderList = p.orderList;
	return *this;
}

/*std:: istream& operator>>(std::istream& ins, Player& p1)
{
	ins >> p1.name;
	ins >> p1.cards;
	ins >> p1.territoryList;
	ins >> p1.orderList;
	return ins;
}*/

std::ostream& operator<<(std::ostream& outs, const Player& p1)
{
	outs << "Player ID: " << * (p1.playerID) << endl;
	outs << "Player's name: " << * (p1.name) << endl;
	//outs << "Player's cards: " << p1.handCards << endl;
	outs << "Player's cards: ";
	p1.handCards->printHand();
	outs << "Player's reinforcement pool" << *(p1.reinforcementPool) << endl;;
	//outs << (p1.territoryList);
	//outs << p1.orderList;

	return outs;
}

vector<Territory*> Player::toAttack(vector<Territory*> attack)
{
	vector<Territory*> AttackList;
	if (AttackList!= territoryList) {
		AttackList = getNeighbourTerritories(attack);

		cout << "The list of territories that are be Attack" << endl;
		for (int i = 0; i < AttackList.size(); i++)
		{
			cout << "Index " << i << " " << (*AttackList[i]).getName() << " " << (*AttackList[i]).getContinent() << endl;
		}
		return AttackList;
	}
}

vector<Territory*> Player::toDefend()
{

	vector<Territory*> DefendList;
	Territory* temp = NULL;
	cout << "The list of territories that are be defended" << endl;
	for (int i = 0; i < territoryList.size(); i++)
	{
		cout << "Index " << i << " " << (*territoryList[i]).getName() << " " << (*territoryList[i]).getContinent() << endl;
		temp = territoryList[i];
		DefendList.push_back(temp);
	}
	return DefendList;
}

void Player::issueOrder(vector<Territory*> order)
{
	bool CanDeploy = false;
	bool CanAdvance = false;
	bool SpecialOrder = false;


	//Returns list of enemy territories that are neighbors that we can attack
	toAttack(order);

	//Returns list of  territories that belong to the player that we can defend
	toDefend();



	//Check for dpeloy
	if (this->reinforcementPool > 0)
	{
		Deploy* d = new Deploy;
		this->getOrdersList()->addToListOfOrders(d);
		CanDeploy = true;
	}

	//Check for Advance
	bool AdvanceAttack = true;
	if (this->toAttack().size() == 0)
		AdvanceAttack = false;

	bool AdvanceDeploy = true;
	if (this->toDefend().size() == 0)
		AdvanceDeploy = false;

	if (AdvanceAttack || AdvanceDeploy) {
		Advance* d = new Advance;
		this->_OrderList.push_back(d);
		CanAdvance = true;
	}


	//Verify for the Execution of a Special Order

	vector<Card*> Hand = this->getHand()->GetCollection();
	//Monitor if we have already pushed a  Card

	//Play will remove the Card from the player Hand
	string CardType;
	if (Hand.size() != 0) {
		for (Card* c : Hand) {

			CardType = c->GetType();

			if (CardType == "Bomb") {
				//Plays the Card
				c->play(CardType);
				// This breaks out of the loop so we can push one Card at a time
				break;
			}

			if (CardType == "Airlift") {
				c->play(CardType);

				// This breaks out of the loop so we can push one Card at a time
				break;
			}

			if (CardType == "Diplomacy") {
				c->play(CardType);

				// This breaks out of the loop so we can push one Card at a time
				break;
			}

			if (CardType == "Blockade") {
				c->play(CardType);

				// This breaks out of the loop so we can push one Card at a time
				break;
			}

		}
	}
	else {
		cout << "We have Used all the cards inside the player's hand" << endl;
		SpecialOrder = true;
	}

	if (CanDeploy && CanAdvance && SpecialOrder) {
		this->FinishedIssueOrder = true;
		return;
	}
}

//check if territories are neighbour
vector<Territory*> Player::getNeighbourTerritories(vector<Territory*> Map) //help with this!!!!!!!!!!!!!!!!!!!1
{
	vector<Territory*> neighbourTerrritories;
	for (int i = 0; i < territoryList.size(); i++)
	{
		for (int j = 0; j < Map.size(); j++)
		{
			if (!territoryList[i]->getTerritoryOwner().compare(Map[j]->getTerritoryOwner()))
			{
				for (int k = 0; k < neighbourTerrritories.size(); k++)
				{
					if (!neighbourTerrritories[k]->getTerritoryOwner().compare(Map[j]->getTerritoryOwner()) || neighbouring_terrritories.empty())
					{
						neighbourTerrritories.push_back(Map[j]);
					}
				}

			}
		}

	}

	return neighbouring_terrritories;

}

// to calculate continent bonus for reinforcement phase
bool Player::playerContinentBouns()
{
	string a = "NA";
	string b = "AS";
	string c = "SA";
	string d = "AU";
	string e = "EU";
	string f = "AF";
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
	for (int i = 0; i < territoryList.size(); i++)
	{
		if ((*territoryList[i]).getContinent().compare(a))
		{
			c1++;
		}
		if ((*territoryList[i]).getContinent().compare(b))
		{
			c2++;
		}
		if ((*territoryList[i]).getContinent().compare(c))
		{
			c3++;
		}
		if ((*territoryList[i]).getContinent().compare(d))
		{
			c4++;
		}
		if ((*territoryList[i]).getContinent().compare(e))
		{
			c5++;
		}
		if ((*territoryList[i]).getContinent().compare(f))
		{
			c6++;
		}


	}
	if (c1 == 3) { 
		return true; 
	}

	if (c2 == 3) { 
		return true;
	}

	if (c3 == 1) { 
		return true; 
	}
	if (c4 == 1) { 
		return true;
	}
	if (c5 == 1) { 
		return true; 
	}
	if (c6 == 1) { 
		return true; 
	}

	return false;
}

int Player::getReinforcementPool() {
	return *(this->reinforcementPool);
}

void Player::setReinforcementPool(int r)
{
	//return int; // There is an error here
	*this->reinforcementPool = r;
}



void Player::setName(const string& n) {
	*name = n;
}

void Player::setPlayerID(const int& ID) {
	*playerID = ID;
}

vector<Territory*> Player::getTerritoryList() {
	return territoryList;
}


string Player::GetPlayerName() const{
	return *name;
}

Hand* Player::getPlayerHand() {
	return handCards;
}

int Player::GetPlayerID() const {
	return *playerID;
}

void Player::addTerritory(Territory* newTerritory) {

	territoryList.push_back(newTerritory);
}

void Player::addToReinforcePool(int armies) {
	delete reinforcementPool;
	reinforcementPool = new int(*reinforcementPool + armies);
}

void Player::removeFromReinforcePool(int armies) {
	delete reinforcementPool;
	reinforcementPool = new int(*reinforcementPool - armies);
}

void Player::AddCard(Cards* card) {
	handCards->setHand(card);
}

void Player::Attach(LogObserver* observer) {
	orderList->Attach(observer);
}

// Added by justine & jennifer
void Player::setTerritory(Territory* newTerritory)
{
	territoryList.push_back(newTerritory);
}

void Player::removeTerritory(int i)
{
	this->territoryList.erase(this->territoryList.begin() + i);
}

OrdersList* Player::getOrdersList() {
	return orderList;
}

void Player::setOrder(Order* order) {
	orderList->addToListOfOrders(order);
}

void Player::addNegociate(Player* p) {
	playerNegociate.push_back(p);
}

bool Player::isNegociating(Player* p) {
	for (int i = 0; i < playerNegociate.size(); i++) {
		if (playerNegociate.at(i) == p) {
			return true;
		}
	}
	return false;
}

void Player::addPlayer(Player* p)
{
	players.push_back(p);
}

vector<Player*> Player::getListOfPlayers()
{
	return players;
}
