#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Superclass Orders
//The Order class implements a stream insertion operator that outputs a string describing the order. 
//If the order has been executed, it should also output the effect of the order, stored as a string. 
class Order {
public:
    //Constructor and destructor
    Order();
    ~Order();

    //Copy constructor, assignement and stream insertion operator
    Order(Order& anotherOrder);
    Order& operator =(const Order& anOrder);
    friend istream& operator>>(istream&, Order&);
    friend ostream& operator<<(ostream&, const Order&);

    //Getters and setters
    virtual string const getName();
    void setName(string);

    //Member functions
    bool validate();
    void execute();
private:
    string name;
};


//Each kind of order is implemented as a subclass of the Order class. 
//Every order subclass must implement the validate() method that is used to validate if the order is valid.
//Every order subclass must implement the execute() method that first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state.
class Deploy : public Order {
public:
    //Constructor and destructor
    Deploy();
    ~Deploy();

    //Copy constructor, assignement and stream insertion operator
    Deploy(Deploy& aDeploy);
    Deploy& operator =(const Deploy& aDeploy);
    friend ostream& operator<<(ostream&, const Deploy&);

    //Getters and setters
    string const getName();
    void setName(string);

    //Member functions
    bool validate();
    void execute();
private:
    string name;
};

class Advance : public Order {
public:
    //Constructor and destructor
    Advance();
    ~Advance();

    //Copy constructor, assignement and stream insertion operator
    Advance(Advance& anAdvance);
    Advance& operator =(const Advance& anAdvance);
    friend ostream& operator<<(ostream&, const Advance&);

    //Getters and setters
    string const getName();
    void setName(string);

    //Member functions
    bool validate();
    void execute();
private:
    string name;
};

class Bomb : public Order {
public:
    //Constructor and destructor
    Bomb();
    ~Bomb();

    //Copy constructor, assignement and stream insertion operator
    Bomb(Bomb& aBomb);
    Bomb& operator =(const Bomb& aBomb);
    friend ostream& operator<<(ostream&, const Bomb&);

    //Getters and setters
    string const getName();
    void setName(string);

    //Member functions
    bool validate();
    void execute();
private:
    string name;
};

class Blockade : public Order {
public:
    //Constructor and destructor
    Blockade();
    ~Blockade();

    //Copy constructor, assignement and stream insertion operator
    Blockade(Blockade& aBlockade);
    Blockade& operator =(const Blockade& aBlockade);
    friend ostream& operator<<(ostream&, const Blockade&);

    //Getters and setters
    string const getName();
    void setName(string);

    //Member functions
    bool validate();
    void execute();
private:
    string name;
};

class Airlift : public Order {
public:
    //Constructor and destructor
    Airlift();
    ~Airlift();

    //Copy constructor, assignement and stream insertion operator
    Airlift(Airlift& anAirlift);
    Airlift& operator =(const Airlift& anAirlift);
    friend ostream& operator<<(ostream&, const Airlift&);

    //Getters and setters
    string const getName();
    void setName(string);

    //Member functions
    bool validate();
    void execute();
private:
    string name;
};

class Negotiate : public Order {
public:
    //Constructor and destructor
    Negotiate();
    ~Negotiate();

    //Copy constructor, assignement and stream insertion operator
    Negotiate(Negotiate& aNegotiate);
    Negotiate& operator =(const Negotiate& aNegotiate);
    friend ostream& operator<<(ostream&, const Negotiate&);

    //Getters and setters
    string const getName();
    void setName(string);

    //Member functions
    bool validate();
    void execute();
private:
    string name;
};


//Superclass OrdersList
//The OrdersList class implements a remove() method that deletes an order from the list. 
//The OrdersList class implements a move() method to move an order in the list of orders. 
class OrdersList {
public:
    //Constructor and destructor
    OrdersList();
    OrdersList(vector<Order*>);
    ~OrdersList();

    //Copy constructor, assignement and stream insertion operator
    OrdersList(OrdersList& anOrdersList);
    OrdersList& operator =(const OrdersList& anOrdersList);
    friend ostream& operator<<(ostream&, const OrdersList&);

    //Member functions
    void addToListOfOrders(Order*);
    void move(int, int);
    void remove(int);

    //private:
        //The OrdersList class contains a list of Order objects
    vector<Order*> listOfOrders;        //vector of pointers to Order object
};
