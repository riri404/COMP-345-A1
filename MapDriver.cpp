#include <iostream>
#include "Map.h"

int main() {
  MapLoader m{};
  m.readMap("source_maps/bigeurope.map");
  return 0;
}

