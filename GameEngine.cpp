#include "GameEngine.h"
#include <sstream>

using namespace std;

GameEngine::GameEngine()
{
    state = State::null;
    this->map = nullptr;
    vector<Player*> players;
    this->deck = new Deck();
    this->numberOfPlayers = 0;
    this->NumberOfTerritories = 0;

    CommandProcessor* commandProcessor = new CommandProcessor();
    processor = new CommandProcessor();
    processor->gameEnginePtr = this;
}

// Creates a deep copy of this GameEngine, and all of its components.
GameEngine::GameEngine(GameEngine& engine)
{
    state = State::null;
    this->map = new Map(*engine.map);
    // this->players;
    for (int i = 0; i < engine.players.size(); i++)
    {
        this->players.push_back(new Player(*engine.players.at(i)));
    }

    this->deck = new Deck(*engine.deck);
    this->numberOfPlayers = engine.numberOfPlayers;
    this->NumberOfTerritories = engine.NumberOfTerritories;
    this->state = engine.state;
    this->processor = engine.processor;
    processor->gameEnginePtr = this;
}

GameEngine::~GameEngine()
{

    delete this->map;
    map = NULL;
    delete this->deck;
    deck = NULL;

    delete this->processor->gameEnginePtr;
    processor->gameEnginePtr = NULL;

    delete this->processor;
    processor = NULL;

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
    istringstream iss(command);
    string garbage = "";
    string name = "";
    iss >> garbage >> name;
    return name;
}


void GameEngine::StartupPhase() {
    cout << "Welcome to Warzone" << endl << endl;

    Start();
    LoadMap();
    ValidateMap();
    AddPlayers();
    GameStart();
}

void GameEngine::TakeInput() {

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
 
    string mapName;
    string fileName;

    do {
        cout << "::Use the \"loadmap <filename>\" command to select a map" << endl << endl;

        commandEntered = processor->getCommand();
            
        if (processor->validate(commandEntered)) {

            mapName = SelectName(commandEntered->GetCommandName());

            fileName = "source_maps/" + mapName + ".map";

            map = new Map(fileName);

            if (map->isMapLoaded()) {
                state = State::maploaded;
                cout << endl << "GamePhase: map loaded" << endl << endl;
                Notify(this);
            }
        }
    } while (map == nullptr || !map->isMapLoaded());
}


