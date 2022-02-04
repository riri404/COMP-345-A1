#ifndef MAP_H
#define MAP_H

#include <vector>
using namespace std;

class Player;
//---------------------Territory-----------------------
class Territory {
  string name;             // territorys name.
  int id;                   // territorys ID.
  int playerId;             // territory owned by player with this id
  int armies;               // # of armies
  /* constructors */
public:
  ~Territory();					        // Destructor
	Territory(); 									// Default Constructor
  Territory(int, string);  // Constructor
  Territory(const Territory&);  // Copy Constructor
  Territory& operator=(const Territory&);//!! // Assignment operator Overloading 
	                 // when data members are type pointer and we need deep copies
	                 // and we have a copy constructor.
	                 // https://www.youtube.com/watch?v=ieD3l--qgK4
  friend ostream& operator<<(ostream&, const Territory&);//!!// we use this when
                     //we want to print a user defined class object using COUT.
					 //https://www.youtube.com/watch?v=2972LRdyquk
};

//----------------------Continent--------------------------
class Continent {
	int id;
	int armyValue;
	string name;
	vector<Territory*> territories;
	/* constructors */
public:
	~Continent();                      // Destructor
	Continent(); // added              // Default Constructor
	Continent(int, int, string);       // Constructor
	Continent(const Continent&);       // Copy Constructor
	Continent& operator=(const Continent&); // Assignment operator Overloading 
	                 // when data members are type pointer and we need deep copies
	                 // and we have a copy constructor.
	                 // https://www.youtube.com/watch?v=ieD3l--qgK4
	friend ostream& operator<<(ostream&, const Continent&);//!! // we use this when
                     //we want to print a user defined class object using COUT.
					 //https://www.youtube.com/watch?v=2972LRdyquk
};

// an adjacency list is used to represent the graph, 
//-----------------------------Map---------------------------
class Map {
	vector<Continent*> continents; // sub graphs
	// continents[continentId - 1] to access continent of that id
	vector<vector<Territory*>> adjList; // adjacency list
	// we are going to use the id of the territory as index
	// territories[0] === adj territories of territory with id 1
	// so, territories[territoryId - 1] used to access ajd territories
	vector<Territory*> territories;
	// all territories stored, for now to have a map from territoryId to its name
	int numTerritories;
public:
	~Map();                      // Destructor
	Map();                       // Default Constructor
	Map(const Map&);             // Copy Constructor 
	Map& operator=(const Map&);  // Assignment operator Overloading
	friend ostream& operator << (ostream& out, const Map& );//added//
	void addContinentToMap(Continent* continent);  //added//
	void addTerritory(Territory* territory);
	void addBorder(Territory* t1, Territory* t2);
	
	bool validate() const; // TODO: validate by going through the graph, 
	                       //counting each nodes that has not been visited 
	                       //before and comparing with total number of nodes
	                       //, if equal, graph is connected, otherwise no, 
	                       //do this for territories and continents, 
		                  	 //and finally check that continents contains 
	                       //no duplicate territories.
};
//---------------------------Map loader--------------------------
class MapLoader {
	string fileName; // to read the file name???
	vector<string> borders; // store each line of the border section in the vector
	// ex. ["1 2 3 4", "2 12 10 5", ...]
	vector<string> continents; // same as borders
	vector<string> countries;  // same as borders
	// check source_maps folder for an example file
	// we will obtain all the data first, then we will process the data and create the objects
public:
  ~MapLoader();//do we need this?? 
  MapLoader();
  MapLoader(const MapLoader&);// do we need this??
  MapLoader& operator = (const MapLoader& );// do we need this??
  friend ostream& operator<<(ostream& out, const MapLoader&); //added//ostream operator
  void readMap(const string&); // TODO: open any .map file and fill up the 3 vectors (borders, continents and countries)
	void processData(); // not completed yet
};

#endif