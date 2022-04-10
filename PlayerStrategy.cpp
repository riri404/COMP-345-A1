#include "PlayerStrategy.h"
#include "Orders.h"
#include "Map.h"
#include "Player.h"
#include <vector>;
#include <set>;
using namespace std;
class Orders;
class Player;
class Territory;

//--------------------------------------------------HUMAN PLAYER STRATEGY--------------------------------------------------
#pragma region Human Player Strategy

HumanPlayerStrategy::HumanPlayerStrategy(Player* p, Player* all, Deck* d) {
	this->player = p;
	this->allPlayers = all;
	this->deck = d;
}

// Why did this method like this? Why an int? why not using string order?
int HumanPlayerStrategy::changeStrategy(string order, int armies)
{
	cout << "HumanPlayerStrategy: Please choose a strategy from the following \n"
		"1 for issueOrder(), 2 for toAttack(), 3 for toDefend(). " << endl;			//Supposed to be strategies (Aggressive, 
	...), not methods?
	int input;
	cin >> input;
	if (input == 1) {
		issueOrder();
		return armies - 1;
	}
	else if (input == 2) {
		toAttack();
		return armies - 2;
	}
	else if (input == 3) {
		toDefend();
		return armies;
	}
	else {
		cout << "Please input an correct integer from 1 to 3...\n" << endl;
	}
}

// The player issues deploy orders on its own territories that are in the list returned by toDefend(). As long as the player has armies still to deploy (see startup phase and reinforcement phase), 
// it will issue a deploy order and no other order. Once it has deployed all its available armies, it can proceed with other kinds of orders.
void HumanPlayerStrategy::issueOrder()
{
	// If reinforcement pool > 0, then do deploy orders
	if (player->getReinforcementPool() > 0)
	{
		cout << "Player " << player->GetPlayerName() << "'s reinforcement pool contains " << player->getReinforcementPool() << " armie units." << endl;
	}
	//const int EXITNUMBER = 7;
	//int input = 0;

	//while (input != EXITNUMBER) {
	//	cout << "Which order are you issuing?" << endl;
	//	cout << "1. Deploy" << endl;
	//	cout << "2. Advance" << endl;
	//	cout << "3. Airlift" << endl;
	//	cout << "4. Bomb" << endl;
	//	cout << "5. Blockade" << endl;
	//	cout << "6. Negotiate" << endl;
	//	cout << EXITNUMBER << ". Exit" << endl;

	//	//fix problem with orders
	//	cin >> input;
	//	switch (input) {
	//	case (1):
	//		DeployOrder();
	//		break;
	//	case (2):
	//		AdvanceOrder();
	//		break;
	//	case (3):
	//		AirliftOrder();
	//		break;
	//	case (4):
	//		BombOrder();
	//		break;
	//	case (5):
	//		BlockadeOrder();
	//		break;
	//	case (6):
	//		NegotiateOrder();
	//		break;
	//	case (EXITNUMBER):
	//		cout << "Exiting" << endl;
	//		break;
	//	default:
	//		cout << "Please Enter a valid order number!" << endl;
	//		break;
	//	}
	//}
}

