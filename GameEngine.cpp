#include "GameEngine.h"
using namespace std;

GameEngine::GameEngine()
{
    state = State::null;
    this->map = nullptr;
    vector<Player*> players;
    this->deck = new Deck();
    this->numberOfPlayers = 0;
    this->NumberOfTerritories = 0;

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
    this->numberOfPlayers = engine.numberOfPlayers;
    this->NumberOfTerritories = engine.NumberOfTerritories;
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
    return numberOfPlayers;
}

void GameEngine::SetNumberOfPlayers(int nop)
{
    this->numberOfPlayers = nop;
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
        p += (*i).GetPlayerName() + " | ";
    }

    return os <<
        "GAME ENGINE: Current state: " << gameEngine.state <<
        "\n    Players (" << gameEngine.numberOfPlayers << "): " << endl << p.substr(0, p.length() - 2) << endl<<
        "\n    Number of Territories : (" << gameEngine.NumberOfTerritories << ")" << endl;
}



// Get String between two delimiter String
// https://stackoverflow.com/questions/18800796/c-get-string-between-two-delimiter-string
string GameEngine::get_str_between_two_str(const string& s,
                                              const string& start_delim,
                                                const string& stop_delim)
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

    Start();
    LoadMap();
    ValidateMap();
    AddPlayers();
    GameStart();
}





//=================== StartUp Phase===================

void GameEngine::Start() {
    state = State::start;   
    cout << "GamePhase: start" << endl << endl;
    Notify(this);

    // show a list of available maps
    std::cout << "Available maps:"
        << "\n---------------------------\n"
        << "bigeurope" << endl
        << "bigeurope2 (invalid)" << endl
        << "invalid (lol)" << endl
        << "sw_baltic"
        << "\n---------------------------\n"
        << endl;


    
    
}


void GameEngine::LoadMap() {
 
    // Select a map and load it
    string command;
    string mapName;
    string fileName;

    do {
        cout << "use the \"loadmap <filename>\" command to select a map" << endl << endl;

        string returnedCommand;


        Command* commandEntered{};
        CommandProcessor* processor{};

        processor = new CommandProcessor();

        commandEntered = processor->getCommand();
      //  getline(cin, command);

        // cin >> command;
        cout << "validation result: " << processor->validate(commandEntered)<< endl;
       
        mapName = SelectName(commandEntered->getCommandName());

        

        fileName = "source_maps/" + mapName + ".map";

        map = new Map(fileName);

        if (map->isMapLoaded()) {
            state = State::maploaded;
            cout << endl << "GamePhase: map loaded" << endl << endl;
            Notify(this);
        }

    } while (map == nullptr || !map->isMapLoaded());
}

bool GameEngine::ValidateMap() {
    

    cout << "use the \"validatemap\" command to validate the map" << endl << endl;
 


    bool validMap = false;
    
    validMap = map->validate();
 
      
    if (!validMap)
    {
        cout << "Not a valid map, please try again\n"; 
        return false;
    }
    else
    {
        state = State::mapvalidated;
        cout << "GamePhase: map validated" << endl << endl;
        Notify(this);
        return true;
    }

}

void GameEngine::AddPlayer() {

    string command;
    string playerName;


    cout << "use the \"addplayer <playername>\" command to enter players in the game (2-6 players)" << endl << endl;

    getline(cin, command);

    playerName = SelectName(command);

    Player* player = new Player();
    numberOfPlayers++;
    player->setName(playerName);
    player->setPlayerID(numberOfPlayers);
    player->addToReinforcePool(50);

    players.push_back(player);

    cout << "Player " << numberOfPlayers << " has been created. " << endl << endl;

}

void GameEngine::AddPlayers() {

    AddPlayer();

    state = State::playersadded;
    cout << "GamePhase: players added" << endl << endl; 
    Notify(this);
    
    while (numberOfPlayers < 2) {
        AddPlayer();
    }

}


void GameEngine::GameStart() {

    mapTerritories = map->GetMapTerritories();
    NumberOfTerritories = map->GetMapTerritoriesNumber();
   
    deck->create_deck();


   // cout << *map;
   // cout << players.size();

  

    for (auto player : players)
    {
        cout << *player;
    }

    // Fairly distribute all the territories to the players

    int playerIndex = 0;

    for (int i = 0; i < NumberOfTerritories; i++) {
        Player* tempPlayer = players.at(playerIndex);
        mapTerritories[i]->setOwnerId(tempPlayer->GetPlayerID());
        Territory* tempTerritory = new Territory(*mapTerritories[i]);
        tempPlayer->addTerritory(tempTerritory);

       // tempPlayer->getTerritoryList().push_back(tempTerritory);

        playerIndex++;

        if (playerIndex >= players.size()) {
            playerIndex = 0;
        }
    }

    for (Player* p : players) {

        p->AddCard(deck->draw());

        cout << "Territories owned by " << p->GetPlayerName() << " are:" << endl;
       

    }


    for (Player* p : players) {

        cout << "Territories owned by " << p->GetPlayerName() << " are:" << endl;
        for (Territory* t : p->getTerritoryList()) {
            cout << *t;
        }
        
    }

    for (Territory* t : map->GetMapTerritories()) {
        //adjTerritories.push_back(t); // shallow copy
       // cout << *t;
    }


    // Determine randomly the order of play of the players in the game

   /* int* tempOrder = new int[players.size()];

    for (int j = 0; j < players.size(); j++) {
        tempOrder[j] = rand() % (player_list.size() - j) + j;
    }

    setPlayerOrder(tempOrder);*/

}


// Adds troops to a player's reinforcement pool at the start of the turn.

void GameEngine::ReinforcementPhase() {
    state = State::reinforcementPhase;
    Notify(this);

    cout << "Starting Reinforcement Phase..." << endl;
    for (auto player : players)
    {
       // vector<Territory*> playerTerritories = player->GetTerritoryList();
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
        case State::maploaded:
            log = "Map loaded";
            break;
        case State::mapvalidated:
            log = "Map validated";
            break;
        case State::playersadded:
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


