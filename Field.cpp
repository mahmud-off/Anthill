#include "Field.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Materials.h"
#include "AntHill.h"

#define DAILY_FOOD_SPAWN 50
#define DAILY_MATERIALS_SPAWN 50
#define MAX_WEIGHT_FOOD 10
#define MAX_WEIGHT_MATERIALS 50
#define MATERIALS "materials"
#define FOOD "food"

Field::Field(int width, int height) {
    this->height = height;
    this->width = width;
   
}

int canSpawnHere(Anthill *anthill, int x, int y) {
    if (x > anthill->getPosX() && x < (x + anthill->getWidth())) { // pos(x, y) in anthill
        if (y > anthill->getPosY() && y < (y + anthill->getHeight())) {
            return 0;
        }
    }
    return 1; // pos(x, y) not in anthill
}

void Field::materialsSpawn(int k, Anthill* anthill) {
    for (int i = 0; i < k; i++) {
        srand(time(0));
        int x = rand() % this->width;
        int y = rand() % this->height;
        while (field[y][x] != "" ) {
            // если ячейка поля уже занята, то пересчитываем заново
            x = rand() % this->width;
            y = rand() % this->height;
        }
        this->field[y][x] = MATERIALS;
        int weight = rand() % MAX_WEIGHT_MATERIALS;
        this->materialsCoordinates.push_back(new Materials);
        this->materialsCoordinates.back()->initMaterials(x, y, weight);

    }
}

void Field::createEnemy(Anthill* anthill) {
    //first - compute Enemy's point
    srand(time(0));
    int x = rand() % this->width;
    int y = rand() % this->height;
    while (field[x][y] != "" ) {
        // point is free +
        x = rand() % this->width;
        y = rand() % this->height;
    }
    //create Enemy
    Enemy *newEnemy = new Enemy(x, y);
    enemies.push_back(newEnemy);
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

void Field::foodSpawn(int k, Anthill* anthill) {
    cout <<"HUI"<< field.size() << " ";
    cout << field[1].size() << endl;
    cout << this->width << " ";
    cout << this->height;
    for (int i = 0; i < k; i++) {
        srand(time(0));
        int x = rand() % this->width;
        int y = rand() % this->height;
        cout << x << " " << y << "\n";
        while (field[y][x] != "" ) {
            // если ячейка поля уже занята, то пересчитываем заново
            cout << x << " " << y << "\n";
            x = rand() % this->width;
            y = rand() % this->height;
        }
        this->field[y][x] = FOOD;
        int weight = rand() % MAX_WEIGHT_FOOD;
        this->foodCoordinates.push_back(new Food(x, y, weight));
        this->foodCoordinates.back()->initFood(x, y, weight);

    }
}

void Field::ResourceSpawn(Anthill* anthill) {
    this->foodSpawn(DAILY_FOOD_SPAWN, anthill);
    this->materialsSpawn(DAILY_MATERIALS_SPAWN, anthill);
}

void Field::setHW(int x,int y)
{
    this->width = x;
    this ->height = y;
    this->field.resize(height);
    for (int i = 0; i < height; i++) {
        this->field[i].resize(width);
    }
}

void Field::updateFoodCoordinatesList() {
    // для того чтобы не рассматривать лишние координаты с едой в следующий раз
    /*
    vector<Food*> newFoodCoordinates;
    for (int i = 0; i < foodCoordinates.size(); i++) {
        int x = foodCoordinates[i]->getX();
        int y = foodCoordinates[i]->getY();
        if (field[y][x] == FOOD) {
            newFoodCoordinates.push_back(foodCoordinates[i]);
        }
    }
    foodCoordinates = newFoodCoordinates;
    */

    /*cout << detectedFood.size()<<"\n";

    for(int i = 0; i < detectedFood.size(); ++i) {
        cout << detectedFood[i]->getX() << " " << detectedFood[i]->getY() << " / ";
    }
    cout << "\n";
*/
    vector<Food*> newFoodCoordinates = detectedFood;
    for (int i = 0; i < newFoodCoordinates.size(); i++) {
        int x = newFoodCoordinates[i]->getX();
        int y = newFoodCoordinates[i]->getY();
        if (field[y][x] != FOOD) {
            detectedFood.erase(detectedFood.begin()+i);
        }
    }
    /*
    cout << foodCoordinates.size()<<"\n";
    for(int i = 0; i < foodCoordinates.size(); ++i) {
        cout << foodCoordinates[i]->getX() << " " << foodCoordinates[i]->getY() << " / ";
    }
    cout << "\n";
*/
}

void Field::updateMaterialsCoordinatesList() {
    vector<Materials*> newMaterialsCoordinates;
    for (int i = 0; i < newMaterialsCoordinates.size(); i++) {
        int x = materialsCoordinates[i]->getX();
        int y = materialsCoordinates[i]->getY();
        if (field[y][x] == MATERIALS) {
            newMaterialsCoordinates.push_back(materialsCoordinates[i]);
        }
    }
    materialsCoordinates = newMaterialsCoordinates;
}