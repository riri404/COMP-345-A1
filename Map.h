#ifndef MAP_H
#define MAP_H

#include <utility>
#include <vector>
using namespace std;

class Player;

// x and y coordinate of the circle that will be put on a territory
struct Point {
  int x;
  int y;
}

// territory class which contains info about the territory, and the player who owns it
class Territory {
  int territoryNumber;
  int continentNumber;
  string continentName;
  string territoryName;
  Point coords;
  Player* player
public:
  Territory(int, string, string, int);
  Territory(const Territory&);
  Territory& operator=(const Territory&);
};

class Continent {
  int continentNumber;
  int armyValue;
  vector<Territory*> territories;
}

// map is implemented as a graph, using adjacency list
class Map {
  vector<pair<int, vector<int>>> adjList; // adjacency list, key is the territory number and the value is a vector of adjacent territory numbers
  vector<Territory*> territories;
  vector<Continent*> continents;
  int numTerritories;
public:
  Map();
  ~Map();
  Map(const Map&);
  Map& operator=(const Map&);
  bool validate() const; // TODO: validate by going through the graph, counting each nodes that has not been visited before and comparing with total number of nodes, if equal, graph is connected, otherwise no
};

class MapLoader {
  pair<int, vector<int>> readBorder(string);
public:
  MapLoader();
  Map* loadMap(const string&);
};

#endif