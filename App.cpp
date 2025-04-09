#include <iostream>
#include "AntHill.h"
#include "Field.h"
//#include "Ant.h"

#define FIELD_HEIGHT 250
#define FIELD_WIDTH 250

int main() {
    Field field(FIELD_WIDTH, FIELD_HEIGHT);
    Anthill anthill(100, FIELD_HEIGHT / 2, FIELD_WIDTH / 2);
    anthill.generateAnts(FIELD_HEIGHT / 2, FIELD_WIDTH / 2);
    field.ResourceSpawn();



    // test foodCoordinates
    // for (int i = 0; i < field.foodCoordinates.size(); i++) {
    //     auto cur = field.foodCoordinates[i];
    //     cout << cur.first << " " << cur.second.first << " " << cur.second.second << "\n";
    // }

    // test collecters work
    cout << anthill.collecterList[1]->getWeight() << "\n";
    anthill.collecterList[2]->work(field);

    // test builders work

}
