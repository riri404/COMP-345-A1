#include "PlayerStrategy.h" 
#include "Player.h" 
#include "Map.h"
#include "Orders.h"
#include <vector>

class Territory;
class OrderList;

void StrategiesDriver(){

    Territory *t1=new Territory(4011 ,"mark", "Europe");
    Territory *t2=new Territory(4129, "joe", "Asia");
    Territory *t3=new Territory(4001 ,"leo", "Africa");
    Territory *t4=new Territory(4109, "cleo", "Asia");
    vector<Territory *> territoriesList={t1, t2,t3,t4};

    //creating arbitary list of orders
    OrderList* orderList;

    bool a = true;
    bool b = true;

    int a1 = 1;
    int a2 = 2;

    vector<string> list1 = {"a"};
    vector<string> list2 = {"b"};


cout << "Human Player testing\n\n";
	Player* humanPlayer = new Player();
	humanPlayer->setName("Human Player");
	//humanPlayer->setPlayerStrategy(Human); 

	Player* neutralPlayer2 = new Player();
	neutralPlayer2->setName("Neutral Player");
	//neutralPlayer2->setPlayerStrategy(Neutral);

	humanPlayer->setTerritory(t1);
	humanPlayer->setTerritory(t2);
	neutralPlayer2->setTerritory(t3);
	neutralPlayer2->setTerritory(t4);




	humanPlayer->setReinforcementPool(10);
	humanPlayer->issueOrder();

}