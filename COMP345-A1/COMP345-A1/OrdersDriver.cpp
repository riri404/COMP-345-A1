#include "Orders.h"
//--------------------------ORDER---------------------------
//Default constructor
Order::Order() {
    name = "Order";
}

//Destructor
Order:: ~Order() {

}

//Copy constructor
Order::Order(Order& anotherOrder) {
    this->name = anotherOrder.name;
}

//Assignment operator
Order& Order::operator=(const Order& anOrder) {
    this->name = anOrder.name;
    return *this;
}


istream& operator>>(istream& ins, Order& order) {
    cout << "Enter order's name: ";
    ins >> order.name;
    return ins;
}

ostream& operator<<(ostream& outs, const Order& order) {
    outs << "Order's name: " << order.name << endl;
    return outs;
}

string const Order::getName() {
    return this->name;
}

void Order::setName(string orderName) {
    name = orderName;
}

bool Order::validate() {
    bool isValid;
    if (true) {
        isValid = true;
    }
    else {
        isValid = false;
    }
    return isValid;
}

void Order::execute() {
    bool isValid = validate();
    if (isValid) {
        cout << "Executing order..." << endl;
        //execute deploy action
    }
    else {
        cout << "Cannot execute order." << endl;
    }
}


//--------------------------DEPLOY---------------------------
//Default constructor
Deploy::Deploy() {
    name = "Deploy";
    cout << "Deploy has been created." << endl;
}

//Destructor
Deploy::~Deploy() {

}

//Copy constructor
Deploy::Deploy(Deploy& anotherDeploy) : Order(anotherDeploy) {
    this->name = anotherDeploy.name;
}

//Assignment operator
Deploy& Deploy::operator=(const Deploy& aDeploy) {
    this->name = aDeploy.name;
    return *this;
}

ostream& operator<<(ostream& outs, const Deploy& deploy) {
    outs << "Order's name: " << deploy.name << endl;
    return outs;
}

string const Deploy::getName() {
    return this->name;
}

bool Deploy::validate() {
    bool isValid;
    if (true) {
        isValid = true;
    }
    else {
        isValid = false;
    }
    return isValid;
}

void Deploy::execute() {
    bool isValid = validate();
    if (isValid) {
        cout << "Executing deploy..." << endl;
        //execute deploy action
    }
    else {
        cout << "Cannot execute deploy." << endl;
    }
}

//--------------------------ADVANCE---------------------------
//Default constructor
Advance::Advance() {
    name = "Advance";
    cout << "Advance has been created" << endl;
}

//Destructor
Advance::~Advance() {

}

//Copy constructor
Advance::Advance(Advance& anotherAdvance) : Order(anotherAdvance) {
    this->name = anotherAdvance.name;
}

//Assignment operator
Advance& Advance::operator=(const Advance& anAdvance) {
    this->name = anAdvance.name;
    return *this;
}

ostream& operator<<(ostream& outs, const Advance& advance) {
    outs << "Order's name: " << advance.name << endl;
    return outs;
}

string const Advance::getName() {
    return this->name;
}

bool Advance::validate() {
    bool isValid;
    if (true) {
        isValid = true;
    }
    else {
        isValid = false;
    }
    return isValid;
}

void Advance::execute() {
    bool isValid = validate();
    if (isValid) {
        cout << "Executing advance..." << endl;
        //execute advance action
    }
    else {
        cout << "Cannot execute advance." << endl;
    }
}

//--------------------------BOMB---------------------------
//Default constructor
Bomb::Bomb() {
    name = "Bomb";
    cout << "Bomb has been created" << endl;
}

//Destructor
Bomb::~Bomb() {

}

//Copy constructor
Bomb::Bomb(Bomb& anotherBomb) : Order(anotherBomb) {
    this->name = anotherBomb.name;
}

//Assignment operator
Bomb& Bomb::operator=(const Bomb& aBomb) {
    this->name = aBomb.name;
    return *this;
}

ostream& operator<<(ostream& outs, const Bomb& bomb) {
    outs << "Order's name: " << bomb.name << endl;
    return outs;
}

string const Bomb::getName() {
    return this->name;
}

bool Bomb::validate() {
    bool isValid;
    if (true) {
        isValid = true;
    }
    else {
        isValid = false;
    }
    return isValid;
}

void Bomb::execute() {
    bool isValid = validate();
    if (isValid) {
        cout << "Executing bomb..." << endl;
        //execute bomb action
    }
    else {
        cout << "Cannot execute bomb." << endl;
    }
}

//--------------------------BLOCKADE---------------------------
//Default constructor
Blockade::Blockade() {
    name = "Blockade";
    cout << "Blockade has been created" << endl;
}

//Destructor
Blockade::~Blockade() {

}

//Copy constructor
Blockade::Blockade(Blockade& anotherBlockade) : Order(anotherBlockade) {
    this->name = anotherBlockade.name;
}

//Assignment operator
Blockade& Blockade::operator=(const Blockade& aBlockade) {
    this->name = aBlockade.name;
    return *this;
}

ostream& operator<<(ostream& outs, const Blockade& blockade) {
    outs << "Order's name: " << blockade.name << endl;
    return outs;
}

string const Blockade::getName() {
    return this->name;
}

bool Blockade::validate() {
    bool isValid;
    if (true) {
        isValid = true;
    }
    else {
        isValid = false;
    }
    return isValid;
}

