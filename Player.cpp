#pragma once
#include "Player.h"
#include "Map.h"
#include "Cards.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Player::Player()
{
	name = NULL;
	playerID = NULL;
	territoryList = *(new vector<Territory*>);
	cards = new Hand();
	list;
	//orderList = new OrdersList();
}

Player::Player(int* playerID, int reinforcementPool, string* name, vector<Territory*> territoryList, Hand* cards, OrdersList* orderlist)
{
	this->playerID = playerID;
	this->reinforcementPool = reinforcementPool;
	this->name = name;
	this->territoryList = territoryList;
	this->cards = cards;
	this->orderList = orderList;
}

Player::Player(const Player& p)
{
	this->playerID = p.playerID;
	this->reinforcementPool = p.reinforcementPool;
	this->name = new string(*(p.name));
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
	delete orderList;
	orderList = nullptr;
	for (auto p : territoryList)
	{
		delete p;
	}
	territoryList.clear();

	// Added by Justine & Jennifer
	for (auto l : list) {
		delete l;
	}
	list.clear();

	for (auto n : playerNegociate) {
		delete n;
	}
	playerNegociate.clear();

	delete deck;
	deck = nullptr;

	for (auto lp : listOfPlayers) {
		delete lp;
	}
	listOfPlayers.clear();
}

Player& Player::operator=(const Player& p)
{
	this->playerID = p.playerID;
	this->name = new string(*(p.name));
	this->reinforcementPool = p.reinforcementPool;
	this->territoryList = p.territoryList;
	this->cards = p.cards;
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
	outs << p1.playerID;
	outs << p1.name;
	outs << p1.cards;
	//outs << (p1.territoryList);
	//outs << p1.orderList;

	return outs;
}

int Player::getPlayerID() {
	return *playerID;
}

Hand* Player::getPlayerHand()
{
	return cards;
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
void Player::setName(string* n)
{
	name = n;
}
vector<Territory*> Player::getTerritoryList()
{
	return territoryList;
}

int Player::getReinforcementPool()
{
	return reinforcementPool;
}

void Player::addReinforcementPool(int i)
{
	reinforcementPool += i;
}

void Player::removeReinforcementPool(int i) {
	if (i > reinforcementPool) {
		cout << "You don't have enough reinforcement." << endl;
	}
	else {
		reinforcementPool -= i;
	}
}

void Player::setTerritory(Territory* newTerritory)
{
	territoryList.push_back(newTerritory);
}

void Player::removeTerritory(int i)
{
	this->territoryList.erase(this->territoryList.begin() + i);
}

vector<Orders*> Player::getOrdersList() {
	return list;
}

void Player::setOrder(Orders* order) {
	list.push_back(order);
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

string* Player::getName() {
	return name;
}

void Player::setPlayerName(string* n) {
	this->name = n;
	this->pName = *name;
}
void Player::addPlayer(Player* p)
{
	listOfPlayers.push_back(p);
}
vector<Player*> Player::getListOfPlayers()
{
	return listOfPlayers;
}
/*
void Player::issueOrder()
{
	Order* order = new Bomb();
	orderList.push_back(order);
	std::cout << *order << std::endl;
}*/
