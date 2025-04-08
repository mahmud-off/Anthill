#include "Field.h"
#include <ctime>
#include <cstdlib>

#define DAILY_FOOD_SPAWN 100
#define DAILY_MATERIALS_SPAWN 50

Field::Field(int height, int width) {
    this->height = height;
    this->width = width;
    this->field.resize(height);
    for (int i = 0; i < height; i++) {
        this->field[i].resize(width);
    }
}

void Field::materialsSpawn(int k) {
    for (int i = 0; i < k; i++) {
        srand(time(0));
        int x = rand() % this->width;
        int y = rand() % this->height;
        while (field[x][y] != "") { // если ячейка поля уже занята, то пересчитываем заново
            x = rand() % this->width;
            y = rand() % this->height;
        }
        this->field[x][y] = "materials";
    }
}

void Field::foodSpawn(int k) {
    for (int i = 0; i < k; i++) {
        srand(time(0));
        int x = rand() % this->width;
        int y = rand() % this->height;
        while (field[x][y] != "") { // если ячейка поля уже занята, то пересчитываем заново
            x = rand() % this->width;
            y = rand() % this->height;
        }
        this->field[x][y] = "food";
    }
}

void Field::ResourceSpawn() {
    this->foodSpawn(DAILY_FOOD_SPAWN);
    this->materialsSpawn(DAILY_MATERIALS_SPAWN);
}
