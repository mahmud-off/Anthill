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
    c->work(field);

}
