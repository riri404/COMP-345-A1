#include <iostream>
#include "Map.h"

int main() {
  Map* map = new Map("source_maps/bigeurope.map");
  Map* copy = new Map(*map);
  cout << map->validate() << endl;
  cout << copy->validate() << endl;
  return 0;
}

