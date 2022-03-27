#pragma once
#include "Player.h"
#include "Map.h"
#include "Cards.h"
#include "LoggingObserver.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Order;
class OrdersList;
class Cards;
class Hand;
class Deck; // Added by Justine & Jennifer

void PlayerDriver();

class Player
{
public:
	// contructors
	Player(); // default constructor
	Player(int* id, int*, string* name, vector<Territory*> territoryList, Hand* cards, OrdersList* orderlist); //Constructor
	Player(const Player& p); //copy constructor
	~Player(); //destructor

	// operators
	Player& operator =(const Player& p);
	friend istream& operator >>(istream& ins, Player& p);
	friend ostream& operator <<(ostream& outs, const Player& p);

	//methods
	vector<Territory*> toAttack(vector<Territory*> attack); // method to attck; returns orders list
	vector<Territory*> toDefend(); // method to defend; returns ordrs list
	void issueOrder(string order);
	void setName(const string& name);
	void setPlayerID(const int& playerID);
	vector<Territory*> getTerritoryList();
	bool playerContinentBouns(); 
	//void setOrder(Orders*);
	string GetPlayerName() const;
	int GetPlayerID() const;
	void addTerritory(Territory*);
	void addToReinforcePool(int armies); // Add to reinforcement pool
	void removeFromReinforcePool(int armies); // Remove from reinforcement pool
	int getReinforcementPool();
	void setReinforcementPool(int);
	void AddCard(Cards*);
	void Attach(LogObserver* observer);


	// Added & modified by Justine & Jennifer 
	void setTerritory(Territory*);
	void removeTerritory(int i);
	Hand* getPlayerHand();

	OrdersList* getOrdersList();
	void setOrder(Order* order);

	void addNegociate(Player* p);
	bool isNegociating(Player* p);

	void addPlayer(Player* p);
	vector<Player*> getListOfPlayers();

private:
	//attributes/ variables
	string* name;
	int* reinforcementPool;
	int* playerID;
	vector<Territory*> territoryList;
	OrdersList* orderList;
	Hand* handCards;

	vector<Player*> players;

	// Added by Justine & Jennifer 
	// vector<Order*> list;  we already have orderList
	vector<Player*> playerNegociate;
	Deck* deck;
	string pName;
};
