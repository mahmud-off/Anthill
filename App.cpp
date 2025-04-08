#include <iostream>
#include "AntHill.h"
#include "Field.h"
//#include "Ant.h"

#define FIELD_HEIGHT 250
#define FIELD_WIDTH 250

int main() {
    Field field(FIELD_HEIGHT, FIELD_WIDTH);
    Anthill anthill(100, FIELD_HEIGHT / 2, FIELD_WIDTH / 2);
    anthill.generateAnts(FIELD_HEIGHT / 2, FIELD_WIDTH / 2);
    field.ResourceSpawn();



    // test
    Ant* c = anthill.collecterList[0];
    pair<int, int> p = c->findNearestPoint(c->getPosX(), c->getPosY(), field.foodCoordinates);
    vector<pair<int, int>> paths = c->A_StarSearch({c->getPosX(), c->getPosY()}, p);
    for (auto x : paths) {
        cout << x.first << " " << x.second << "\n";
    }




}