bool GameEngine::ValidateMap() {
    
    bool validMap = false;

    do {
        cout << "::Use the \"validatemap\" command to validate the map" << endl << endl;

        commandEntered = processor->getCommand();

        if (processor->validate(commandEntered)) {

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
    } while (!validMap);
    return false;
}

void GameEngine::AddPlayers() {

    bool startGame = false;

    while (!startGame) {

        cout << "::Use the \"addplayer <playername>\" command to enter players in the game (2-6 players)" << endl;

        if (numberOfPlayers > 1 && numberOfPlayers < 7) {

            cout << "OR" << endl;
            cout << "::Use the \"gamestart\" to start the game play phase" << endl << endl;
        }

        commandEntered = processor->getCommand();

        if (processor->validate(commandEntered)) {

            if (commandEntered->type == Command::CommandType::addplayer) {

                if (numberOfPlayers < 6) {

                    AddPlayer();

                }

                else {

                    cout << endl << "-< Maximum number of players is 6 >- " << endl;

                    cout << endl << "::Use the \"gamestart\" command to start the game play phase" << endl;
                }
            }

            if (commandEntered->type == Command::CommandType::gamestart) {

                startGame = true;
            }
        }
    }

}

void GameEngine::AddPlayer() {

    string playerName;

    playerName = SelectName(commandEntered->GetCommandName());

    Player* player = new Player();

    player->setName(playerName);
    player->setPlayerID(numberOfPlayers);
    

    players.push_back(player);
    numberOfPlayers++;

    cout << "Player " << numberOfPlayers << ". " << playerName << " -> has been created. " << endl << endl;
    state = State::playersadded;
    cout << "GamePhase: players added" << endl << endl;
    Notify(this);    
}

void GameEngine::DistributeTerritories() {

    mapTerritories = map->GetMapTerritories();
    NumberOfTerritories = map->GetMapTerritoriesNumber();

    int playerIndex = 0;

    for (int i = 0; i < NumberOfTerritories; i++) {

        Player* tempPlayer = players.at(playerIndex);

        mapTerritories[i]->setOwnerId(tempPlayer->GetPlayerID());

        // Territory* tempTerritory = new Territory(*mapTerritories[i]);
        // just add the territory no need to copy

        tempPlayer->addTerritory(mapTerritories[i]);

        playerIndex++;

        if (playerIndex >= players.size()) {
            playerIndex = 0;
        }
    }
}

void GameEngine::ShufflePlayers(vector<Player*> playersToShuffle) {

    // obtain a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);

    shuffle(begin(playersToShuffle), end(playersToShuffle), e);
}

void GameEngine::GameStart() {

    DistributeTerritories();

    ShufflePlayers(players);

    deck->create_deck();

    for (Player* player : players) {

        for (int i = 0; i < 2; i++) {

            player->AddCard(deck->draw());
        }

        player->addToReinforcePool(50);
    }

  
    // cout << endl << "Map info ->" << endl << endl <<*map;

    cout << endl << "Players of this game ->" << endl;

    for (auto player : players)
    {
        
        cout << endl << *player << endl;
    }


 /*   for (Player* player : players) {

        cout << endl <<"Territories owned by " << player->GetPlayerName() << " -> " << endl << endl;
        for (Territory* territory : player->getTerritoryList()) {
          cout << *territory;
        }
        
    }*/
}


// Adds troops to a player's reinforcement pool at the start of the turn.

void GameEngine::ReinforcementPhase() {
    state = State::reinforcementPhase;
    Notify(this);

    bool check = false;
    int temp = 0;
    double count = 0;

    cout << "Starting Reinforcement Phase..." << endl;
    for (int i = 0; i < players.size(); i++)
    {   //check if the player's terriotries
        temp = players[i]->getReinforcementPool();

        for (int j = 0; j < players[i]->getTerritoryList().size(); i++)
        {
            cout << "inside nested loop..." << endl;
            //count the terriorties number
            count++;
        }
        //calcuate the contient bouns
        check = (*players[i]).playerContinentBouns();


        if (check == true)
        {
            temp += 2 * (int)round(count / 3);
        }
        else
        {
            temp += (int)round(count / 3);
        }

        temp += 3;

        players[i]->setReinforcementPool(temp);
        check = false;
        temp = 0;
        count = 0;

    }

    cout << endl << "end of Reinforcement phase" << endl << endl;
    // IssueOrdersPhase(); //why????????????????????????????
}



// Calls IssueOrder until all players have commited that they are done issuing orders.

void GameEngine::IssueOrdersPhase() {
    state = State::issueOrderPhase;
    Notify(this);

    cout << "Starting Issue Orders Phase..." << endl;


    auto m = map->GetMapTerritories();
    
    for (auto player : players)
    {
        player->issueOrder(m);
    }
    cout << "end of issue orders phase" << endl << endl;

    // ExecuteOrdersPhase(); // why????
}


// Calls ExecuteOrder() until all players have no more orders in their orders list.

void GameEngine::ExecuteOrdersPhase() {
    state = State::executeOrderPhase;
    Notify(this);


    cout << "Starting Execute Orders Phase..." << endl;

    for (Player* player : players)
    {
        auto orderList = player->getOrdersList()->listOfOrders;
        for (int i = 0; i < orderList.size(); i++)
        {
            //execute and remove if its a deploy order
            if (orderList.at(i)->getName() == "Deploy Orders")
            {
                //validate, excute and delete order
                orderList.at(i)->validate();
                orderList.at(i)->execute();
                orderList.erase(orderList.begin() + i);
                i--;
            }
        }
    }

    //there should be no more deploy orders

    for (Player* player : players)
    {
        auto orderList = player->getOrdersList()->listOfOrders;
        while (!orderList.empty())
        {
            //validate, excute and delete order
            orderList.at(0)->validate();
            orderList.at(0)->execute();
            orderList.erase(orderList.begin());
        }
    } //order list should be empty


    cout << "end of execute orders phase" << endl;
}

void GameEngine::ExecuteOrders() {


    cout << "Enter \"win\" to win,  Enter \"executeOrder\" to repeat executeOrder Enter \"new\"to go back to issue new order" << endl;
    string a;
    cin >> a;
    if (a == "win") {
        state = State::win;
        Notify(this);
    }
    else if (a == "executeOrder") {
        ExecuteOrdersPhase();
        state = State::executeOrderPhase;
        Notify(this);

    }
    else if (a == "new") {
        state = State::issueOrderPhase;
        Notify(this);
        IssueOrdersPhase();
    }
}


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
            log = "State: Starting game";
            break;
        case State::maploaded:
            log = "Phase: Map loaded";
            break;
        case State::mapvalidated:
            log = "Phase: Map validated";
            break;
        case State::playersadded:
            log = "Phase: Players added";
            break;
        case State::reinforcementPhase:
            log = "Phase: Reinforcement";
            break;
        case State::issueOrderPhase:
            log = "Phase: Issue order";
            break;
        case State::executeOrderPhase:
            log = "Phase: Execute order";
            break;
        case State::tournamentStart:
            log = "Phase: Starting tournament";
        case State::tournamentEnd:
            log = tournamentLog();
        default:
            log = "Unknown phase";
            break;
        
    }
    return log;
}

