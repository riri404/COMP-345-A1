#include "Player.h"
//#include "MapLoader.h"
#include "Cards.h"
#include "Orders.h"
#include "Map.h"
#include <vector>
#include "Deck.h"

class GameEngine {
private:
	Map* map;
	std::vector<Player*> players;  // Keep these in order of play.
	Deck* deck;
	static Player* neutralPlayer; // Used by blockade order
	
	

public:
	GameEngine();
	~GameEngine();
	void Init();
	void StartupPhase();
	void MainGameLoop();
	void ReinforcementPhase();
	void IssueOrdersPhase();
	void ExecuteOrdersPhase();

	std::vector<Player*> getPlayers();
	std::vector<Player*>* getPlayersAdress();

	Map* GetMap();
	void PlayerDrawCard(Player* player);
};
