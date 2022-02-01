#pragma once
//#include <Orders.h>
//#include <Map.h>
//#include <Cards.h>
//#include <vector>
#include <iostream>
using namespace std;


class Player
{
public:
	// contructors
	Player(); // default constructor
	Player(Player& p); //copy constructor
	~Player(); //destructor

	//methods
	Player& operator =(const Player& p);
	friend istream& operator >>(istream& ins, Player& p);
	friend ostream& operator <<(ostream& outs, const Player& p);

	void toAttack(); // method to attck; returns orders list
	void toDefend(); // method to defend; returns ordrs list
	//void issueOrder(Orders order);

private:
	//attributes/ variables
	Player playerID;
	//vector<Territory> territoryList; 
	//OrdersList orderList; OR vector<OrdersList> orderList
	//Hand hand; OR vector<Hand> hand;
};
