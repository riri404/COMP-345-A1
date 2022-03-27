#pragma once
#include "Player.h"
#include "Map.h"
#include "Cards.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Orders;
class OrdersList;
class Cards;
class Hand;
class Deck;

void PlayerDriver();

class Player
{
public:
	// contructors
	Player(); // default constructor
	//Player(string);
	Player(int* id, int reinforcementPool, string* name, vector<Territory*> territoryList, Hand* cards, OrdersList* orderlist); //Constructor
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
	void setName(string* name);
	vector<Territory*> getTerritoryList();
	//void setOrder(Orders*);

	// Added & modified by Jennifer 
	int getReinforcementPool();
	void addReinforcementPool(int i);
	void removeReinforcementPool(int i);

	// Added By Justine & Jennifer
	void setTerritory(Territory*);
	void removeTerritory(int i);
	int getPlayerID();
	Hand* getPlayerHand();

	vector<Orders*> getOrdersList();
	void setOrder(Orders* order);


	void addNegociate(Player* p);
	bool isNegociating(Player* p);

	string* getName();
	void setPlayerName(string* n);
	vector<Hand*> playerHand;

	void addPlayer(Player* p);
	vector<Player*> getListOfPlayers();

private:
	//attributes/ variables
	string* name;
	int reinforcementPool; // Modified by Jennifer
	int* playerID;
	vector<Territory*> territoryList;
	OrdersList* orderList;
	Hand* cards;

	// Added by Justine & Jennifer 
	vector<Orders*> list;
	vector<Player*> playerNegociate;
	Deck* deck;
	string pName;
	vector<Player*> listOfPlayers;
};
