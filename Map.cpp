#include <iostream>
#include <string>
#include <sstream>
#include "Map.h"

using namespace std;
//---------------------Territory-----------------------
Territory::~Territory() { } // map will handle memory

Territory::Territory() {
  playerId = -1;
  armies = 0;
  id = -1;
  name = "";
}

Territory::Territory(int id, string name) {
  playerId = -1;
  armies = 0;
  this->id = id;
  this->name = name;
}

Territory::Territory(const Territory& other) {
  playerId = other.playerId;
  armies = other.armies;
  id = other.id;
  name = other.name;
  for (Territory* t : other.adjTerritories) {
    adjTerritories.push_back(t); // shallow copy
  }
}

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

ostream& operator<<(ostream& out, const Territory& territory) {
  out << "Name: " << territory.name << " (" << territory.id << ")" << endl;
  out << "Armies: " << territory.armies << endl;
  out << "Owned by player " << territory.playerId << endl;
  return out;
}

void Territory::addAdjTerritory(Territory* t) {
  adjTerritories.push_back(t);
}

// getter and setters
void Territory::setPlayerId(int playerId) { this->playerId = playerId; }
int Territory::getId() { return id; }
int Territory::getPlayerId() { return playerId; }
int Territory::getArmies() { return armies; }
string Territory::getName() { return name; }
vector<Territory*> Territory::getAdjTerritories() { return adjTerritories; }

//----------------------Continent--------------------------
Continent::~Continent() { } // map will handle memory

Continent::Continent() {
  this->armyValue = -1;
  this->id = -1;
  this->name = "";
}

Continent::Continent(int armyValue, int id, string name) {
  this->armyValue = armyValue;
  this->id = id;
  this->name = name;
}

Continent::Continent(const Continent& other) {
  armyValue = other.armyValue;
  id = other.id;
  name = other.name;
  for (Territory* t : other.territories) {
    territories.push_back(t);
  }
}

Continent& Continent::operator=(const Continent& rhs) {
    armyValue = rhs.armyValue;
    id = rhs.id;
    name = rhs.name;
    for (Territory* t : rhs.territories) {
        territories.push_back(t);
    }
    return *this;
}

ostream& operator<<(ostream& out, const Continent& continent) {
  out << "Name: " << continent.name << " (" << continent.id << ")" << endl;
  out << "Army value: " << continent.armyValue << endl;
  out << "Territories: " << endl;
  for (Territory* t : continent.territories) {
    out << *t << endl;
  }
  return out;
}

void Continent::addTerritory(Territory* t) { 
  territories.push_back(t); 
}

// getters and setters
int Continent::getId() { return id; }
int Continent::getArmyValue() { return armyValue; }
string Continent::getName() { return name; }
vector<Territory*> Continent::getTerritories() { return territories; }

//-----------------------------Map---------------------------
Map::~Map() {
  // map will store only one address for each territory, for the whole game and delete them all after the end of the game
  // and delete all the continents also
  for (Territory* t : territories) delete t;
  for (Continent* c : continents) delete c;
}

Map::Map() {
  numTerritories = 0;
  isConnected = false;
}

void Map::addTerritoryToContinent(int continentId, Territory* t) {
  for (Continent* c : continents) {
    if (c->getId() == continentId) {
      c->addTerritory(t);
      break;
    }
  }
}

void Map::addTerritory(Territory* t) {
  territories.push_back(t);
}

void Map::addContinent(Continent* t) {
  continents.push_back(t);
}

Territory* Map::findTerritory(int id) {
  for (Territory* t : territories) {
    if (t->getId() == id) return t;
  }
  return nullptr;
}

Territory* Map::findTerritory(const string& name) {
  for (Territory* t : territories) {
    if (t->getName() == name) return t;
  }
  return nullptr;
}

bool Map::validateContinents() {
  for (Continent* c : continents) {
    
  }
}

bool Map::validate() {
  // TODO
}

//---------------------------Map loader----------------------
void MapLoader::MapLoader() {
  mapName = "Map"; // default name
}

void MapLoader::readMap(const string& fileName) {
  // you can work here
  // open file, google std::getline, std::istream for this part
  // https://stackoverflow.com/questions/29097127/c-reading-file-line-by-line
  // for help
  // get the map name too just in case
}

void MapLoader::getMap() {
  Map* map = new Map();
  readMap();
  map->name = mapName;
  map->numTerritories = territories.size();
  for (int i = 0; i < continents.size(); ++i) {
    // initializing continents
    istringstream iss(continents[i]);
    string name = "";
    int armyValue = 0;
    int id = i + 1;
    iss >> name >> armyValue;
    map->addContinent(new Continent(armyValue, id, name));
  }
  for (const string& territory : territories) {
    // initializing territories, and adding territories to continents
    istringstream iss(territory);
    int id = 0;
    string name = "";
    int continentId = 0;
    iss >> id >> name >> continentId;
    Territory* t = new Territory(id, name);
    map->addTerritory(t);
    map->addTerritoryToContinent(continentId, t);
  }
  for (const string& border : borders) {
    // adding all the adj territories to each territory
    istringstream iss(border);
    int id = 0; // territory;
    int adjId = 0; // adj territory
    iss >> id; 
    Territory* t = map->findTerritory(id);
    bool isConnected = false;
    while (iss >> adjId) {
      Territory* adjT = map->findTerritory(adjId);
      t->addAdjTerritory(adjT);
      isConnected = true;;
    }
    // if theres no adj territories for one territory,
    // then graph is not connected
    map->isConnected = isConnected;
    return map;
  }
}