// From Assignment 2 (Orders Issuing phase): 
// The player decides which neighboring territories are to be attacked in priority (as a list return by the toAttack() method), and which of their own territories are to be defended 
// in priority (as a list returned by the toDefend() method).
vector<Territory*> HumanPlayerStrategy::toAttack()
{
	cout << "HumanPlayerStrategy: toAttack() " << endl;
	//vector<Territory*> attackList;

	string toAttack;
	string input;

	for (int i = 0; i < player->getTerritoryList().size(); i++)
	{
		for (int j = 0; j > player->getTerritoryList().at(i)->getAdjTerritories().size(); j++) {
			// Make sure territory does not belong to player
			if (player->getTerritoryList().at(i)->getAdjTerritories().at(j)->getPlayerOwner() != player) {
				cout << "Adjacent territories of territory " << player->getTerritoryList().at(i)->getName() << " are: " << endl;
				cout << "\t" << player->getTerritoryList().at(i)->getAdjTerritories().at(j)->getName() << " belonging to player " << player->getTerritoryList().at(i)->getAdjTerritories().at(j)->getPlayerOwner()->GetPlayerName()
					<< " and has " << player->getTerritoryList().at(i)->getAdjTerritories().at(j)->getArmies() << " armie units." << endl;
			}
		}
	}

	/// Do while loop so the player can add the territories they wish to attack to the attackList
	while (true)
	{
		cout << "Which territory do you wish to attack? (Enter territory name)" << endl;
		cin >> toAttack;

		for (int i = 0; i < player->getTerritoryList().size(); i++)
		{
			for (int j = 0; j > player->getTerritoryList().at(i)->getAdjTerritories().size(); j++) {
				// If territory does not belong to the player, then it's a valid input.
				if (player->getTerritoryList().at(i)->getAdjTerritories().at(j)->getName() == toAttack && player->getTerritoryList().at(i)->getAdjTerritories().at(j)->getPlayerOwner() != player) {
					cout << "Territory " << player->getTerritoryList().at(i)->getAdjTerritories().at(j)->getName() << " is being added to attackList." << endl;
					/*attackList.push_back(player->getTerritoryList().at(i)->getAdjTerritories().at(j));*/
					player->addTerritoryToAttack(player->getTerritoryList().at(i)->getAdjTerritories().at(j));
					continue;
				}
				// If territory belongs to the player, it's not a valid input
				else if (player->getTerritoryList().at(i)->getAdjTerritories().at(j)->getName() == toAttack && player->getTerritoryList().at(i)->getAdjTerritories().at(j)->getPlayerOwner() == player) {
					cout << "The territory " << player->getTerritoryList().at(i)->getAdjTerritories().at(j)->getName() << " belongs to you, you can't attack your own territory, please try again." << endl;
					continue;
				}
			}
		}

		cout << "Do you wish to add another territory to your attackList? (yes or no)" << endl;
		cin >> input;

		if (input == "yes") {
			continue;
		}
		else {
			break;
		}
	}

	return player->getListToAttack();
}

// From Assignment 2 (Orders Issuing phase): 
// The player decides which neighboring territories are to be attacked in priority (as a list return by the toAttack() method), and which of their own territories are to be defended 
// in priority (as a list returned by the toDefend() method).
vector<Territory*> HumanPlayerStrategy::toDefend()
{
	cout << "HumanPlayerStrategy: toDefend() " << endl;

	//vector<Territory*> defendList;

	string toDefend;
	string input;

	for (int i = 0; i < player->getTerritoryList().size(); i++) {
		cout << "Territories to defend are: " << endl;
		cout << "\t" << player->getTerritoryList().at(i)->getName() << " with armies: " << player->getTerritoryList().at(i)->getArmies() << endl;
	}

	// Do while loop so the player can add the territories they wish to defend to the defendList
	while (true)
	{
		cout << "Which territory do you wish to defend? (Enter territory name)" << endl;
		cin >> toDefend;

		for (int i = 0; i < player->getTerritoryList().size(); i++)
		{
			// If territory is in list of territories of player, then it's valid
			if (player->getTerritoryList().at(i)->getName() == toDefend) {
				cout << "Territory " << player->getTerritoryList().at(i)->getName() << " is being added to your defendList." << endl;
				//defendList.push_back(player->getTerritoryList().at(i));
				player->addTerritoryToDefend(player->getTerritoryList().at(i));
				continue;
			}
			else {
				cout << "Territory " << toDefend << " is not a valid input, please try again." << endl;
			}
		}

		cout << "Do you wish to add another territory to your defendList? (yes or no)" << endl;
		cin >> input;

		if (input == "yes") {
			continue;
		}
		else {
			break;
		}
	}

	return player->getListToDefend();
}

void HumanPlayerStrategy::PrintStrategy()
{
	std::cout << "Human Player Strategy\n";
}

#pragma region Helper Functions

void HumanPlayerStrategy::DeployOrder()
{

	//show necessary information
	ShowTerritory();
	cout << "Available Reinforcement: " << player->getReinforcementPool() << endl;

	//get region and reinforcement
	int region = ChooseValidOption(player->getTerritoryList().size());
	int rein = GetArmyNumber(player->getReinforcementPool());
	player->setReinforcementPool(player->getReinforcementPool() - rein);

	//make order
	//Deploy* deployOrder = new Deploy();
	// WHY? Should be using constructor
	Deploy* deployOrder = new Deploy(player, rein, player->getTerritoryList().at(region));
	/*deployOrder->setSelfPlayers(player);
	deployOrder->setTargetTerritory(player->getTerritoryList().at(region));
	deployOrder->setNumArmy(rein);*/

	player->setOrder(deployOrder);
}

