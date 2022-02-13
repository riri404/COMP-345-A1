#include <iostream>
#include "Map.h"
#include <map>

void MapDriver() {
    string name = "source_maps/sw_baltic.map";
    string name1 = "source_maps/bigeurope2.map";
    string name2 = "source_maps/bigeurope.map";
    string name3 = "source_maps/invalid.txt";

    Map* map = new Map(name);             // valid map
    Map* copy = new Map(map);
    if (map->validate() and copy->validate()) cout <<"MAP : "<<name << " is valid !" << endl;
    else cout << "MAP : " << name << " is not valid !!" << endl;

    Map map1 = new Map(name1);          // invalid .map file
    Map* copy1 = new Map(map1);
    if (map1->validate() and copy1->validate()) cout << "MAP : " << name1 << " is valid !" << endl;
    else cout << "MAP : " << name1 << " is not valid !!" << endl;

    Map map2 = new Map(name2);           // valid map
    Map* copy2 = new Map(map2);
    if (map2->validate() and copy2->validate()) cout << "MAP : " << name2 << " is valid !" << endl;
    else cout << "MAP : " << name2 << " is not valid !!" << endl;

    Map map3 = new Map(name3);             // invalid .txt file
    Map* copy3 = new Map(*map3);
    if (map3->validate() and copy3->validate()) cout << "MAP : " << name3 << " is valid !" << endl;
    else cout<<"MAP : " << name3<< " is not valid !!" << endl;
}
