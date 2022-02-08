#include <iostream>
#include "Map.h"

int main() {
  Map* map = new Map("source_maps/bigeurope.txt");
  cout << map->validate() << endl;
  return 0;
}