void HumanPlayerStrategy::AdvanceOrder()
{
	//get source territory
	ShowTerritory();
	int source = ChooseValidOption(player->getTerritoryList().size());

	//get target territory
	cout << "These are the target Territories" << endl;
	/*for (int i = 0; i < player->getTerritoryList().at(source)->edges.size(); i++)
	{
		cout << i << ". " << player->getTerritoryList().at(source)->edges.at(i)->getTname() << " (" << player->getTerritoryList().at(source)->edges.at(i)->getArmyAmount() << ")";
		if (player->getTerritoryList().at(source)->edges.at(i)->getTerritoryOwner() != player)
		{
			cout << " (enemy)";
		}
		cout << endl;
	}*/
	// Changed by Justine & Jennifer, instead of using edges, used method getAdjTerritories() in Map to get the adjacent territories from the source
	for (int i = 0; i < player->getTerritoryList().at(source)->getAdjTerritories().size(); i++)
	{
		cout << i << ". " << player->getTerritoryList().at(source)->getAdjTerritories().at(i)->getName() << " (" << player->getTerritoryList().at(source)->getAdjTerritories().at(i)->getArmies() << ")";
		if (player->getTerritoryList().at(source)->getAdjTerritories().at(i)->getPlayerOwner() != player)
		{
			cout << " (enemy)";
		}
		cout << endl;
	}
	int target = ChooseValidOption(player->getTerritoryList().size());

	//get army amount
	cout << "Source armount is " << player->getTerritoryList().at(source)->getArmies() << endl;
	int army = GetArmyNumber(player->getTerritoryList().at(source)->getArmies());

	//make advance orders
	/*Advance* advanceOrder = new Advance();
	advanceOrder->setSelfPlayers(player);
	advanceOrder->setSourceTerritory(player->getTerritoryList().at(source));
	advanceOrder->setTargetTerritory(player->getTerritoryList().at(source)->edges.at(target));
	advanceOrder->setArmyUnits(army);*/
	// WHY? Should be using constructor
	Advance* advanceOrder = new Advance(player, army, player->getTerritoryList().at(source), player->getTerritoryList().at(source)->getAdjTerritories().at(target), player->getPlayerHand(), deck);

	player->setOrder(advanceOrder);
}

void HumanPlayerStrategy::AirliftOrder()
{
	ShowTerritory();

	int source = ChooseValidOption(player->getTerritoryList().size());

	cout << "Choose another region to Airlift towards" << endl;
	int target = ChooseValidOption(player->getTerritoryList().size());

	cout << "Choose army amount to source" << endl;
	cout << "Available army: " << player->getTerritoryList().at(source)->getArmies() << endl;
	int army = GetArmyNumber(player->getTerritoryList().at(source)->getArmies());

	/*Airlift* airliftOrder = new Airlift();
	airliftOrder->setSelfPlayers(player);
	airliftOrder->setSourceTerritory(player->getTerritoryList().at(source));
	airliftOrder->setTargetTerritory(player->getTerritoryList().at(target));
	airliftOrder->setNumArmy(army);*/
	// WHY? Should be using constructor
	Airlift* airliftOrder = new Airlift(player, army, player->getTerritoryList().at(source), player->getTerritoryList().at(target));

	player->setOrder(airliftOrder);
}

void HumanPlayerStrategy::BombOrder()
{
	//get enemy territory
	vector<Territory*> enemyTerritory = GetEnemyTerritory();

	//choose enemy territory
	cout << "These are enemy Territory Territories" << endl;
	for (int i = 0; i < enemyTerritory.size(); i++)
	{
		cout << i << ". " << enemyTerritory.at(i)->getName() << " (" << enemyTerritory.at(i)->getArmies() << ")";
		cout << endl;
	}
	int territory = ChooseValidOption(enemyTerritory.size());

	//make bomb orders
	/*Bomb* bombOrders = new Bomb();
	bombOrders->setSelfPlayers(player);
	bombOrders->setTargetTerritory(enemyTerritory.at(territory));*/
	// WHY? Should be using constructor
	Bomb* bombOrders = new Bomb(player, enemyTerritory.at(territory), player->getTerritoryList());

	player->setOrder(bombOrders);
}

