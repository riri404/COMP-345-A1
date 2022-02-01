#ifndef MAP_H
#define MAP_H

#include <vector>
using namespace std;

class Player;

// territory class which contains info about the territory, and the player who owns it
class Territory {
  int playerId = -1; 
  int armies = 0;
  int number = 0;
  string name = "";
  vector<Territory*> adjacentTerritories = {};
public:
  ~Territory();
  Territory(int, int, sring);
  Territory(const Territory&);
  Territory& operator=(const Territory&);
  friend ostream& operator<<(ostream&, const Territory&);
};

class Continent {
  int armyValue = 0;
  int number = 0;
  string name = "";
  vector<Territory*> territories = {};
public:
  ~Continent();
  Continent(int, int, string);
  Continent(const Continent&);
  Continent& operator=(const Continent&);
  friend ostream& operator<<(ostream&, const Continent&);
}

// map is implemented as a graph, using adjacency list
class Map {
  vector<Continent*> continents = {};
  vector<Territory*> territories = {};
  int numTerritories = 0;
public:
  Map();
  ~Map();
  Map(const Map&);
  Map& operator=(const Map&);
  void addTerritory(Territory* territory);
  void addBorder(Territory* from, Territory* to);
  bool validate() const; // TODO: validate by going through the graph, counting each nodes that has not been visited before and comparing with total number of nodes, if equal, graph is connected, otherwise no
};

class MapLoader {
public:
  MapLoader();
  Map* loadMap(const string&);
};

#endif