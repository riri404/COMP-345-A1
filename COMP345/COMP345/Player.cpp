#include "Player.h"
#include "Map.h"
#include "Cards.h"
#include <vector>

Player::Player()
{
	name = NULL;
	playerID = NULL;
	territoryList = *(new vector<Territory*>);
	cards = new Hand();
	orderList = new OrdersList();
}

Player::Player(int* playerID, string* name, vector<Territory*> territoryList, Hand* cards, OrdersList* orderlist)
{
	this->playerID = playerID;
	this->name = name;
	this->territoryList = territoryList;
	this->cards = cards;
	this->orderlist = orderlist;
}

Player::Player(const Player& p)
{
	this->playerID = p.playerID;
	this->name = p.name;
	this->territoryList = p.territoryList;
	this->cards = p.cards;
	this->orderList = p.orderList;
}

Player::~Player()
{
	delete playerID;
	playerID = nullptr;
	delete name;
	name = nullptr;
	delete cards;
	cards = nullptr;
	for (auto p : territoryList)
	{
		delete p;
	}
	territoryList.clear();

	for (auto p : orderList)
	{
		delete p;
	}
	orderList.clear();
}

Player& Player::operator=(const Player& p)
{
	this->playerID = p.playerID;
	this->name = p.name;
	this->territoryList = p.territoryList;
	this->cards = p.cards;
	this->orderList = p.orderList;
	return *this;
}

istream& operator>>(istream& ins, Player& p1)
{
	cout << "Enter name ";
	ins >> p1.name;
	cout << "Enter Cards ";
	ins >> p1.cards;
	cout << "Enter territoty list ";
	ins >> p1.territoryList;
	cout << "Enter orders lost ";
	ins >> p1.orderList;
	return ins;
}

ostream& operator<<(ostream& outs, const Player& p1)
{
	outs << p1.name;
	outs << p1.cards;
	outs << p1.territoryList;
	outs << p1.orderList;
	return outs;
}

vector<Territory*> Player::toAttack()
{

	vector<Territory*> territoriesToAttack;
	if (territoriesToAttack != territoryList) {
		for (vector<Territory*>::iterator attcked = territoriesToAttack.begin(); attcked != territoriesToAttack.end(); ++attcked) {
			territoriesToAttack.push_back(*attcked);
			std::cout << *attcked << std::endl;
		}
	}

	return territoriesToAttack;
}

vector<Territory*> Player::toDefend()
{

	vector<Territory*> territoriesToDefend = territoryList;
	for (vector<Territory*>::iterator defend = territoriesToDefend.begin(); defend != territoriesToDefend.end(); ++defend) {
		territoriesToDefend.push_back(*defend);
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

/*
void Player::issueOrder()
{
	Order* order = new Bomb();
	orderList.push_back(order);
	std::cout << *order << std::endl;
}*/