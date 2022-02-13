#include "Orders.h"
#include <iostream>
using namespace std;

void OrdersDriver() {
    //Driver that creates orders of every kind, places them in an OrdersList object, and demonstrates that the above features are available. 

    //Creating pointers for each object
    Deploy* deploy = new Deploy;
    Advance* advance = new Advance;
    Bomb* bomb = new Bomb;
    Blockade* blockade = new Blockade;
    Airlift* airlift = new Airlift;
    Negotiate* negotiate = new Negotiate;
    cout << endl;

    //Creating OrdersList
    OrdersList list;
    cout << list << endl;

    //Adding each pointers to the list
    list.addToListOfOrders(deploy);
    list.addToListOfOrders(advance);
    list.addToListOfOrders(bomb);
    list.addToListOfOrders(blockade);
    list.addToListOfOrders(airlift);
    list.addToListOfOrders(negotiate);
    cout << endl;

    //Print the filled list
    cout << list << endl;

    //Move the orders
    cout << "----------Moving orders----------" << endl;
    list.move(0, 4);
    cout << list << endl;
    list.move(2, 6);
    cout << endl;

    //Execute the orders
    deploy->execute();
    advance->execute();
    bomb->execute();
    blockade->execute();
    airlift->execute();
    negotiate->execute();
    cout << endl;

    //Remove the orders in the list
    cout << "----------Removing orders----------" << endl;
    list.remove(3);
    cout << list << endl;
    list.remove(9);
}