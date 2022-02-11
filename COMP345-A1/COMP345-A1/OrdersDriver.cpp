#include "Orders.h"

//int main() {
//    //Driver that creates orders of every kind, places them in an OrdersList object, and demonstrates that the above features are available. 
//    //Creating objects
//    //Creating pointers for each object
//    Deploy* deploy = new Deploy;
//    Advance* advance = new Advance;
//    Bomb* bomb = new Bomb;
//    Blockade* blockade = new Blockade;
//    Airlift* airlift = new Airlift;
//    Negotiate* negotiate = new Negotiate;
//    cout << endl;
//
//    //Create a reference for each object
//    /* Deploy& d = *deploy;
//    Advance& ad = *advance;
//    Bomb& bo = *bomb;
//    Blockade& bl = *blockade;
//    Airlift& ai = *airlift;
//    Negotiate& n = *negotiate; */
//
//    //Creating OrdersList
//    OrdersList list;
//    cout << list << endl;
//
//    //Adding each pointers to the list
//    list.addToListOfOrders(deploy);
//    list.addToListOfOrders(advance);
//    list.addToListOfOrders(bomb);
//    list.addToListOfOrders(blockade);
//    list.addToListOfOrders(airlift);
//    list.addToListOfOrders(negotiate);
//    cout << endl;
//    /*  list.addToListOfOrders2(d);
//        list.addToListOfOrders2(ad);
//        list.addToListOfOrders2(bo);
//        list.addToListOfOrders2(bl);
//        list.addToListOfOrders2(ai);
//        list.addToListOfOrders2(n);
//        cout << endl; */
//
//        //Print the filled list
//    cout << list << endl;       //This prints the base class name instead of the subclass
//
//    //Execute each order
//    deploy->execute();
//    //...
//
//    //Move the orders in the list and print
//
//    //Remove the orders in the list and print
//
//    return 0;
//}