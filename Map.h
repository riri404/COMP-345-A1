#ifndef MAP_H
#define MAP_H

#include <vector>
using namespace std;

class Player;

class Territory {
  int id = 0;
  string name = "";
  int playerId = -1;  // this territory is owned by player with this id
  int armies = 0;
  vector<Territory*> adjacentTerritories = {};
public:
  ~Territory();
  Territory(int, int, sring);
  Territory(const Territory&);
  Territory& operator=(const Territory&);
  friend ostream& operator<<(ostream&, const Territory&);
};

class Continent {
  int id = 0;
  string name = "";
  int armyValue = 0;
  vector<Territory*> territories = {};
public:
  ~Continent();
  Continent(int, int, string);
  Continent(const Continent&);
  Continent& operator=(const Continent&);
  friend ostream& operator<<(ostream&, const Continent&);
}

// an adjacency list is used to represent the graph, 
// implemented with a vector of territories, where each territory contains a vector of adjacent territories
class Map {
  vector<Continent*> continents = {}; // sub graphs
  vector<Territory*> territories = {}; // adjacency list
  int numTerritories = 0;
public:
  Map();
  ~Map();
  Map(const Map&);
  Map& operator=(const Map&);
  void addTerritory(Territory* territory);
  void addBorder(Territory* t1, Territory* t2);
  bool validate() const; // TODO: validate by going through the graph, counting each nodes that has not been visited before and comparing with total number of nodes, if equal, graph is connected, otherwise no, do this for territories and continents, and finally check that continents contains no duplicate territories
};

class MapLoader {
public:
  MapLoader();
  Map* loadMap(const string&);
};

#endif