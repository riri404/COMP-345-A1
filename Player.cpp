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
	outs << "Player ID: " << *(p1.playerID) << endl;
	outs << "Player's name: " << *(p1.name) << endl;
	//outs << "Player's cards: " << p1.handCards << endl;
	outs << "Player's cards: ";
	p1.handCards->printHand();
	outs << "Player's reinforcement pool" << *(p1.reinforcementPool) << endl;;
	//outs << (p1.territoryList);
	//outs << p1.orderList;

	return outs;
}

vector<Territory*> Player::toAttack()
{
	vector<Territory*> territoriesToAttack;
	if (territoriesToAttack != territoryList) {
		for (auto it = territoriesToAttack.begin(); it != territoriesToAttack.end(); ++it) {
			territoriesToAttack.push_back(*it);
			std::cout << *it << std::endl;
		}
	}

	return territoriesToAttack;
}

vector<Territory*> Player::toDefend()
{

	vector<Territory*> territoriesToDefend = territoryList;

	for (auto defend = territoriesToDefend.begin(); defend != territoriesToDefend.end(); ++defend) {
		// territoriesToDefend.push_back(*defend);
		std::cout << *defend << std::endl;
	}
	return territoriesToDefend;
}

void Player::issueOrder(string order)
{
	if (order == "Deploy") {
		Deploy* deploy = new Deploy();
		orderList->addToListOfOrders(deploy);
	}
	else if (order == "Advance") {
		Advance* advance = new Advance();
		orderList->addToListOfOrders(advance);
	}
	else if (order == "Bomb") {
		Bomb* bomb = new Bomb();
		orderList->addToListOfOrders(bomb);
	}
	else if (order == "Blockade") {
		Blockade* block = new Blockade();
		orderList->addToListOfOrders(block);
	}
	else if (order == "Airlift") {
		Airlift* air = new Airlift();
		orderList->addToListOfOrders(air);
	}
	else if (order == "Negotiate") {
		Negotiate* negotiate = new Negotiate();
		orderList->addToListOfOrders(negotiate);
	}
	else {
		cout << "Error! Please enter one of the following orders: 1. Deploy, 2. Advance, 3. Bomb, 4. Blockade, 5 Airlift, 6. Negotiate." << endl;
	}
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


string Player::GetPlayerName() const {
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

// Changed by justine & jennifer, old version wasn't working, generated negative number
void Player::addToReinforcePool(int armies) {
	*reinforcementPool = *reinforcementPool + armies;
}

void Player::removeFromReinforcePool(int armies) {
	*reinforcementPool = *reinforcementPool - armies;
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

	// When add a player to the list that contains all the players, then we also add the territories that have been assigned to the player.
	for (int i = 0; i < p->getTerritoryList().size(); i++) {
		addTerritory(p->getTerritoryList().at(i));
	}
}

vector<Player*> Player::getListOfPlayers()
{
	return players;
}

vector<Territory*> Player::getListToDefend()
{
	return defendTerritories;
}

vector<Territory*> Player::getListToAttack()
{
	return attackTerritories;
}

void Player::addTerritoryToDefend(Territory* t)
{
	defendTerritories.push_back(t);
}

void Player::addTerritoryToAttack(Territory* t)
{
	attackTerritories.push_back(t);
}

void Player::printToDefend()
{
	cout << "Player " << GetPlayerName() << "'s list of territories to defend: " << endl;
	if (!defendTerritories.empty())
	{
		for (Territory* t : defendTerritories)
		{
			cout << "\t" << t->getName() << " with " << t->getArmies() << " armie units." << endl;
		}
	}
	else {
		cout << "Player " << GetPlayerName() << " has no territories to defend." << endl;
	}
}

void Player::printToAttack()
{
	cout << "Player " << GetPlayerName() << "'s list of territories to attack: " << endl;
	if (!attackTerritories.empty())
	{
		for (Territory* t : attackTerritories)
		{
			cout << "\t" << t->getName() << " belonging to player " << t->getPlayerOwner()->GetPlayerName() << " with " << t->getArmies() << " armie units. " << endl;
		}
	}
	else {
		cout << "Player " << GetPlayerName() << " has no territories to attack." << endl;
	}
}
