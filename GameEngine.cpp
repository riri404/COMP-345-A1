#pragma once

#include "GameEngine.h"



#define MGL_DRIVER
#ifdef MGL_DRIVER
#define STOP std::cin.get();
#define LOG(x) std::cout << "[Main Game Loop Log] " << x << std::endl
#else
#define STOP
#define LOG(X)
#endif

GameEngine::GameEngine()
    : deck(),  map(nullptr){}

// Part 1: Game Start.
void GameEngine::Init() {
    /* 1. Select a map and load it. */
    std::string mapName;
    std::string fileName;
    MapLoader* mapLoader = new MapLoader();
    std::cout << "Here are the available maps:\n---------------------------\n"
        << "map1.map\nmap2.map\nmap3.map";

    // Loops until the user enters a valid map
    bool validMap = false;
    do {
        std::cout << "\nEnter the name of a map to choose it: ";
        std::cin >> mapName;
        fileName = "src/Maps/" + mapName;
       // map = mapLoader->LoadMap(fileName);

        if (map == nullptr)
            std::cout << "Please try again." << std::endl;
        else {
          //  validMap = map->ValidateMap();
            if (!validMap) std::cout << "Not a valid map, please try again\n";
        }

    } while (map == nullptr || !validMap);

    // Deleting the map loader
    delete mapLoader;

    /* 2. Select number of Players. */
    int num_players;

    // Loops until the user enters a valid number of players
    do {
        std::cout << "\nEnter the number of players (2-5) : ";
        std::cin >> num_players;

        if (num_players < 2 || num_players > 5)
            std::cout << "Incorrect number of players, try again." << std::endl;
    } while (num_players < 2 || num_players > 5);

    // Allocating the right number of space in the vector
    players.reserve(num_players);


    /* 3. Create Players. */
    for (int i = 0; i < num_players; i++) {
        players.push_back(new Player());

 

        std::cout << "\nPlayer " << i + 1
            << " has been created. " << std::endl;
    }


    /* 4. Create a deck of cards. */
    deck = new Deck();
   
   // deck->addCard(new BombCard(deck));
   // deck->addCard(new ReinforcementCard(deck));


    // Displaying the deck information to the user
    std::cout << "\nA deck of 10 cards has been created. "
        << std::endl;  
}

// Part 2: Game Startup
void GameEngine::StartupPhase() {



    
}

// Part 3. Main Game Loop
void GameEngine::MainGameLoop() {
    LOG("Starting Game Loop...");
    STOP
        while (true) {
            ReinforcementPhase();
            IssueOrdersPhase();
            ExecuteOrdersPhase();
            // Eliminate players who don't have any more territories.
            for (int i = players.size() - 1; i >= 0; i--) {
                if ( false/* player has no more territories */) {
                    LOG("A player has been eliminated.");
                    STOP
                        players.erase(players.begin() + i);
                }
            }
            // If a player controls all territories, they win the game.
            if (players.size() < 2) {
                LOG("There's only one player left.");
                STOP
                    if (false /*players.at(0)->player controls all territories*/) {
                     
                        LOG("Exiting Main Game Loop.");
                        return;
                    }
            }
        }
}

/*
Adds troops to a player's reinforcement pool at the start of the turn.
*/
void GameEngine::ReinforcementPhase() {
    LOG("Starting Reinforcement Phase...");
    STOP
}



// Returns all the players in the game in their order of play.
std::vector<Player*> GameEngine::getPlayers() { return players; }

std::vector<Player*>* GameEngine::getPlayersAdress() { return &players; }

/*
Calls IssueOrder until all players have commited that they are done issuing orders.
*/
void GameEngine::IssueOrdersPhase() {
    LOG("Starting Issue Orders Phase...");
    STOP
}

/*
Calls ExecuteOrder() until all players have no more orders in their orders list.
*/
void GameEngine::ExecuteOrdersPhase() {
    LOG("Starting Execute Orders Phase...");
    STOP
}

// Returns a pointer to the game map.
Map* GameEngine::GetMap() { return map; }

void GameEngine::PlayerDrawCard(Player* player) {
    
}



// Destructor
GameEngine::~GameEngine() {
    for (Player* p : players) {
        delete p;
        p = nullptr;
    }
    players.clear();
   

    delete neutralPlayer;
    neutralPlayer = nullptr;
    delete map;
    map = nullptr;
    delete deck;
    deck = nullptr;
}
