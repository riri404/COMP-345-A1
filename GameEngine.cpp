#include "GameEngine.h"

Engine::Engine()
{
    state = null;
    this->map = nullptr;
    vector<Player*> players;  
    this->deck = new Deck();
    this->numOfPlayers = 0;

}

// Creates a deep copy of this GameEngine, and all of its components.
Engine::Engine(Engine& engine)
{
    state = null;
    this->map = new Map(*engine.map);
    this->players;
    for (int i = 0; i < engine.players.size(); i++)
    {
        this->players.push_back(new Player(*engine.players.at(i)));
    }
  
    this->deck = new Deck(*engine.deck);
    this->numOfPlayers = engine.numOfPlayers;
    this->state = engine.state;

}


Engine::~Engine()
{
    
    delete this->map;
    map = NULL;
    delete this->deck;
    deck = NULL;
 
    for (int i = 0; i < this->players.size(); i++)
    {
        delete this->players[i];
        this->players.at(i) = nullptr;
        
    }
    this->players.clear();
}


State Engine::GetState() 
{ 
    return state; 
}

int Engine::GetNumberOfPlayers() 
{ 
    return numOfPlayers; 
}

void Engine::SetState(State state) 
{ 
    this->state = state; 
}
void Engine::SetNumberOfPlayers(int x) 
{ 
    this->numOfPlayers = x;
}

// Returns all the players in the game in their order of play.
std::vector<Player*> Engine::GetPlayers() { return players; }

std::vector<Player*>* Engine::GetPlayersAdress() { return &players; }


// Returns a pointer to the game map.
Map* Engine::GetMap() { return map; }


//=================== StartUp Phase===================================

void Engine::StartGame() {

    state = start;
    cout << "Welcome to Warzone" << endl;
    cout << "end of start phase" << endl;

    LoadMap();
    AddPlayer();
}


void Engine::LoadMap() {
    state = mapLoaded;

    MapLoader* mapLoader = new MapLoader();

    /* 1. Select a map and load it. */

    string mapName;
    string fileName;

    std::cout << "Available maps:"
                <<"\n---------------------------\n"
                    << "bigeurope.map";

   
    // Loops until the user enters a valid map
    do {
        cout << "\nEnter the name of a map to choose it: ";
        cin >> mapName;
        fileName = "src/Maps/" + mapName + ".map";
        *map = mapLoader->LoadMap(fileName);

      //  if (map == nullptr)
        if(false) // added for debugging
            cout << "Please try again." << endl;
        else {
            cout << "end of load map phase" << endl;
            Engine::ValidateMap();
        }

        

    } while (map == nullptr);

    // Delete the map loader
    delete mapLoader;
}


void Engine::ValidateMap() {

    state = mapValidated;
    bool validMap = false;
    do {

        //validMap = map->ValidateMap();
        validMap = true; // added for debugging
        if (!validMap) cout << "Not a valid map, please try again\n";

    } while (!validMap);

    cout << "end of validate map phase" << endl;
   
}

void Engine::AddPlayer() {

    cout << "Please enter the number of players" << endl;
    cin >> this->numOfPlayers;
    // Allocating the right number of space in the vector
    players.reserve(numOfPlayers);

    state = playersAdded;
    for (int i = 0; i < numOfPlayers; i++) {
        string name;
        Player* player = new Player();
        cout << "Please enter the player's name" << endl;
        cin >> name;
        player->SetName(name);
        players.push_back(player);
        cout << "\nPlayer " << i + 1
            << " has been created. " << std::endl;
    }
    cout << "end of add player phase" << endl;

}



// Adds troops to a player's reinforcement pool at the start of the turn.

void Engine::ReinforcementPhase() {
    state = assignReinforcement;
   
        cout << "Starting Reinforcement Phase..." << endl;
        for (auto player : players)
        {
            vector<Territory*> playerTerritories = player->GetTerritoryList();
            int baseArmySize = playerTerritories.size() / 3;
            // Gent Bounus value
            // int continentBonus = findContinentBonusTotal(player);
            //int armiesToGive = continentBonus + baseArmySize;
            int reinforcementArmySize = baseArmySize;

            if (reinforcementArmySize < 3) reinforcementArmySize = 3;

         
            /*    string message = "give armies";
                string armies = to_string(reinforcementArmySize);
                string id = to_string(player->GetPlayerID());
                string baseArmies = to_string(baseArmySize);
                string continentB = to_string(continentBonus);
                this->notify(message + " " + armies + " " + id + " " + baseArmies + " " + continentB);*/

        //    player->AddArmies(reinforcementArmySize); //Using add and not set because of the initial armies given from setup. Will always be 0 at start of a turn.

        }
    cout << "end of add player phase" << endl;

};


// Calls IssueOrder until all players have commited that they are done issuing orders.

void Engine::IssueOrdersPhase(Player* player) {
    state = issueOrder;

   
    cout << "Starting Issue Orders Phase..." << endl; 
    
    for (auto player : players)
    {  
        // player->issueOrder(this, map, deck);
    }
    cout << "end of issue orders phase" << endl;
}


// Calls ExecuteOrder() until all players have no more orders in their orders list.

void Engine::ExecuteOrdersPhase() {
    state = ExecuteOrders;
  
        
    cout << "Starting Execute Orders Phase..." << endl;

    for (auto player : players)
    {
        // player->ExecuteOrders(this, map, deck);
    }
    cout << "end of execute orders phase" << endl;
}



//
//void Engine::LoadDeck() {
//
//    /* 4. Create a deck of cards. */
//    deck = new Deck();
//    // deck->addCard(new BombCard(deck));
//    // deck->addCard(new ReinforcementCard(deck));
//
//    // Displaying the deck information to the user
//    std::cout << "\nA deck of 10 cards has been created. "
//        << std::endl;
//}

void Engine::PlayerDrawCard(Player* player) {

}


// ==============================Play Phase===================================
void Engine::MainGameLoop() {

    cout << "Starting Main Game Loop..." << endl;

        while (true) {
            ReinforcementPhase();
            IssueOrdersPhase();
            ExecuteOrdersPhase();
            // Eliminate players who don't have any more territories.
            for (int i = players.size() - 1; i >= 0; i--) {
                if (false/* player has no more territories */) {
                    cout << "A player has been eliminated." << endl;
                   
                        players.erase(players.begin() + i);
                }
            }
            // If a player controls all territories, they win the game.
            if (players.size() < 2) {
                cout << "There's only one player left." << endl;

             
                    if (false /*players.at(0)->player controls all territories*/) {
                        cout << "Exiting Main Game Loop." << endl;
                        
                        return;
                    }
            }
        }
}

