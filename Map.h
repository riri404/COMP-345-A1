#ifndef MAP_H
#define MAP_H

#include <map>
#include <vector>
using namespace std;

class Player;

// simple struct to hold 2 values (key and value)
template <class K, class V>
struct Pair {
  K key;
  V value;
}

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
  int armyValue;
  Point coords;
  Player* player
public:
  Territory(int, string, string, int);
  Territory(const Territory&);
  Territory& operator=(const Territory&);
};

// map is implemented as a graph, using adjacency list
class Map {
  vector<Pair<int, vector<Territory*>>> territories;
  vector<Pair<int, vector<Territory*>>> continents;
  int numTerritories;
public:
  Map();
  ~Map();
  Map(const Map&);
  Map& operator=(const Map&);
  bool validate() const; // TODO: validate by going through the graph, counting each nodes that has not been visited before and comparing with total number of nodes, if equal, graph is connected, otherwise no
};

// copy constructor and copy assignment operator omitted because it makes no sense
// only purpose is to take a .map file and return a map object
// for continents, create an array, and array[index] = continent name, continent number = index + 1
class MapLoader {
  pair<int, vector<int>> readBorder(string);

public:
  MapLoader();
  Map* loadMap(const string&);
};

#endif