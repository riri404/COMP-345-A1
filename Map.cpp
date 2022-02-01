#include <iostream>
#include "Map.h"

using namespace std;

Territory::~Territory() {
  for (Territory* t : adjacentTerritories) delete t;
}

Territory::Territory(int armies, int number, string name) {
  this->playerId = -1;
  this->armies = armies;
  this->number = number;
  this->name = name;
}

Territory::Territory(const Territory& other) {
  playerId = other.playerId;
  armies = other.armies;
  number = other.number;
  name = other.name;
  for (Territory* t : other.adjacentTerritories) {
    adjacentTerritories.push_back(new Territory(*t));
  }
}

Territory& Territory::operator=(const Territory& rhs) {
  playerId = rhs.playerId;
  armies = rhs.armies;
  number = rhs.number;
  name = rhs.name;
  for (Territory* t : adjacentTerritories) delete t;
  adjacentTerritories.clear();
  for (Territory* t : rhs.adjacentTerritories) {
    adjacentTerritories.push_back(new Territory(*t));
  }
}

ostream& operator<<(ostream& out, const Territory& territory) {
  out << territory.name << " (" << territory.number << ")" << endl;
  out << "Armies: " << territory.armies << endl;
  out << "Owned by player " << territory.playerId << endl;
  return out;
}

Continent::~Continent() {
  for (Territory* t : territories) delete t;
}

Continent::Continent(int armyValue, int number, string name) {
  this->armyValue = armyValue;
  this->number = number;
  this->name = name;
}

Continent::Continent(const Continent& other) {
  armyValue = other.armyValue;
  number = other.number;
  name = other.name;
  for (Territory* t : other.territories) {
    territories.push_back(new Territory(*t));
  }
}

Continent& Continent::operator=(const Continent& rhs) {
  armyValue = rhs.armyValue;
  number = rhs.number;
  name = rhs.name;
  for (Territory* t : territories) delete t;
  territories.clear();
  for (Territory* t : rhs.territories) {
    territories.push_back(new Territory(*t));
  }
}

ostream& operator<<(ostream& out, const Continent& continent) {
  out << continent.name << " (" << continent.number << ")" << endl;
  out << "Army value: " << continent.armyValue << endl;
  out << "Territories: " << endl;
  for (Territory* t : continent.territories) {
    out << *t << endl;
  }
  return out;
}