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
	friend class MapLoader;
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
  Territory& operator=(const Territory&); // https://www.youtube.com/watch?v=ieD3l--qgK4
  friend ostream& operator<<(ostream&, const Territory&); // https://www.youtube.com/watch?v=2972LRdyquk
	void addAdjTerritory(Territory*);
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
	void addTerritory(Territory*);
};

//-----------------------------Map---------------------------
class Map {
	friend class MapLoader;
	vector<Continent*> continents; // sub graphs
	vector<Territory*> territories;
	int numTerritories;
	bool isValid;
public:
	~Map();                      // Destructor
	Map();                       // Default Constructor
	Map(const Map&);             // Copy Constructor 
	Map& operator=(const Map&);  // Assignment operator Overloading
	friend ostream& operator << (ostream& out, const Map& );
	void addContinent(Continent* continent);
	void addTerritory(Territory* territory);
	void setNumOfTerritories(int num);
	bool validate() const;
};

//---------------------------Map loader--------------------------
// maploader will first extract the 3 sections (borders, continents and countries) of the file into 3 vectors of string which is then processed and used to initialize the map
class MapLoader {
	string fileName;
	vector<string> borders;
	vector<string> continents;
	vector<string> countries;
public:
  MapLoader(const string&);
  void readMap(); // TODO: open any .map file and fill up the 3 vectors (borders, continents and countries)
	void initializeMap(Map* map) const;
};

#endif