void HumanPlayerStrategy::BlockadeOrder()
{
	ShowTerritory();
	int region = ChooseValidOption(player->getTerritoryList().size());

	//Blockade* blockadeOrders = new Blockade();
	//blockadeOrders->setSelfPlayers(player);
	////blockadeOrders->setNeutralPlayer(player->getNeutralPlayer()); 
	//// WHY? the neutral player is created when the order is executed
	//blockadeOrders->setTargetTerritory(player->getTerritoryList().at(region));
	// WHY not use constructor?
	//Blockade* blockadeOrders = new Blockade(player, allPlayers, player->getTerritoryList().at(region));

	//player->setOrder(blockadeOrders);
}

void HumanPlayerStrategy::NegotiateOrder()
{
	set<Player*> playersTemp = GetPlayers();
	vector<Player*> players = vector<Player*>(playersTemp.begin(), playersTemp.end());

	cout << "These are the valid player options" << endl;
	for (int i = 0; i < players.size(); i++)
	{
		next(players.begin(), i);
		cout << i << ". " << players.at(i)->GetPlayerName() << endl;
	}

	int chosenPlayer = ChooseValidOption(players.size());

	/*Negotiate* negotiateOrders = new Negotiate();
	negotiateOrders->setSelfPlayers(player);
	negotiateOrders->setPeacePlayer(players.at(chosenPlayer));*/
	// WHY? Should be: 
	Negotiate* negotiateOrders = new Negotiate(player, players.at(chosenPlayer));
	// Reason: setPeacePlayer is technically the player chosen to negociate with, but should use constructor

	player->setOrder(negotiateOrders);
}

int HumanPlayerStrategy::ChooseValidOption(int max)
{
	int region = -1;
	while (region >= max || region < 0) {
		cout << "choose a valid option: ";
		cin >> region;
	}

	return region;
}

int HumanPlayerStrategy::GetArmyNumber(int army)
{
	int rein = -1;
	while (rein > army || rein < 0) {
		cout << "choose a valid amount: ";
		cin >> rein;
		cout << endl;
	}

	return rein;
}

void HumanPlayerStrategy::ShowTerritory()
{
	cout << "These are the available to Choose from" << endl;
	for (int i = 0; i < player->getTerritoryList().size(); i++)
	{
		cout << i << ". " << player->getTerritoryList().at(i)->getName() << " (" << player->getTerritoryList().at(i)->getArmies() << ")" << endl;
	}
}

vector<Territory*> HumanPlayerStrategy::GetEnemyTerritory()
{
	vector<Territory*> nonPlayerTerritory;

	// Modified by Jennifer, changed from for each(Territory* territory in player->getMap()) to this bc the other one gave errors
	//for (Territory * territory : player->getMap()) {
	//	if (territory->getPlayerOwner() != player) {
	//		nonPlayerTerritory.push_back(territory);
	//	}
	//}
	for (Territory* territory : allPlayers->getTerritoryList()) {
		if (territory->getPlayerOwner() != player) {
			nonPlayerTerritory.push_back(territory);
		}
	}

	return nonPlayerTerritory;
}

set<Player*> HumanPlayerStrategy::GetPlayers()
{
	set<Player*> players;

	// Changed by Jennifer
	//for each (Territory * terr in player->getMap())
	//{
	//	if (terr->getTerritoryOwner() != player) {
	//		players.insert(terr->getTerritoryOwner());
	//	}
	//}
	/*for (Territory* terr : player->getMap())
	{
		if (terr->getPlayerOwner() != player) {
			players.insert(terr->getPlayerOwner());
		}
	}*/
	for (Player* p : allPlayers->getListOfPlayers()) {
		if (p != player) {
			players.insert(p);
		}
	}
	return players;
}

#pragma endregion

#pragma endregion

//--------------------------------------------------AGGRESSIVE PLAYER STRATEGY--------------------------------------------------

#pragma region Aggressive Player Strategy

AggressivePlayerStrategy::AggressivePlayerStrategy(Player* p, Player* all, Deck* d) {
	this->player = p;
	this->allPlayers = all;
	this->deck = d;
}

int AggressivePlayerStrategy::changeStrategy(string order, int armies)
{
	cout << "AggressivePlayerStrategy: changeStrategy() " << endl;
	return 0;
}

