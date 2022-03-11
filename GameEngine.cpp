#include "GameEngine.h"

Engine::Engine()
{
    state = State::null;
    this->map = nullptr;
    vector<Player*> players;
    this->deck = new Deck();
    this->numOfPlayers = 0;

}

// Creates a deep copy of this GameEngine, and all of its components.
Engine::Engine(Engine& engine)
{
    state = State::null;
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

    state = State::start;
    cout << "Welcome to Warzone" << endl<< endl;

    cout << "beginning start phase" << endl;
    cout << "starting game..." << endl << endl;

    Notify(this);

    LoadMap();
    AddPlayer();
}


void Engine::LoadMap() {
    cout << "Starting Load Map Phase..." << endl;

    // MapLoader* mapLoader = new MapLoader();

    /* 1. Select a map and load it. */

    string mapName;
    string fileName;

    bool validMap = false;

    std::cout << "Available maps:"
        << "\n---------------------------\n"
        << "bigeurope" << endl
        << "bigeurope2 (invalid)" << endl
        << "invalid (lol)" << endl
        << "sw_baltic"
        << "\n---------------------------\n"
        << endl;


    // Loops until the user enters a valid map
    do {
        cout << "\nEnter the name of a map to choose it: ";
        cin >> mapName;
        fileName = "source_maps/" + mapName + ".map";
       // *map = mapLoader-> new Map(fileName);
        map = new Map(fileName);

      //  map = mapLoader.loadMap(filename)
       // map = map->load(fileName);

       // Map* map = new Map(name);             // valid map
      /*  if (map->validate()) cout << "MAP : " << mapName << " is valid !" << endl;
        else cout << "MAP : " << mapName << " is not valid !!" << endl;*/
      //  bool mapLoaded = mapLoader->loadMap(map, fileName);
        //if (false) // added for debugging
        
        
       // if (map == nullptr)
        if (!map->isMapLoaded())
            cout << "Please try again." << endl;
        else {
            cout<< endl << "The chosen map has been loaded"<< endl;
            cout << "end of load map phase" << endl<< endl;
            state = State::mapLoaded;
            Notify(this);

            validMap = Engine::ValidateMap();
        }



    } while (map == nullptr || !validMap);
   
    // Delete the map loader
  //  delete mapLoader;
}


bool Engine::ValidateMap() {
    cout << "Starting Validate Map Phase..." << endl;

    cout << "Validating loaded map" << endl;
    bool validMap = false;
    
    validMap = map->validate();
       // validMap = true; // added for debugging
      
    if (!validMap)
    {
        cout << "Not a valid map, please try again\n"; 
        return false;
    }
    else
    {
        cout << "end of validate map phase" << endl<< endl;
        state = State::mapValidated;
        Notify(this);
        return true;
    }

    AddPlayer();

}

void Engine::AddPlayer() {

    cout << "Starting Add Player Phase..." << endl;

    cout << "Please enter the number of players" << endl;
    cin >> this->numOfPlayers;
    // Allocating the right number of space in the vector
    players.reserve(numOfPlayers);

    for (int i = 0; i < numOfPlayers; i++) {
        string name;
        Player* player = new Player();
        cout << endl << "Please enter the player's name" << endl;
        cin >> name;
     //   player->SetName(name);
        players.push_back(player);
        cout << "Player " << i + 1
             << " has been created. " << endl;
    }
    cout << endl << "end of add player phase" << endl<< endl;
    state = State::playersAdded;
    Notify(this);
    ReinforcementPhase();
}



// Adds troops to a player's reinforcement pool at the start of the turn.

void Engine::ReinforcementPhase() {
    state = State::reinforcementPhase;
    Notify(this);

    cout << "Starting Reinforcement Phase..." << endl;
    for (auto player : players)
    {



        //vector<Territory*> playerTerritories = player->GetTerritoryList();
        //int baseArmySize = playerTerritories.size() / 3;
        //Gent Bounus value
        //int continentBonus = findContinentBonusTotal(player);
        //int armiesToGive = continentBonus + baseArmySize;
        //int reinforcementArmySize = baseArmySize;

        //if (reinforcementArmySize < 3) reinforcementArmySize = 3;


        // string message = "give armies";
        // string armies = to_string(reinforcementArmySize);
        // string id = to_string(player->GetPlayerID());
        // string baseArmies = to_string(baseArmySize);
        // string continentB = to_string(continentBonus);
        // this->notify(message + " " + armies + " " + id + " " + baseArmies + " " + continentB);

        // player->AddArmies(reinforcementArmySize); //Using add and not set because of the initial armies given from setup. Will always be 0 at start of a turn.

    }
    cout << endl << "end of Reinforcement phase" << endl << endl;
    IssueOrdersPhase();
}


// Calls IssueOrder until all players have commited that they are done issuing orders.

void Engine::IssueOrdersPhase() {
    state = State::issueOrderPhase;
    Notify(this);

    cout << "Starting Issue Orders Phase..." << endl;

    for (auto player : players)
    {
        // player->issueOrder(this, map, deck);
    }
    cout << "end of issue orders phase" << endl << endl;

    ExecuteOrdersPhase();
}


// Calls ExecuteOrder() until all players have no more orders in their orders list.

void Engine::ExecuteOrdersPhase() {
    state = State::executeOrderPhase;
    Notify(this);


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

std::string Engine::stringToLog() {
    std::string log = "";
    switch (state) {
        case State::start:
            log = "Starting game";
            break;
        case State::mapLoaded:
            log = "Map loaded";
            break;
        case State::mapValidated:
            log = "Map validated";
            break;
        case State::playersAdded:
            log = "Players added";
            break;
        case State::reinforcementPhase:
            log = "Reinforcement phase";
            break;
        case State::issueOrderPhase:
            log = "Issue order phase";
            break;
        case State::executeOrderPhase:
            log = "Execute order phase";
            break;
    }
    return log;
}




















