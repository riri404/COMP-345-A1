#include <iostream>
#include <string>
#include "Player.h"
#include <Territory.h>
#include "Orders.h"
#include "Cards.h"

int main {

 //creating arbitary list of territories
  Territory* t1 = new Territory(1,"America");
  Territory* t2 = new Territory(2,"Canada");
  vector<Territory*> territoryList = {t1, t2};

  //creating arbitary hand
  Hand* cards;
  string c1 = "Deploy";
  string c2 = "Advance";
  cards.push_back(&c1);
  cards.push_back(&c2);

  // creating arbitary list of orders
  OrderList orderList;
  Order o1, o2;
  Order* ptr1 = &o1;
  Order* ptr2 = &o2;
  orderList.addToListOfOrders(ptr1);
  orderList.addToListOfOrders(ptr2);

  OrderList* orderList2 = new OrderList;
  orderList2 = &orderList;

  //creating arbitary card and then hand
  Bomb bomb;
  Card* ptrBomb = &bomb;
  vector<Card*> myHand;

  myHand.push_back(ptrBomb);

  //  MyCollectionOfCards2.push_back(PointerBlockade2);
  Hand cards(myHand);
  Hand* cardsptr = &cards;

  cout << "Creating player\n";
  Player player1 = new Player(12345,"mark", territoryList, cardsptr, orderList2);
  cout << player1 << endl;

  //testing toAttack()
  cout << "testing toAttack() method---------------------------------\n";
  for (Territory* t : player1.toAttack()) {
      cout << (*t) << endl;
  }
  
  
//testing toDefend()
  cout << "testing toDefend() method--------------------------------\n";
  for (Territory* t : player1.toDefend()) {

      cout << (*t) << endl;
  }

 

  cout << "testing issueOrder() method---------------------------------\n";
  player1.issueOrder("Bomb");

  //delete player that created
  delete player;

  player = nullptr;

}


