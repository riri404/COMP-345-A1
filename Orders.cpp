#include "Orders.h"
/////////////////////////////////////////////////////////////ORDER
//Default constructor
Order::Order(){

}

//Destructor
Order::~Order(){

}

//Copy constructor
Order::Order(Order& anotherOrder){

}

//Assignment operator
Order& Order::operator=(const Order &anOrder){

}


istream& operator>>(istream &ins, Order& order){

}

ostream& operator<<(ostream &outs, const Order &order){

}

/////////////////////////////////////////////////////////////DEPLOY
//Default constructor
Deploy::Deploy(){

}

//Destructor
Deploy::~Deploy(){

}

//Copy constructor
Deploy::Deploy(Deploy& anotherDeploy){

}

//Assignment operator
Deploy& Deploy::operator=(const Deploy &aDeploy){

}

istream& operator>>(istream &ins, Deploy& deploy){

}

ostream& operator<<(ostream &outs, const Deploy &deploy){

}

bool Deploy::validate(){

} 

void Deploy::execute(){

}


/////////////////////////////////////////////////////////////ADVANCE
//Default constructor
Advance::Advance(){

}

//Destructor
Advance::~Advance(){

}

//Copy constructor
Advance::Advance(Advance& anotherAdvance){

}

//Assignment operator
Advance& Advance::operator=(const Advance &anAdvance){

}

istream& operator>>(istream &ins, Advance& advance){

}

ostream& operator<<(ostream &outs, const Advance &advance){

}

bool Advance::validate(){

}

void Advance::execute(){

}

/////////////////////////////////////////////////////////////BOMB
//Default constructor
Bomb::Bomb(){

}

//Destructor
Bomb::~Bomb(){

}

//Copy constructor
Bomb::Bomb(Bomb& anotherBomb){

}

//Assignment operator
Bomb& Bomb::operator=(const Bomb &aBomb){

}

istream& operator>>(istream &ins, Bomb& bomb){

}

ostream& operator<<(ostream &outs, const Bomb &bomb){

}


bool Bomb::validate(){

}

void Bomb::execute(){

}

/////////////////////////////////////////////////////////////BLOCKADE
//Default constructor
Blockade::Blockade(){

}

//Destructor
Blockade::~Blockade(){

}

//Copy constructor
Blockade::Blockade(Blockade& anotherBlocakde){

}

//Assignment operator
Blockade& Blockade::operator=(const Blockade &aBlockade){

}

istream& operator>>(istream &ins, Blockade& blockade){

}

ostream& operator<<(ostream &outs, const Blockade &blockade){

}

bool Blockade::validate(){

}

void Blockade::execute(){

}

/////////////////////////////////////////////////////////////AIRLIFT
//Default constructor
Airlift::Airlift(){

}

//Destructor
Airlift::~Airlift(){

}

//Copy constructor
Airlift::Airlift(Airlift& anotherAirlift){

}

//Assignment operator
Airlift& Airlift::operator=(const Airlift &anAirlift){

}

istream& operator>>(istream &ins, Airlift& airlift){

}

ostream& operator<<(ostream &outs, const Airlift &airlift){

}

bool Airlift::validate(){

}

void Airlift::execute(){

}

/////////////////////////////////////////////////////////////NEGOTIATE
//Default constructor
Negotiate::Negotiate(){

}

//Destructor
Negotiate::~Negotiate(){

}

//Copy constructor
Negotiate::Negotiate(Negotiate& anotherNegotiate){

}

//Assignment operator
Negotiate& Negotiate::operator=(const Negotiate &aNegotiate){

}

istream& operator>>(istream &ins, Negotiate& negotiate){

}

ostream& operator<<(ostream &outs, const Negotiate &negotiate){

}

bool Negotiate::validate(){

}

void Negotiate::execute(){

}

/////////////////////////////////////////////////////////////ORDERSLIST
//Default constructor
OrdersList::OrdersList(){

}

//Destructor
OrdersList::~OrdersList(){

}

//Copy constructor
OrdersList::OrdersList(OrdersList& anotherOrdersList){

}

//Assignment operator
OrdersList& OrdersList::operator=(const OrdersList &anOrdersList){

}

istream& operator>>(istream &ins, OrdersList& ordersList){

}

ostream& operator<<(ostream &outs, const OrdersList &anOrdersList){

}

void OrdersList::addToListOfOrders(Order anOrder){

}

void OrdersList::move(int fromIndex, int toIndex){

}

void OrdersList::remove(int index){

}
