#include <iostream>
#include "Map.h"
#include <map>

void MapDriver() {
    string name = "source_maps/sw_baltic.map";
    string name1 = "source_maps/bigeurope2.map";
    string name2 = "source_maps/bigeurope.map";
    string name3 = "source_maps/invalid.txt";

    MapLoader* loader = new MapLoader();
    Map* test = loader->loadMap(name);
    cout << test->validate() << endl;

    Map* map = new Map(name);             // valid map
    if (map->validate()) cout << "MAP : " << name << " is valid !" << endl;
    else cout << "MAP : " << name << " is not valid !!" << endl;

    Map* map1 = new Map(name1);          // invalid .map file
    if (map1->validate()) cout << "MAP : " << name1 << " is valid !" << endl;
    else cout << "MAP : " << name1 << " is not valid !!" << endl;

    Map* map2 = new Map(name2);           // valid map
    if (map2->validate()) cout << "MAP : " << name2 << " is valid !" << endl;
    else cout << "MAP : " << name2 << " is not valid !!" << endl;

    Map* map3 = new Map(name3);             // invalid .txt file
    if (map3->validate()) cout << "MAP : " << name3 << " is valid !" << endl;
    else cout << "MAP : " << name3 << " is not valid !!" << endl;
}
