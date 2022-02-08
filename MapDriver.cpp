#include <iostream>
#include "Map.h"

int main() {
  MapLoader loader{};
  Map* map = loader.getMap("source_maps/bigeurope.map");
  cout << map->validate() << endl;
  return 0;
}

