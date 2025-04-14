#include "Field.h"
#include <ctime>
#include <cstdlib>
#include <vector>

#define DAILY_FOOD_SPAWN 100
#define DAILY_MATERIALS_SPAWN 50
#define MAX_WEIGHT_FOOD 10
#define MAX_WEIGHT_MATERIALS 50
#define MATERIALS "materials"
#define FOOD "food"

Field::Field(int width, int height) {
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
        while (field[x][y] != "") {
            // если ячейка поля уже занята, то пересчитываем заново
            x = rand() % this->width;
            y = rand() % this->height;
        }
        this->field[x][y] = MATERIALS;
        int weight = rand() % MAX_WEIGHT_MATERIALS;
        this->materialsCoordinates.push_back({weight, {x, y}});
    }
}

void Field::createEnemy() {
    //first - compute Enemy's point
    srand(time(0));
    int x = rand() % this->width;
    int y = rand() % this->height;
    while (field[x][y] != "") {
        // point is free +
        x = rand() % this->width;
        y = rand() % this->height;
    }
    //create Enemy
    Enemy *newEnemy = new Enemy(x, y);
    enemies.push_back(newEnemy);
    cout << "Enemy's position --> " << x << " " << y << "\n";
}

void Field::deleteEnemy(Enemy *killed) { // O(Enemies count)
    for (int i = 0; i < enemies.size(); ++i) {
        if (enemies[i] == killed) {
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
        while (field[x][y] != "") {
            // если ячейка поля уже занята, то пересчитываем заново
            x = rand() % this->width;
            y = rand() % this->height;
        }
        this->field[x][y] = FOOD;
        int weight = rand() % MAX_WEIGHT_FOOD;
        this->foodCoordinates.push_back({weight, {x, y}});
    }
}

void Field::ResourceSpawn() {
    this->foodSpawn(DAILY_FOOD_SPAWN);
    this->materialsSpawn(DAILY_MATERIALS_SPAWN);
}

void Field::updateFoodCoordinatesList() {
    // для того чтобы не рассматривать лишние координаты с едой в следующий раз
    vector<pair<int, pair<int, int> > > newFoodCoordinates;
    for (int i = 0; i < newFoodCoordinates.size(); i++) {
        int x = foodCoordinates[i].second.first;
        int y = foodCoordinates[i].second.second;
        if (field[x][y] == FOOD) {
            newFoodCoordinates.push_back({foodCoordinates[i].first, foodCoordinates[i].second});
        }
    }
    foodCoordinates = newFoodCoordinates;
}

void Field::updateMaterialsCoordinatesList() {
    vector<pair<int, pair<int, int> > > newMaterialsCoordinates;
    for (int i = 0; i < newMaterialsCoordinates.size(); i++) {
        int x = materialsCoordinates[i].second.first;
        int y = materialsCoordinates[i].second.second;
        if (field[x][y] == MATERIALS) {
            newMaterialsCoordinates.push_back({foodCoordinates[i].first, foodCoordinates[i].second});
        }
    }
    foodCoordinates = newMaterialsCoordinates;
}