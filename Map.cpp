#include <iostream>
#include "Map.h"

using namespace std;

Territory::Territory(int territoryNumber, string territoryName, string continentName, int armyValue): 
  territoryNumber(territoryNumber), 
  territoryName(territoryName), 
  continentName(continentName), 
  armyValue(armyValue) { cout << "Territory " << territoryName << " created" << endl; }

