#include "Cards.h"
#include "Map.h"
#include "Orders.h"
#include "Player.h"
#include "GameEngine.h"
#include "CommandProcessing.h"





int main() {

    GameEngine* engine;
    engine = new GameEngine;
  //  CommandProcessor* commandProcessor = new CommandProcessor();
   // engine->AddPlayer();
   
    engine->StartupPhase();

 //  cout<< engine->SelectName("loadmap <mapfile>");
    
    system("pause");
    return 0;
    

    
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