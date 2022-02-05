#include "Orders.h"
//--------------------------ORDER---------------------------
//Default constructor
Order::Order(){
    name = new string("Order");
}

//Destructor
Order::~Order(){
    delete name;        //name is a pointer to a string
    name = NULL;
}

//Copy constructor
Order::Order(Order& anotherOrder){
    this->name = new string(*(name));
}

//Assignment operator
Order& Order::operator=(const Order &anOrder){
    this->name = new string(*(name));
    return *this;
}


istream& operator>>(istream &ins, Order& order){
    cout << "Enter order's name: ";
    ins >> *(order.name);
    return ins;
}

ostream& operator<<(ostream &outs, const Order &order){
    outs << "Order's name: " << *(order.name) << endl;
    return outs;
}

string const Order::getName(){
    return *name;
}

void Order::setName(string orderName){
    *name = orderName;
}

//--------------------------DEPLOY---------------------------
//Default constructor
Deploy::Deploy(){
    name = new string("Deploy");
}

//Destructor
Deploy::~Deploy(){
    delete name;
    name = NULL;
}

//Copy constructor
Deploy::Deploy(Deploy& anotherDeploy) : Order(anotherDeploy){
    this->name = new string(*(name));
}

//Assignment operator
Deploy& Deploy::operator=(const Deploy &aDeploy){
    this->name = new string(*(name));
    return *this;
}

ostream& operator<<(ostream &outs, const Deploy &deploy){
    outs << "Order's name: " << *(deploy.name) << endl;
    return outs;
}

bool Deploy::validate(){
    bool isValid;
    if(true){
        isValid = true;
    }
    else{
        isValid = false;
    }
    return isValid;
} 

void Deploy::execute(){
    bool isValid = validate();
    if(isValid){
        cout << "Executing deploy..." << endl;
        //execute deploy action
    }
    else{
        cout << "Cannot execute deploy." << endl;
    }
}

//--------------------------ADVANCE---------------------------
//Default constructor
Advance::Advance(){
    name = new string("Advance");
}

//Destructor
Advance::~Advance(){
    delete name;
    name = NULL;
}

//Copy constructor
Advance::Advance(Advance& anotherAdvance) : Order(anotherAdvance){
    this->name = new string(*(name));
}

//Assignment operator
Advance& Advance::operator=(const Advance &anAdvance){
    this->name = new string(*(name));
    return *this;
}

ostream& operator<<(ostream &outs, const Advance &advance){
    outs << "Order's name: " << *(advance.name) << endl;
    return outs;
}

bool Advance::validate(){
    bool isValid;
    if(true){
        isValid = true;
    }
    else{
        isValid = false;
    }
    return isValid;
}

void Advance::execute(){
    bool isValid = validate();
    if(isValid){
        cout << "Executing advance..." << endl;
        //execute advance action
    }
    else{
        cout << "Cannot execute advance." << endl;
    }
}

//--------------------------BOMB---------------------------
//Default constructor
Bomb::Bomb(){
    name = new string("Bomb");
}

//Destructor
Bomb::~Bomb(){
    delete name;
    name = NULL;
}

//Copy constructor
Bomb::Bomb(Bomb& anotherBomb) : Order(anotherBomb){
    this->name = new string(*(name));
}

//Assignment operator
Bomb& Bomb::operator=(const Bomb &aBomb){
    this->name = new string(*(name));
    return *this;
}

ostream& operator<<(ostream &outs, const Bomb &bomb){
    outs << "Order's name: " << *(bomb.name) << endl;
    return outs;
}


bool Bomb::validate(){
    bool isValid;
    if(true){
        isValid = true;
    }
    else{
        isValid = false;
    }
    return isValid;
}

void Bomb::execute(){
    bool isValid = validate();
    if(isValid){
        cout << "Executing bomb..." << endl;
        //execute bomb action
    }
    else{
        cout << "Cannot execute bomb." << endl;
    }
}

//--------------------------BLOCKADE---------------------------
//Default constructor
Blockade::Blockade(){
    name = new string("Blockade");
}

//Destructor
Blockade::~Blockade(){
    delete name;
    name = NULL;
}

//Copy constructor
Blockade::Blockade(Blockade& anotherBlockade) : Order(anotherBlockade){
    this->name = new string(*(name));
}

//Assignment operator
Blockade& Blockade::operator=(const Blockade &aBlockade){
    this->name = new string(*(name));
    return *this;
}

ostream& operator<<(ostream &outs, const Blockade &blockade){
    outs << "Order's name: " << *(blockade.name) << endl;
    return outs;
}

