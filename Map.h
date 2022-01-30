#ifndef MAP_H
#define MAP_H

#include <utility>
#include <vector>
using namespace std;

class Player;

// x and y coordinate of the circle that will be put on a territory
struct Point {
  int x = 0;
  int y = 0;
}

// territory class which contains info about the territory, and the player who owns it
class Territory {
  int territoryNumber = 0;
  int continentNumber = 0;
  string continentName = "";
  string territoryName = "";
  Point coords = {0, 0};
  Player* player = nullptr;
public:
  Territory();
  Territory(int, string, string, int);
  Territory(const Territory&);
  Territory& operator=(const Territory&);
};

class Continent {
  int continentNumber = 0;
  int armyValue = 0;
  vector<Territory*> territories = {};
}

// map is implemented as a graph, using adjacency list
class Map {
  vector<pair<int, vector<Territory*>>> adjList = {}; // adjacency list, key is the territory number and the value is a vector of adjacent territory numbers
  vector<Territory*> territories = {};
  vector<Continent*> continents = {};
  int numTerritories = 0;
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