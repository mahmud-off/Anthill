#include <iostream>
#include "AntHill.h"
#include "Field.h"

#define FIELD_HEIGHT 250
#define FIELD_WIDTH 250

void worldCreation() {
    Field field(FIELD_HEIGHT, FIELD_WIDTH);
    Anthill anthill(100, FIELD_HEIGHT / 2, FIELD_WIDTH / 2);
    anthill.generateAnts();
    field.ResourceSpawn();
}

int main() {
    worldCreation();
}
