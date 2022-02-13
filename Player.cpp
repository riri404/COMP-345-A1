#include "Player.h"
#include "Map.h"
#include "Cards.h"
#include <vector>

Player::Player()
{
	SetName("default");
	//name = "default";
	playerID = NULL;
	territoryList = *(new vector<Territory*>);
	cards = new Hand();
	orderList = new OrdersList();
}

Player::Player(Player& p)
{
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

	//for (auto p : orderList)
	//{
	//	delete p;
	//}
	//orderList.clear();
}

void Player::SetName(string n) 
{ 
	name = &n; 
}

Player& Player::operator=(const Player& player)
{
	this->name = player.name;
	this->territoryList = player.territoryList;
	this->cards = player.cards;
	this->orderList = player.orderList;
	return *this;
}

//istream& operator>>(istream& ins, Player& p1)
//{
//	//cout << "Enter name ";
//	//ins >> p1.name;
//	//cout << "Enter Cards ";
//	//ins >> p1.cards;
//	//cout << "Enter territoty list ";
//	//ins >> p1.territoryList;
//	//cout << "Enter orders lost ";
//	//ins >> p1.orderList;
//	//return ins;
//}

ostream& operator<<(ostream& outs, const Player& p1)
{
	outs << p1.name;
	outs << p1.cards;
	//outs << p1.territoryList;
	outs << p1.orderList;
	return outs;
}

vector<Territory*> Player::toAttack()
{

	vector<Territory*> territoriesToAttack;
	for (vector<Territory*>::iterator it = territoriesToAttack.begin(); it != territoriesToAttack.end(); ++it) {
		territoriesToAttack.push_back(*it);
		std::cout << *it << std::endl;
	}

	return territoriesToAttack;
}

vector<Territory*> Player::toDefend()
{

	vector<Territory*> territoriesToDefend;
	for (vector<Territory*>::iterator it = territoriesToDefend.begin(); it != territoriesToDefend.end(); ++it) {
		territoriesToDefend.push_back(*it);
		std::cout << *it << std::endl;
	}
	return territoriesToDefend;
}


//void Player::issueOrder()
//{
//	Order* order = new Bomb();
//	orderList.push_back(order);
//	std::cout << *order << std::endl;
//}