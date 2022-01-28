#ifndef MAP_H
#define MAP_H

#include <map>
#include <vector>
using namespace std;

// territory class which contains info about the territory, and the player who owns it
class Territory {
  int territoryNumber;
  string continentName;
  string territoryName;
  int armyValue;
  // Player* p
public:
  Territory(int, string, string, int);
  Territory(const Territory&);
  Territory& operator=(const Territory&);
};

// map is implemented as sort of a graph, using adjacency list, where the territory numbers are used as the value in the adjacency list
class Map {
  map<int, vector<int>> adjList; // key represents the territory and value represent the adjacent territories
  map<int, Territory*> territories; // maps territory number to the territory object
  int numTerritories;
public:
  Map();
  ~Map();
  Map(const Map&);
  Map& operator=(const Map&);
  bool validate() const;
};

// copy constructor and copy assignment operator omitted because it makes no sense
// only purpose is to take a .map file and return a map object
class MapLoader {
public:
  MapLoader();
  Map* loadMap(const string&);
};

#endif