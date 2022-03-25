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
    name = anotherOrder.name;
}

//Assignment operator
Order& Order::operator=(const Order& anOrder) {
    name = anOrder.name;
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
    return name;
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
         Notify(this);
        //execute deploy action
    }
    else {
        cout << "Cannot execute order." << endl;
    }
}

string Order::stringToLog() {
    return "Order " + name + " executed";
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
    name = anotherDeploy.name;
}

//Assignment operator
Deploy& Deploy::operator=(const Deploy& aDeploy) {
    name = aDeploy.name;
    return *this;
}

ostream& operator<<(ostream& outs, const Deploy& deploy) {
    outs << "Order's name: " << deploy.name << endl;
    return outs;
}

string const Deploy::getName() {
    return name;
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
    name = anotherAdvance.name;
}

//Assignment operator
Advance& Advance::operator=(const Advance& anAdvance) {
    name = anAdvance.name;
    return *this;
}

ostream& operator<<(ostream& outs, const Advance& advance) {
    outs << "Order's name: " << advance.name << endl;
    return outs;
}

string const Advance::getName() {
    return name;
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
    name = anotherBomb.name;
}

//Assignment operator
Bomb& Bomb::operator=(const Bomb& aBomb) {
    name = aBomb.name;
    return *this;
}

ostream& operator<<(ostream& outs, const Bomb& bomb) {
    outs << "Order's name: " << bomb.name << endl;
    return outs;
}

string const Bomb::getName() {
    return name;
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
    name = anotherBlockade.name;
}

//Assignment operator
Blockade& Blockade::operator=(const Blockade& aBlockade) {
    name = aBlockade.name;
    return *this;
}

ostream& operator<<(ostream& outs, const Blockade& blockade) {
    outs << "Order's name: " << blockade.name << endl;
    return outs;
}

string const Blockade::getName() {
    return name;
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
    name = anotherAirlift.name;
}

//Assignment operator
Airlift& Airlift::operator=(const Airlift& anAirlift) {
    name = anAirlift.name;
    return *this;
}

ostream& operator<<(ostream& outs, const Airlift& airlift) {
    outs << "Order's name: " << airlift.name << endl;
    return outs;
}

string const Airlift::getName() {
    return name;
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
    name = anotherNegotiate.name;
}

//Assignment operator
Negotiate& Negotiate::operator=(const Negotiate& aNegotiate) {
    name = aNegotiate.name;
    return *this;
}

ostream& operator<<(ostream& outs, const Negotiate& negotiate) {
    outs << "Order's name: " << negotiate.name << endl;
    return outs;
}

string const Negotiate::getName() {
    return name;
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

void OrdersList::addToListOfOrders(Order* order) {
    listOfOrders.push_back(order);                //Push order at the end of the list
    cout << stringToLog() << endl;
    
    notifyAddOrder(order);
    Notify(this);
}

void OrdersList::move(int fromIndex, int toIndex) {
    if ((fromIndex >= 0 && fromIndex <= listOfOrders.size() - 1) && (toIndex >= 0 && toIndex <= listOfOrders.size() - 1)) {
        listOfOrders.insert(listOfOrders.begin() + toIndex, listOfOrders.at(fromIndex));
        listOfOrders.erase(listOfOrders.begin() + fromIndex);
    }
    else {
        cout << "Cannot move: invalid index" << endl;
    }
}

void OrdersList::remove(int index) {
    if (index >= 0 && index <= listOfOrders.size() - 1) {
        listOfOrders.erase(listOfOrders.begin() + index);
    }
    else {
        cout << "Cannot remove: invalid index" << endl;
    }
}

string OrdersList::stringToLog() {
    Order* latestOrder = listOfOrders.back();
    return "Order " + latestOrder->getName() + " added";
}

void OrdersList::notifyAddOrder(Order* order) {
    for (auto observer : *observers) {
        order->Attach(observer);
    }
}