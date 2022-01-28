#ifndef MAP_H
#define MAP_H

#include <map>
#include <vector>
using namespace std;

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
  map<int, vector<int>> continents; // maps continent number to a vector of territory numbers
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