#pragma once
#include "Orders.h"
#include "Map.h"
#include "Cards.h"
#include <vector>
#include <iostream>
using namespace std;

class Orders;
class OrderList;
class Card;
class Hand;

void PlayerDriver();

class Player
{
public:
	// contructors
	Player(); // default constructor
	Player(int* id,string* name, vector<Territory*> territoryList, Hand* cards, OrdersList* orderlist); //Constructor
	Player(const Player& p); //copy constructor
	~Player(); //destructor

	// operators
	Player& operator =(const Player& p);
	friend istream& operator >>(istream& ins, Player& p);
	friend ostream& operator <<(ostream& outs, const Player& p);

	//methods
	vector<Territory*> toAttack(); // method to attck; returns orders list
	vector<Territory*> toDefend(); // method to defend; returns ordrs list
	void issueOrder(string order);
	//void setOrder(Orders*);


private:
	//attributes/ variables
	string* name;
	int* playerID;
	vector<Territory*> territoryList; 
	OrdersList* orderList;
	Hand* cards; 

};