bool Blockade::validate(){
    bool isValid;
    if(true){
        isValid = true;
    }
    else{
        isValid = false;
    }
    return isValid;
}

void Blockade::execute(){
    bool isValid = validate();
    if(isValid){
        cout << "Executing blockade..." << endl;
        //execute blockade action
    }
    else{
        cout << "Cannot execute blockade." << endl;
    }
}

//--------------------------AIRLIFT---------------------------
//Default constructor
Airlift::Airlift(){
    name = new string("Airlift");
}

//Destructor
Airlift::~Airlift(){
    delete name;
    name = NULL;
}

//Copy constructor
Airlift::Airlift(Airlift& anotherAirlift) : Order(anotherAirlift){
    this->name = new string(*(name));
}

//Assignment operator
Airlift& Airlift::operator=(const Airlift &anAirlift){
    this->name = new string(*(name));
    return *this;
}

ostream& operator<<(ostream &outs, const Airlift &airlift){
    outs << "Order's name: " << *(airlift.name) << endl;
    return outs;
}

bool Airlift::validate(){
    bool isValid;
    if(true){
        isValid = true;
    }
    else{
        isValid = false;
    }
    return isValid;
}

void Airlift::execute(){
    bool isValid = validate();
    if(isValid){
        cout << "Executing airlift..." << endl;
        //execute airlift action
    }
    else{
        cout << "Cannot execute airlift." << endl;
    }
}

//--------------------------NEGOTIATE---------------------------
//Default constructor
Negotiate::Negotiate(){
    name = new string("Negotiate");
}

//Destructor
Negotiate::~Negotiate(){
    delete name;
    name = NULL;
}

//Copy constructor
Negotiate::Negotiate(Negotiate& anotherNegotiate) : Order(anotherNegotiate){
    this->name = new string(*(name));
}

//Assignment operator
Negotiate& Negotiate::operator=(const Negotiate &aNegotiate){
    this->name = new string(*(name));
    return *this;
}

ostream& operator<<(ostream &outs, const Negotiate &negotiate){
    outs << "Order's name: " << *(negotiate.name) << endl;
    return outs;
}

bool Negotiate::validate(){
    bool isValid;
    if(true){
        isValid = true;
    }
    else{
        isValid = false;
    }
    return isValid;
}

void Negotiate::execute(){
    bool isValid = validate();
    if(isValid){
        cout << "Executing negotiate..." << endl;
        //execute negotiate action
    }
    else{
        cout << "Cannot execute negotiate." << endl;
    }
}

////--------------------------ORDERSLIST---------------------------
//Default constructor
OrdersList::OrdersList(){

}

//Constructor
OrdersList::OrdersList(vector<Order*> anOrdersList){
    listOfOrders = anOrdersList;
}

//Destructor
OrdersList::~OrdersList(){
    for(int i = 0; i < listOfOrders.size(); i++){
        delete listOfOrders[i];               //listOfOrders[i] is a pointer to an Order object
        listOfOrders.clear();
    }
}

//Copy constructor
OrdersList::OrdersList(OrdersList& anotherOrdersList){
    this->listOfOrders = anotherOrdersList.listOfOrders;
}

//Assignment operator
OrdersList& OrdersList::operator=(const OrdersList &anOrdersList){
    listOfOrders = anOrdersList.listOfOrders;
    return *this;
}

ostream& operator<<(ostream &outs, const OrdersList &anOrdersList){
    cout << "List or orders:" << endl;
    for (int i = 0; i < anOrdersList.listOfOrders.size(); i++){
        cout << (anOrdersList.listOfOrders[i])->getName() << endl;
    }

}

void OrdersList::addToListOfOrders(Order* anOrder){
    listOfOrders.push_back(anOrder);                //Push order at the end of the list
}

void OrdersList::move(int fromIndex, int toIndex){
    //Index is out of vector bound
    if (fromIndex < 0 || fromIndex > listOfOrders.size() || toIndex < 0 || toIndex > listOfOrders.size()){
        cout << "Invalid index" << endl;
    }
    else{
        //insert(begin+position, value): Insert object at the desired position
        listOfOrders.insert(listOfOrders.begin() + toIndex, listOfOrders[fromIndex]);
        //erase(begin+position): Erase object from original position
        listOfOrders.erase(listOfOrders.begin() + fromIndex);
    }

}

void OrdersList::remove(int index){
    listOfOrders.erase(listOfOrders.begin() + index);
}
