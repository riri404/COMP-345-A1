#include "GameEngine.h"
using namespace std;

GameEngine::GameEngine()
{
    state = State::null;
    this->map = nullptr;
    vector<Player*> players;
    this->deck = new Deck();
    this->numOfPlayers = 0;

}

// Creates a deep copy of this GameEngine, and all of its components.
GameEngine::GameEngine(GameEngine& engine)
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

GameEngine::~GameEngine()
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

State GameEngine::GetState()
{
    return state;
}

void GameEngine::SetState(State state)
{
    this->state = state;
}

int GameEngine::GetNumberOfPlayers()
{
    return numOfPlayers;
}

void GameEngine::SetNumberOfPlayers(int x)
{
    this->numOfPlayers = x;
}

// Returns all the players in the game in their order of play.
std::vector<Player*> GameEngine::GetPlayers() 
{ return players; }

std::vector<Player*>* GameEngine::GetPlayersAdress() 
{ return &players; }


// Returns a pointer to the game map.
Map* GameEngine::GetMap() 
{ return map; }

// Stream insertion operator
ostream& operator<<(ostream& os, const GameEngine& gameEngine) {
    string p = "";
    for (Player* i : gameEngine.players) {
      //  p += (*i).getName() + " | ";
    }

    return os <<
        "GAME ENGINE: Current state: " << gameEngine.state <<
        "\n    Players (" << gameEngine.numOfPlayers << "): " << endl << p.substr(0, p.length() - 2) << endl;
      //  "\n    Number of Territories : (" << gameEngine.NumberOfTerritories << ")" << endl;
}



// Get String between two delimiter String
// https://stackoverflow.com/questions/18800796/c-get-string-between-two-delimiter-string
string GameEngine::get_str_between_two_str(const std::string& s,
                                              const std::string& start_delim,
                                                const std::string& stop_delim)
{
    unsigned first_delim_pos = s.find(start_delim);
    unsigned end_pos_of_first_delim = first_delim_pos + start_delim.length();
    unsigned last_delim_pos = s.find(stop_delim);

    return s.substr(end_pos_of_first_delim,
        last_delim_pos - end_pos_of_first_delim);
}


string GameEngine::SelectName(string command) {
    
    return GameEngine::get_str_between_two_str(command, "<", ">");
}

void GameEngine::StartupPhase() {
    cout << "Welcome to Warzone" << endl << endl;

    StartGame();
    LoadMap();
    cout << "use the \"validatemap\" command to validate the map" << endl << endl;
    bool validMap = false;
    validMap = GameEngine::ValidateMap();
    AddPlayer();
}


//=================== StartUp Phase===================================

void GameEngine::StartGame() {
    Notify(this);

    state = State::start;   
    cout << "GamePhase: start" << endl;

    cout << "starting game..." << endl << endl;


    // show a list of available maps
    std::cout << "Available maps:"
        << "\n---------------------------\n"
        << "bigeurope" << endl
        << "bigeurope2 (invalid)" << endl
        << "invalid (lol)" << endl
        << "sw_baltic"
        << "\n---------------------------\n"
        << endl;


    // Select a map and load it
    string command;
    string mapName;
    string fileName;

    do {
    cout << "use the \"loadmap <filename>\" command to select a map" << endl << endl;
   
    cin >> command;

    mapName = SelectName(command);

    fileName = "source_maps/" + mapName + ".map";

    map = new Map(fileName);

    if (!map->isMapLoaded())
        cout << "Please try again." << endl;
    else {
        cout << endl << "The chosen map has been loaded" << endl;   
    }

    if (map->isMapLoaded()) {
        state = State::mapLoaded;
        cout << "GamePhase: map loaded" << endl;
        Notify(this);
    }

    } while (map == nullptr || !map->isMapLoaded());
    
}


void GameEngine::LoadMap() {
 
    //string mapName;
    //string fileName;

    //bool validMap = false;

    //// Loops until the user enters a valid map
    //do {
    //    cout << "\nEnter the name of a map to choose it: ";

    //    cin >> mapName;

    //    fileName = "source_maps/" + mapName + ".map";

    //    map = new Map(fileName);

    //    if (!map->isMapLoaded())
    //        cout << "Please try again." << endl;
    //    else {
    //        cout<< endl << "The chosen map has been loaded"<< endl;
    //        cout << "end of load map phase" << endl<< endl;
    //        state = State::mapLoaded;
    //        Notify(this);

    //        validMap = GameEngine::ValidateMap();
    //    }

    //} while (map == nullptr || !validMap);
   
}


bool GameEngine::ValidateMap() {
    
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
        cout << "GamePhase: map validated" << endl;
        Notify(this);
        return true;
    }

}

void GameEngine::AddPlayer() {

    string command;
    string playerName;
    int numberOfPlayers = 0;



    
    cout << "use the \"addplayer <playername>\" command to enter players in the game (2-6 players)" << endl << endl;

    cin >> command;

    playerName = SelectName(command);

    Player* player = new Player();
  
    player->setName(playerName);
    players.push_back(player);
    numberOfPlayers++;
    

    cout << "Player " << numberOfPlayers << " has been created. " << endl;


    state = State::playersAdded;
    cout << "GamePhase: players added" << endl;
    Notify(this);
    

    ////////////////////////////////////////////////////

//    cout << "Please enter the number of players" << endl;
//    cin >> this->numOfPlayers;
    // Allocating the right number of space in the vector
//    players.reserve(numOfPlayers);

    for (int i = 0; i < numOfPlayers; i++) {
   /*     string name;
        Player* player = new Player();
        cout << endl << "Please enter the player's name" << endl;
        cin >> name;
        player->setName(name);
        players.push_back(player);
        cout << "Player " << i + 1
             << " has been created. " << endl;*/
    }
   // cout << endl << "end of add player phase" << endl<< endl;
    
    ReinforcementPhase();
}



// Adds troops to a player's reinforcement pool at the start of the turn.

void GameEngine::ReinforcementPhase() {
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

void GameEngine::IssueOrdersPhase() {
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

void GameEngine::ExecuteOrdersPhase() {
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

void GameEngine::PlayerDrawCard(Player* player) {

}


// ==============================Play Phase===================================
void GameEngine::MainGameLoop() {

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

std::string GameEngine::stringToLog() {
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


