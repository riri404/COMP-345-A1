#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Superclass Orders
//The Order class implements a stream insertion operator that outputs a string describing the order. 
//If the order has been executed, it should also output the effect of the order, stored as a string. 
class Order{
    public:
        //Constructor and destructor
        Order();
        ~Order();

        //Member functions
        bool validate();
        void execute();

        //Copy constructor, assignement and stream insertion operator
        Order(Order& anOrder);
        Order& operator =(const Order &anOrder);
        friend ostream& operator<<(ostream&, const Order&);  //Lecture 3, p.7
    private:
        //...
};


//Each kind of order is implemented as a subclass of the Order class. 
//Every order subclass must implement the validate() method that is used to validate if the order is valid.
//Every order subclass must implement the execute() method that first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state.
class Deploy : public Order{
    public:
        //Constructor and destructor
        Deploy();
        ~Deploy();

        //Member functions
        bool validate();
        void execute();

};

class Advance : public Order{
    public:
        //Constructor and destructor
        Advance();
        ~Advance();

        //Member functions
        bool validate();
        void execute();

};

class Bomb : public Order{
    public:
        //Constructor and destructor
        Bomb();
        ~Bomb();

        //Member functions
        bool validate();
        void execute();
};

class Blockade : public Order{
    public:
        //Constructor and destructor
        Blockade();
        ~Blockade();

        //Member functions
        bool validate();
        void execute();
};

class Airlift : public Order{
    public:
        //Constructor and destructor
        Airlift();
        ~Airlift();

        //Member functions
        bool validate();
        void execute();
};

class Negotiate : public Order{
    public:
        //Constructor and destructor
        Negotiate();
        ~Negotiate();

        //Member functions
        bool validate();
        void execute();
};


//Superclass OrdersList
//The OrdersList class implements a remove() method that deletes an order from the list. 
//The OrdersList class implements a move() method to move an order in the list of orders. 
class OrdersList{
    public:
        //Constructor and destructor
        OrdersList();
        ~OrdersList();

        //Member functions
        void remove();
        void move();
    
    private:
        //The OrdersList class contains a list of Order objects
        vector<Order> listOfOrders;

        //Copy constructor, assignement and stream insertion operator
        OrdersList(OrdersList& anOrdersList);
        OrdersList& operator =(const OrdersList &anOrdersList);
        friend ostream& operator<<(ostream&, const OrdersList&);  //Lecture 3, p.7
};
