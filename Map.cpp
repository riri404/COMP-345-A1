#include <iostream>
#include <string>
#include "Map.h"

using namespace std;
//---------------------Territory-----------------------
// **Destructor**
Territory::~Territory() {
  // map will handle delete
}

Territory::Territory() {
  playerId = -1;
  armies = 0;
  id = -1;
  name = "";
}

// **Constructor**
Territory::Territory(int id, string name) {
  playerId = -1;
  armies = 0; // idk whats the starting value
  this->id = id;
  this->name = name;
}
//  **Copy Constructor** 
//( other is the obj that we want to copy from).
Territory::Territory(const Territory& other) {
  playerId = other.playerId;
  armies = other.armies;
  id = other.id;
  name = other.name;
  for (Territory* t : other.adjTerritories) {
    adjTerritories.push_back(t); // shallow copy
  }
}// because we have pointers to atributrs for this class ==>
// https://www.youtube.com/watch?v=PXcRe-W2w7s
// the function operator= is a member of the class Territory we have
//  to add the class name and scoop operator like that (Territory::)
// **overload Assignment (operator = ) for Territory**
Territory& Territory::operator=(const Territory& rhs) {
  playerId = rhs.playerId;
  armies = rhs.armies;
  id = rhs.id;
  name = rhs.name;
  adjTerritories.clear();
  for (Territory* t : rhs.adjTerritories) {
    adjTerritories.push_back(t);
  }
  return *this;
}
// **Assignment operator << to print Territory object.**
ostream& operator<<(ostream& out, const Territory& territory) {
  out << "Name: " << territory.name << " (" << territory.id << ")" << endl;
  out << "Armies: " << territory.armies << endl;
  out << "Owned by player " << territory.playerId << endl;
  return out;
}

//----------------------Continent--------------------------
// **destructor**
Continent::~Continent() {
  // map will handle delete
}

Continent::Continent() {
  this->armyValue = -1;
  this->id = -1;
  this->name = "";
}

// **Constructor**
Continent::Continent(int armyValue, int id, string name) {
  this->armyValue = armyValue;
  this->id = id;
  this->name = name;
}

//  **Copy Constructor**
Continent::Continent(const Continent& other) {
  armyValue = other.armyValue;
  id = other.id;
  name = other.name;
  for (Territory* t : other.territories) {
    territories.push_back(t);
  }
}// because we have pointers to atributrs for this class ==>
// **overload Assignment (operator=) for Continent**
Continent& Continent::operator=(const Continent& rhs) {
    armyValue = rhs.armyValue;
    id = rhs.id;
    name = rhs.name;
    for (Territory* t : rhs.territories) {
        territories.push_back(t);
    }
    return *this;
}
//**Assignment operator << to print Continent object.**
ostream& operator<<(ostream& out, const Continent& continent) {
  out << "Name: " << continent.name << " (" << continent.id << ")" << endl;
  out << "Army value: " << continent.armyValue << endl;
  out << "Territories: " << endl;
  for (Territory* t : continent.territories) {
    out << *t << endl;
  }
  return out;
}

//-----------------------------Map---------------------------
Map::~Map() {
  // map will store only one address for each territory, for the whole game and delete them all after the end of the game
  for (Territory* t : territories) delete t;
}

Map::Map() {
  numTerritories = 0;
}
//---------------------------Map loader----------------------

void MapLoader::readMap(const string& file) {
  // you can work here
  // open file, google std::getline, std::istream for this part
  // https://stackoverflow.com/questions/29097127/c-reading-file-line-by-line
  // for help
}

void MapLoader::processData() {
  
}