#pragma once

#include "Player.h"
#include "Cards.h"
#include "Orders.h"
#include "Map.h"
#include <vector>
#include <string>
//#include "Deck.h"
//#include "MapLoader.h"
#include "LoggingObserver.h"


void EngineDriver();

using namespace std;

class Deck;

// enum Phase {StartUp, Play };

enum class State {
	null, start, mapLoaded, mapValidated, playersAdded,
	reinforcementPhase, issueOrderPhase, executeOrderPhase, win
};

class Engine : public Subject, public ILoggable {

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
	//Deck* GetDeck();
	void SetState(State);
	void SetNumberOfPlayers(int);


	// void Init();
	void StartGame();

	void LoadMap();
	bool ValidateMap();
	void AddPlayer();
	void IssueOrdersPhase();
	//void IssueOrdersPhase(Player* player);

	void MainGameLoop();
	//void StartupPhase();
	void ReinforcementPhase();

	void ExecuteOrdersPhase();
	//void ExecuteOrdersPhase(Player* player);


	void PlayerDrawCard(Player* player);

	std::string stringToLog();

private:
	Map* map;
	vector<Player*> players;
	Deck* deck;
	int numOfPlayers;
	State state;
};