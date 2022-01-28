#ifndef MAP_H
#define MAP_H

#include <vector>
using namespace std;

class Player;

class Territory {
  int nodeIndex;
  string continentName;
  string territoryName; // i think territory is country
  int armyValue;
  Player* p; // owned by player p
  vector<Territory*> adjacentTerritories;
public:
  Territory();
  Territory(const Territory&);
  Territory& operator=(const Territory&);
};

class Map {
  vector<vector<int>>adjacencyMatrix;
  vector<Territory*> territories;
  vector<vector<Territory*>> continents;
public:
  Map();
  ~Map();
  Map(const Map&);
  Map& operator=(const Map&);
};

class MapLoader {
  MapLoader();
public:
  static Map* loadMap(const string&);
};



#endif