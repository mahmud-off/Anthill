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
        this->materialsCoordinates.push_back({x, y});
    }
}

void Field::createEnemy()
{
    //first - compute Enemy's point
    srand(time(0));
    int x = rand() % this->width;
    int y = rand() % this->height;
    while (field[x][y] != "") { // point is free +
        x = rand() % this->width;
        y = rand() % this->height;
    }
    //create Enemy
    Enemy* newEnemy = new Enemy(x,y);
    enemies.push_back(newEnemy);
}

void Field::deleteEnemy(Enemy *killed) // O(Enemies count)
{
    for(int i = 0; i < enemies.size(); ++i) {
        if(enemies[i] == killed) {
            delete killed;
            enemies.erase(enemies.begin() + i);
            break;
        }
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
        this->foodCoordinates.push_back({x, y});
    }
}

void Field::ResourceSpawn() {
    this->foodSpawn(DAILY_FOOD_SPAWN);
    this->materialsSpawn(DAILY_MATERIALS_SPAWN);
}