//computer player that focuses on attack (deploys or advances armies on its strongest country)
//Then always advances to enemy territories until it cannot do so anymore). 
void AggressivePlayerStrategy::issueOrder()
{
	Territory* source;
	Territory* target;
	//Deploys or advances armies on its strongest territories
	//Find the strongest territory
	//for all territories in its list of territories, if territory at i has more armies, then strongest territory = territory at i
	//Create a Deploy or Advance (on its own territory) order, move all armies on the strongest country
	if (player->getReinforcementPool() > 0)
	{
		// If player has reinforcement units, then deploy
		target = player->getTerritoryList().at(0);
		// Find territory with largest number of units
		for (int i = 0; i < player->getTerritoryList().size(); i++) {
			if (target->getArmies() < player->getTerritoryList().at(i)->getArmies()) {
				target = player->getTerritoryList().at(i);
			}
		}
		Deploy* deployOrder = new Deploy(player, player->getReinforcementPool(), target);

		player->setOrder(deployOrder);
	}
	// Else, advance
	else
	{
		//Always advances to enemy territories until it cannot do so anymore
		//Create Advance order on enemy territory
		source = player->getTerritoryList().at(0);
		// While the player still has armie units, do advance
		while (source->getArmies() > 0)
		{
			// Find territory with largest number of units; Going to be the source territory
			for (int i = 0; i < player->getTerritoryList().size(); i++) {
				if (source->getArmies() < player->getTerritoryList().at(i)->getArmies()) {
					source = player->getTerritoryList().at(i);
				}
			}

			target = allPlayers->getTerritoryList().at(0);
			// Go through all the territories
			for (int i = 0; allPlayers->getTerritoryList().size(); i++) {
				// If territory does not belong to the player, then it belongs to an enemy player
				if (allPlayers->getTerritoryList().at(i)->getPlayerOwner() != player) {
					// If the enemie territory has lowest amount of armie units and is adjacent to the source territory, then it's going to be the target
					if (target->getArmies() > allPlayers->getTerritoryList().at(i)->getArmies() && source->isAdjacentTo(allPlayers->getTerritoryList().at(i)->getId()))
						target = allPlayers->getTerritoryList().at(i);
				}
			}

			Advance* advanceOrder = new Advance(player, source->getArmies(), source, target, player->getPlayerHand(), deck);

			player->setOrder(advanceOrder);
		}
	}

	//cout << "\nAggressive player deployed/Advanced all its armies and reinforcements until it no longer can." << endl;
}

vector<Territory*> AggressivePlayerStrategy::toAttack()
{
	vector<Territory*> attackList;

	return attackList;
}

vector<Territory*> AggressivePlayerStrategy::toDefend()
{
	vector<Territory*> DefendList;
	return DefendList;
	//cout << "AggressivePlayerStrategy: toDefend() " << endl;
	//cout << "Aggressive Player can not defend!" << endl;
}

void AggressivePlayerStrategy::PrintStrategy()
{
	std::cout << "Aggressive Player Strategy\n";
}

#pragma endregion

//--------------------------------------------------BEENEVOLENT PLAYER STRATEGY--------------------------------------------------

#pragma region Benevolent Player Strategy

BenevolentPlayerStrategy::BenevolentPlayerStrategy(Player* p, Player* all, Deck* d) {
	this->player = p;
	this->allPlayers = all;
	this->deck = d;
}

int BenevolentPlayerStrategy::changeStrategy(string order, int numArmy)
{
	cout << "BenevolentPlayerStrategy: changeStrategy() " << endl;

	return 0;

}

//computer player that focuses on protecting its weak countries (deploys or advances armies on its weakest countries, 
//never advances to enemy territories).
void BenevolentPlayerStrategy::issueOrder()
{
	//Deploys its weakest territories
	//Find the weakest territory
	//set weakest territory to index 0
	//for all territories in its list of territories, if territory at i has less armies, then weakest territory = territory at i
	//Create a Deploy on the weakest country
	Territory* source;
	Territory* target;
	if (player->getReinforcementPool() > 0)
	{
		// If player has reinforcement units, then deploy
		source = player->getTerritoryList().at(0);
		// Find territory with largest number of units
		for (int i = 0; i < player->getTerritoryList().size(); i++) {
			if (source->getArmies() > player->getTerritoryList().at(i)->getArmies()) {
				source = player->getTerritoryList().at(i);
			}
		}
		Deploy* deployOrder = new Deploy(player, player->getReinforcementPool(), source);

		player->setOrder(deployOrder);
	}
	//Check adjacent countries that has less armies then the others and move armies to the weaker countries (Advance)
	else
	{
		source = player->getTerritoryList().at(0);
		while (source->getArmies() > 0)
		{
			// Find territory with largest number of units; Going to be the source territory
			for (int i = 0; i < player->getTerritoryList().size(); i++) {
				if (source->getArmies() < player->getTerritoryList().at(i)->getArmies()) {
					source = player->getTerritoryList().at(i);
				}
			}

			target = player->getTerritoryList().at(0);
			for (int i = 0; i < player->getTerritoryList().size(); i++) {
				if (source->isAdjacentTo(player->getTerritoryList().at(i)->getId()) && target->getArmies() > player->getTerritoryList().at(i)->getArmies()) {
					target = player->getTerritoryList().at(i);
				}
			}
			Advance* advanceOrder = new Advance(player, source->getArmies(), source, target, player->getPlayerHand(), deck);
		}
	}

	//Cannot advance on enemy territories
}

