#include "Field.h"
#include <ctime>
#include <cstdlib>
#include <vector>

#define DAILY_FOOD_SPAWN 100
#define DAILY_MATERIALS_SPAWN 50
#define MAX_WEIGHT_FOOD 10

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
        int weight = rand() % MAX_WEIGHT_FOOD;
        this->foodCoordinates.push_back({weight, {x, y}});
    }
}

void Field::ResourceSpawn() {
    this->foodSpawn(DAILY_FOOD_SPAWN);
    this->materialsSpawn(DAILY_MATERIALS_SPAWN);
}

void Field::updateFoodCoordinatesList() { // для того чтобы не рассматривать лишние координаты с едой в следующий раз
    vector<pair<int, pair<int, int>>> newFoodCoordinates;
    for (int i = 0; i < newFoodCoordinates.size(); i++) {
        int x = foodCoordinates[i].second.first;
        int y = foodCoordinates[i].second.second;
        if (field[x][y] == "food") {
            newFoodCoordinates.push_back({foodCoordinates[i].first, foodCoordinates[i].second});
        }
    }
    foodCoordinates = newFoodCoordinates;
}

