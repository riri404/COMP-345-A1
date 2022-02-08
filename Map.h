#ifndef MAP_H
#define MAP_H

#include <vector>
using namespace std;

class Territory;
class Continent;
class Map;
class MapLoader;
class Player;

//---------------------Territory-----------------------
class Territory {
  string name;             	// territory name.
  int id;                   // territory ID.
  int playerId;             // territory owned by player with this id
  int armies;               // # of armies
	vector<Territory*> adjTerritories;
  /* constructors */
public:
  ~Territory();					        // Destructor
	Territory(); 									// Default Constructor
  Territory(int, string);  			// Constructor
  Territory(const Territory&);  // Copy Constructor
  Territory& operator=(const Territory&);
	friend bool operator==(const Territory&, const Territory&);
  friend ostream& operator<<(ostream&, const Territory&);
	void addAdjTerritory(Territory*);
	void setPlayerId(int);
	int getId() const;
	int getPlayerId() const;
	int getArmies() const;
	string getName() const;
	vector<Territory*> getAdjTerritories() const;
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
	Continent& operator=(const Continent&);
	friend ostream& operator<<(ostream&, const Continent&);
	bool isValid() const;
	void addTerritory(Territory*);
	int getId() const;
	int getArmyValue() const;
	string getName() const;
	vector<Territory*> getTerritories() const;
};

//-----------------------------Map---------------------------
class Map {
	friend class MapLoader;
	vector<Continent*> continents; // sub graphs
	vector<Territory*> territories;
	string name;
	int numTerritories;
	bool isConnected;
	void addTerritoryToContinent(int, Territory*) const;
	void addContinent(Continent*);
	void addTerritory(Territory*);
	bool validateGraph() const;
	bool validateContinents() const; // check if each continent is a connected subgraph (store all territoryid of a continent, check if each adj territory of all the territories are in the list, if one is not then it is invalid)
	bool validateTerritories() const; // check if each territory belong to only one continent
	friend bool contains(vector<Territory*>&, Territory*); // helper function for validating
public:
	~Map();                      // Destructor
	Map();                       // Default Constructor
	Map(const Map&);             // Copy Constructor 
	Map& operator=(const Map&);  // Assignment operator Overloading
	friend ostream& operator<<(ostream&, const Map& );
	Territory* findTerritory(int) const;
	Territory* findTerritory(const string&) const;
	bool validate() const;
};

//---------------------------Map loader--------------------------
// maploader will first extract the 3 sections (borders, continents and territories) of the file into 3 vectors of string which is then processed and used to initialize the map
class MapLoader {
	string mapName;
	vector<string> borders;
	vector<string> continents;
	vector<string> territories;
public:
  MapLoader();
	void readMap(const string&);
	Map* getMap(const string&);
};

#endif