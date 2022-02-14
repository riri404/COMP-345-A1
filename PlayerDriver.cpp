#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Orders.h"
#include "Cards.h"
using namespace std;


int main(){

    int playerID = 12345;
    int* id = &playerID;

    string name = "badgirlriri";
    string* n = &name;

    //creating arbitary list of territories
     Territory * t1 = new Territory();
     Territory* t2 = new Territory();
     vector<Territory*> territoryList = {t1, t2};


     // creating arbitary list of orders
     OrdersList orderList;
     //Order o1, o2;
     //Order* ptr1 = &o1;
     //Order* ptr2 = &o2;
     //orderList.addToListOfOrders(ptr1);
    // orderList.addToListOfOrders(ptr2);

     OrdersList* orderList2 = new OrdersList;
     orderList2 = &orderList;

     //creating arbitary card and then hand
     Hand x;
     //Cards* y= new Cards();{};
     //Cards* z= new Cards();
     //x.setHand(y);
     //x.setHand(z);
     Hand hand = x ;
     Hand* h = &hand;

     

     std:: cout << "Creating player\n";
     Player* player1 = new Player( id, n, territoryList, h, orderList2);
     std::cout << player1 << endl;

     //testing toAttack()
     std::cout << "testing toAttack() method---------------------------------\n";
     for (Territory* t : player1->toAttack()) {
         std::cout << (*t) << endl;
     }


     //testing toDefend()
     std::cout << "testing toDefend() method--------------------------------\n";
       for (Territory* t : player1->toDefend()) {

           std::cout << (*t) << endl;
       }



       std::cout << "testing issueOrder() method---------------------------------\n";
       player1->issueOrder("Bomb");

       //delete player that created
       delete player1;

       player1 = nullptr;

}