vector<Territory*> BenevolentPlayerStrategy::toAttack()
{
	vector<Territory*> AttackList;
	return AttackList;
}

vector<Territory*> BenevolentPlayerStrategy::toDefend()
{
	vector<Territory*> defendList;

	return defendList;
}

void BenevolentPlayerStrategy::PrintStrategy()
{
	std::cout << "Benevolent Player Strategy\n";
}

#pragma endregion

//--------------------------------------------------NEUTRAL PLAYER STRATEGY--------------------------------------------------

#pragma region Neutral Player Strategy

//sets player
NeutralPlayerStrategy::NeutralPlayerStrategy(Player* player, Player* all, Deck* d) {
	this->player = player;
	this->allPlayers = all;
	this->deck = d;

}

int NeutralPlayerStrategy::changeStrategy(string, int)
{
	return 0;
}

//computer player that never issues any order. If a Neutral player is attacked, it becomes an Aggressive player.
void NeutralPlayerStrategy::issueOrder()
{
	//Cannot issue order unless attcacked

	int territoryAmount = 0;
	int armyAmount = 0;

	//if army is attacked
	if (territoryAmount < territoryCount || armyAmount < armyCount) {
		
		cout << "Neutral player is attacked, now it is aggressive" << endl;
		
		//change player strategy
		//player->setPlayerStrategy(Aggressive); // have tocreate setPlayerStrategy
		//player->issueOrder();

		//not sure if this is allowed, remove if necessary
		this->~NeutralPlayerStrategy();
	}
	else {
		territoryCount = territoryAmount;
		armyCount = armyAmount;
	}
}

//never needs to attack
vector<Territory*> NeutralPlayerStrategy::toAttack()
{
	vector<Territory*> DefendList;
	cout << "Neutral does not attack" << endl;
	return DefendList;
}

//never needs to defend
vector<Territory*> NeutralPlayerStrategy::toDefend()
{
	vector<Territory*> DefendList;
	cout << "Neutral does not defend" << endl;
	return DefendList;
}

void NeutralPlayerStrategy::PrintStrategy()
{
	std::cout << "Neutral Player Strategy\n";
}

NeutralPlayerStrategy::~NeutralPlayerStrategy()
{

}

#pragma endregion


//--------------------------------------------------CHEATER PLAYER STRATEGY--------------------------------------------------

#pragma region Cheater Player Strategy

CheaterPlayerStrategy::CheaterPlayerStrategy(Player* player, Player* all, Deck* d)
{
	this->player = player;
	this->allPlayers = all;
	this->deck = d;
}

int CheaterPlayerStrategy::changeStrategy(string, int)
{
	return 0;
}

//computer player that automatically conquers all territories that are adjacent to its own territories(only once per turn)
void CheaterPlayerStrategy::issueOrder()
{
	Territory* source;
	Territory* target;


	for (int i = 0; i < player->getTerritoryList().size(); i++)
	{
		source = player->getTerritoryList().at(i);
		for (int j = 0; j < allPlayers->getTerritoryList().size(); j++) {
			target = allPlayers->getTerritoryList().at(i);
			if (target->getPlayerOwner() != player && target->isAdjacentTo(source->getId())) {
				target->setPlayerOwner(player);
			}
		}
	}
}

vector<Territory*> CheaterPlayerStrategy::toAttack()
{
	vector<Territory*> AttackList;

	return AttackList;
}

//cheater never needs to defend
vector<Territory*> CheaterPlayerStrategy::toDefend()
{
	vector<Territory*> DefendList;
	return DefendList;
}

void CheaterPlayerStrategy::PrintStrategy()
{
	std::cout << "Cheater Player Strategy\n";
}

#pragma endregion

void PlayerStrategy::setDeck(Deck* d)
{
	this->deck = d;
}
