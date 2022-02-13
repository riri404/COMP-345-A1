#pragma once

#include "Player.h"
#include "Cards.h"
//#include "Orders.h"
//#include "Map.h"
//#include <vector>
//#include "Deck.h"
//#include "MapLoader.h"


using namespace std;

// enum Phase {StartUp, Play };

enum State {
	null, start, mapLoaded, mapValidated, playersAdded,
	assignReinforcement, issueOrder, ExecuteOrders, win
};

class Engine {

public:

	// constructors

	Engine();
	Engine(Engine& engine);
	~Engine();

	// Mutators

	State GetState();
	int GetNumberOfPlayers();
	vector<Player*> GetPlayers();
	vector<Player*>* GetPlayersAdress();
	Map* GetMap();
	Deck* GetDeck();
	void SetState(State);
	void SetNumberOfPlayers(int);


	// void Init();
	void StartGame();

	void LoadMap();
	void ValidateMap();
	void AddPlayer();
	void IssueOrdersPhase();
	void IssueOrdersPhase(Player* player);

	void MainGameLoop();
	void StartupPhase();
	void ReinforcementPhase();

	void ExecuteOrdersPhase();
	void ExecuteOrdersPhase(Player* player);


	void PlayerDrawCard(Player* player);


private:
	Map* map;
	vector<Player*> players;
	Deck* deck;
	int numOfPlayers;
	State state;
};