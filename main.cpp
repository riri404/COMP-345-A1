#include "Cards.h"
#include "Map.h"
#include "Orders.h"
#include "Player.h"
#include "GameEngine.h"




int main() {

    GameEngine* engine;
    engine = new GameEngine;

   // engine->AddPlayer();

    engine->StartupPhase();

 //  cout<< engine->SelectName("loadmap <mapfile>");
    

    system("pause");


 //   cin.get();
    return 0;
    
      /*  string str = "STARTDELIMITER_0_192.168.1.18_STOPDELIMITER";
        unsigned first = str.find(<);
        unsigned last = str.find_last_of(">");
        string strNew = str.substr(first, last - first);
        std::cout << strNew << std::endl;*/
    
 /* std::cout << "-------------MAP DRIVER-------------" << std::endl;
  MapDriver();
  std::cout << "-------------CARDS DRIVER-------------" << std::endl;
  CardsDriver();
  std::cout << "-------------PLAYER DRIVER-------------" << std::endl;
  PlayerDriver();
  std::cout << "-------------ORDERS DRIVER-------------" << std::endl;
  OrdersDriver();
  std::cout << "-------------ENGINE DRIVER-------------" << std::endl;
  EngineDriver();*/
}