void GameEngine::AttachToOrdersList(LogObserver* observer) {
    for (Player* p : players) {
        p->Attach(observer);
    }
}

void GameEngine::AttachToProcessor(LogObserver* observer) {
    processor->Attach(observer);
    for (auto i : processor->commandObjects) {
        i->Attach(observer);
    }
}


string GameEngine::tournamentLog() {
    ostringstream oss;
    // logging tournament parameters
    oss << "Tournament mode:" << endl;
    oss << "M: ";
    for (auto map : tournamentMaps) oss << map << " ";
    oss << endl;
    oss << "P: ";
    // TODO: replace player->GetPlayerName() by getter for strategy name
    for (auto player : players) oss << player->GetPlayerName() << " ";
    oss << endl;
    oss << "G: " << tournamentNumOfGames << endl;
    oss << "D: " << tournamentMaxturns << endl << endl;
    // logging results
    oss << "Results: " << endl;
    for (int i = 0; i < tournamentNumOfGames; ++i) {
        oss << "Game " << i + 1 << endl;
        for (int j = 0; j < tournamentMaps.size(); ++ j) {
            auto player = tournamentPlayersWon.at(i * tournamentMaps.size() + j);
            oss << "\t" << "Map: " << tournamentMaps.at(j) << ", Won by " << player->GetPlayerName() << endl;
        }
    }
    return oss.str();
}
// returns true if the load was successfull, otherwise false
bool GameEngine::loadAnotherMap(string file) {
    map->load(file);
    return map->validate();
}

void GameEngine::reset() {
    // NOTE: All of these should be reloaded on each game in the tournament
    tournamentPlayersWon.clear();
    for (auto p : players) delete p;
    players.clear();
    map->clear();
    mapTerritories.clear();
    state = State::null;
    delete deck;
    deck = new Deck();
    NumberOfTerritories = 0;
    numberOfPlayers = 0;
}

void GameEngine::playTournament() {
    state = State::tournamentStart;
    Notify(this);
    for (int i = 0; i < tournamentNumOfGames; ++i) {
        for (int j = 0; j < tournamentMaps.size(); ++i) {
            reset();
            // initialize(); feature6 to add
            map->load("source_maps/" + tournamentMaps[i] + ".map");
            // play game
            // GameStart(); is this the correct function?
            Player* playerWon = new Player(); // get player who won
            tournamentPlayersWon.push_back(playerWon);
        }
    }
    state = State::tournamentEnd;
    Notify(this);
}