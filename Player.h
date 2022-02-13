#pragma once
#include "Orders.h"
#include "Map.h"
#include "Cards.h"
#include <vector>
#include <iostream>
using namespace std;
class Order;

class Player
{
public:
	// contructors
	Player(); // default constructor
	// Player(); // default constructor
	Player(Player& p); //copy constructor
	~Player(); //destructor

	//methods
	Player& operator =(const Player& p);
	friend istream& operator >>(istream& ins, Player& p);
	friend ostream& operator <<(ostream& outs, const Player& p);

	vector<Territory*> GetTerritoryList(); // method to attck; returns orders list
	vector<Territory*> toAttack(); // method to attck; returns orders list
	vector<Territory*> toDefend(); // method to defend; returns ordrs list
	//void issueOrder(Orders order);
	void SetName(string n);


private:
	//attributes/ variables
	string* name;
	Player* playerID;
	vector<Territory*> territoryList;
	OrdersList* orderList;
	Hand* cards;

	//friend classes
	friend class Card;
	friend class GameEngine;
	friend class Map;

};