void Blockade::execute() {
    bool isValid = validate();
    if (isValid) {
        cout << "Executing blockade..." << endl;
        //execute blockade action
    }
    else {
        cout << "Cannot execute blockade." << endl;
    }
}

//--------------------------AIRLIFT---------------------------
//Default constructor
Airlift::Airlift() {
    name = "Airlift";
    cout << "Airlift has been created" << endl;
}

//Destructor
Airlift::~Airlift() {

}

//Copy constructor
Airlift::Airlift(Airlift& anotherAirlift) : Order(anotherAirlift) {
    this->name = anotherAirlift.name;
}

//Assignment operator
Airlift& Airlift::operator=(const Airlift& anAirlift) {
    this->name = anAirlift.name;
    return *this;
}

ostream& operator<<(ostream& outs, const Airlift& airlift) {
    outs << "Order's name: " << airlift.name << endl;
    return outs;
}

string const Airlift::getName() {
    return this->name;
}

bool Airlift::validate() {
    bool isValid;
    if (true) {
        isValid = true;
    }
    else {
        isValid = false;
    }
    return isValid;
}

void Airlift::execute() {
    bool isValid = validate();
    if (isValid) {
        cout << "Executing airlift..." << endl;
        //execute airlift action
    }
    else {
        cout << "Cannot execute airlift." << endl;
    }
}

//--------------------------NEGOTIATE---------------------------
//Default constructor
Negotiate::Negotiate() {
    name = "Negotiate";
    cout << "Negotiate has been created" << endl;
}

//Destructor
Negotiate::~Negotiate() {

}

//Copy constructor
Negotiate::Negotiate(Negotiate& anotherNegotiate) : Order(anotherNegotiate) {
    this->name = anotherNegotiate.name;
}

//Assignment operator
Negotiate& Negotiate::operator=(const Negotiate& aNegotiate) {
    this->name = aNegotiate.name;
    return *this;
}

ostream& operator<<(ostream& outs, const Negotiate& negotiate) {
    outs << "Order's name: " << negotiate.name << endl;
    return outs;
}

string const Negotiate::getName() {
    return this->name;
}

bool Negotiate::validate() {
    bool isValid;
    if (true) {
        isValid = true;
    }
    else {
        isValid = false;
    }
    return isValid;
}

void Negotiate::execute() {
    bool isValid = validate();
    if (isValid) {
        cout << "Executing negotiate..." << endl;
        //execute negotiate action
    }
    else {
        cout << "Cannot execute negotiate." << endl;
    }
}

////--------------------------ORDERSLIST---------------------------
//Default constructor
OrdersList::OrdersList() {

}

//Constructor
OrdersList::OrdersList(vector<Order*> anOrdersList) {
    listOfOrders = anOrdersList;
}

//Destructor
OrdersList::~OrdersList() {
    for (int i = 0; i < listOfOrders.size(); i++) {
        delete listOfOrders[i];               //listOfOrders[i] is a pointer to an Order object
        listOfOrders.clear();
    }
}

//Copy constructor
OrdersList::OrdersList(OrdersList& anotherOrdersList) {
    this->listOfOrders = anotherOrdersList.listOfOrders;
}

//Assignment operator
OrdersList& OrdersList::operator=(const OrdersList& anOrdersList) {
    listOfOrders = anOrdersList.listOfOrders;
    return *this;
}

ostream& operator<<(ostream& outs, const OrdersList& anOrdersList) {
    cout << "List of orders:" << endl;
    for (int i = 0; i < anOrdersList.listOfOrders.size(); i++) {
        cout << i << ":" << (anOrdersList.listOfOrders[i])->getName() << endl;
    }
    return outs;
}

void OrdersList::addToListOfOrders(Order* anOrder) {
    listOfOrders.push_back(anOrder);                //Push order at the end of the list
    cout << anOrder->getName() << " added" << endl;
}

/* void OrdersList::addToListOfOrders2(Order& o){
    Order* p = &o;
    Deploy* p1 = dynamic_cast<Deploy*>(p);
    Advance* p2 = dynamic_cast<Advance*>(p);
    Bomb* p3 = dynamic_cast<Bomb*>(p);
    Blockade* p4 = dynamic_cast<Blockade*>(p);
    Airlift* p5 = dynamic_cast<Airlift*>(p);
    Negotiate* p6 = dynamic_cast<Negotiate*>(p);
    listOfOrders.push_back(p);
    if (p1 != NULL){
        cout << p1->getName() << " added" << endl;
    }
    if (p2 != NULL){
        cout << p2->getName() << " added" << endl;
    }
    if (p3 != NULL){
        cout << p3->getName() << " added" << endl;
    }
    if (p4 != NULL){
        cout << p4->getName() << " added" << endl;
    }
    if (p5 != NULL){
        cout << p5->getName() << " added" << endl;
    }
    if (p6 != NULL){
        cout << p6->getName() << " added" << endl;
    }
} */

void OrdersList::move(int fromIndex, int toIndex) {
    //Index is out of vector bound
    if (fromIndex < 0 || fromIndex > listOfOrders.size() || toIndex < 0 || toIndex > listOfOrders.size()) {
        cout << "Invalid index" << endl;
    }
    else {
        //insert(begin+position, value): Insert object at the desired position
        listOfOrders.insert(listOfOrders.begin() + toIndex, listOfOrders[fromIndex]);
        //erase(begin+position): Erase object from original position
        listOfOrders.erase(listOfOrders.begin() + fromIndex);
    }
}

void OrdersList::remove(int index) {
    listOfOrders.erase(listOfOrders.begin() + index);
}

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