#include <iostream>
#include "Map.h"

int main() {
  Map* map = new Map("source_maps/bigeurope.map");
  cout << map->validate() << endl;
  return 0;
}

