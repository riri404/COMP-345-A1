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

using namespace std;

void EngineDriver();



// enum Phase {StartUp, Play };

enum State {
	null, start, mapLoaded, mapValidated, playersAdded,
	reinforcementPhase, issueOrderPhase, executeOrderPhase, win
};

class GameEngine: public Subject, public ILoggable {

public:

	// constructors

	GameEngine();
	GameEngine(GameEngine& engine);

	//Destructor:
	~GameEngine();


	//Assignment operator
	GameEngine& operator =(const GameEngine& other);


	//Stream insertion
	friend ostream& operator << (ostream& out, const GameEngine& g);



	// Mutators

	void SetState(State);
	State GetState();

	Map* GetMap();

	Deck* GetDeck();


	void AddPlayer();
	int GetNumberOfPlayers();
	vector<Player*> GetPlayers();
	vector<Player*>* GetPlayersAdress();
	
	
	
	void SetNumberOfPlayers(int);


	// void Init();
	void StartGame();

	void LoadMap();
	bool ValidateMap();
	
	void IssueOrdersPhase();
	void IssueOrdersPhase(Player* player);

	void MainGameLoop();
	void StartupPhase();
	void ReinforcementPhase();

	void ExecuteOrdersPhase();
	void ExecuteOrdersPhase(Player* player);


	void PlayerDrawCard(Player* player);
	
	std::string stringToLog();



	string GameEngine::SelectName(string command);
	


private:
	Map* map;
	vector<Player*> players;
	Deck* deck;
	int numOfPlayers;
	State state;
	string get_str_between_two_str(const std::string& s,
		const std::string& start_delim,
		const std::string& stop_delim);
};