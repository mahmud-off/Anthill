#include "Field.h"
#include <ctime>
#include <cstdlib>
#include <vector>

#include "AntHill.h"
#include "Materials.h"
#include "Game.h"

#define ENEMIES_SPAWN 50
#define DAILY_FOOD_SPAWN 100
#define DAILY_MATERIALS_SPAWN 100
#define MAX_WEIGHT_FOOD 10
#define MAX_WEIGHT_MATERIALS 50
#define MATERIALS "materials"
#define FOOD "food"
#define ENEMY_HIT 5

Field::Field(int width, int height) {
    this->height = height;
    this->width = width;

}

int getRandomNumber(int min_n, int max_n) {
    static mt19937 generator(random_device{}());
    uniform_int_distribution<int> distribution(min_n, max_n);

    return distribution(generator);
};

int canSpawnHere(Anthill *anthill, int x, int y) {
    if ((x > anthill->getPosX() - 350 && x < (x + anthill->getWidth())) && (y > anthill->getPosY() && y < (y + anthill->getHeight()))) { // pos(x, y) in anthill
        return 0;
    }
    return 1; // pos(x, y) not in anthill
}

void Field::materialsSpawn(int k, Anthill *anthill, Game *game) {
    srand(time(0));
    for (int i = 0; i < k; i++) {
        int x = getRandomNumber(0, this->width-3);
        int y = getRandomNumber(0, this->height-3);
        while (1) {
            if (canSpawnHere(anthill, x, y) == 0) {
                x = getRandomNumber(0, this->width-3);
                y = getRandomNumber(0, this->height-3);
            }
            if (canSpawnHere(anthill, x, y) == 1) {
                this->field[y][x] = MATERIALS;
                break;
            }
        }
        int weight = rand() % MAX_WEIGHT_MATERIALS;
        this->materialsCoordinates.push_back(new Materials(x, y, weight, game));
        this->materialsCoordinates.back()->initMaterials(x, y, weight, game);

    }
}

void Field::createEnemy(int k, Anthill *anthill, Game *game) {
    //first - compute Enemy's point
    for (int i = 0; i < k; i++) {
        int x = getRandomNumber(0, this->width-3);
        int y = getRandomNumber(0, this->height-3);
        while (1) {
            if (canSpawnHere(anthill, x, y) == 0) {
                x = getRandomNumber(0, this->width-3);
                y = getRandomNumber(0, this->height-3);
            }
            if (canSpawnHere(anthill, x, y) == 1) {
                this->field[y][x] = MATERIALS;
                break;
            }
        }
        //create Enemy
        Enemy *newEnemy = new Enemy(x, y, ENEMY_HIT, game);
        enemies.push_back(newEnemy);
    }
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

void Field::foodSpawn(int k, Anthill *anthill, Game *game) {
    // cout <<"HUI"<< field.size() << " ";
    // cout << field[1].size() << endl;
    // cout << this->width << " ";
    // cout << this->height;
    for (int i = 0; i < k; i++) {
        int x = getRandomNumber(0, this->width-3);
        int y = getRandomNumber(0, this->height-3);
        cout << x << " " << y << "\n";
        while (1) {
            if (canSpawnHere(anthill, x, y) == 0) {
                x = getRandomNumber(0, this->width-3);
                y = getRandomNumber(0, this->height-3);
            }
            if (canSpawnHere(anthill, x, y) == 1) {
                this->field[y][x] = MATERIALS;
                break;
            }
        }
        this->field[y][x] = FOOD;
        int weight = rand() % MAX_WEIGHT_FOOD;
        this->foodCoordinates.push_back(new Food(x, y, weight, game));
        this->foodCoordinates.back()->initFood(x, y, weight, game);

    }
}

void Field::ResourceSpawn(Anthill *anthill, Game *game) {
    this->foodSpawn(DAILY_FOOD_SPAWN, anthill, game);
    this->materialsSpawn(DAILY_MATERIALS_SPAWN, anthill, game);
}

void Field::enemiesSpawn(Anthill *anthill, Game *game) {
    this->createEnemy(ENEMIES_SPAWN, anthill, game);
}

void Field::spawnFoodWhenNeeds(Anthill* anthill, Game *game)
{
        int x = getRandomNumber(0, this->width-3);
        int y = getRandomNumber(0, this->height-3);
        while (canSpawnHere(anthill, x, y) == 0) {
            x = getRandomNumber(0, this->width-3);
            y = getRandomNumber(0, this->height-3);
        }
        this->field[y][x] = FOOD;
        int weight = rand() % MAX_WEIGHT_FOOD;
        Food* pop = new Food(x, y, weight, game);
    //cout << this->foodCoordinates.size() << " ";
    this->foodCoordinates.push_back(pop);
      //  cout << this->foodCoordinates.size() << "\n";
        //this->foodCoordinates.back()->initFood(x, y, weight);


}

void Field::spawnMaterialsWhenNeeds(Anthill *anthill, Game *game)
{
    int x = getRandomNumber(0, this->width-3);
    int y = getRandomNumber(0, this->height-3);
    while (canSpawnHere(anthill, x, y) == 0) {
        x = getRandomNumber(0, this->width-3);
        y = getRandomNumber(0, this->height-3);
    }
    this->field[y][x] = MATERIALS;
    int weight = rand() % MAX_WEIGHT_MATERIALS;
    this->materialsCoordinates.push_back(new Materials(x, y, weight, game));
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
    vector<Food*> newFoodCoordinates;
    for (int i = 0; i < foodCoordinates.size(); i++) {
        int x = foodCoordinates[i]->getX();
        int y = foodCoordinates[i]->getY();
        if (field[y][x] == FOOD) {
            newFoodCoordinates.push_back(foodCoordinates[i]);
        }
    }
    foodCoordinates = newFoodCoordinates;

    /*cout << detectedFood.size()<<"\n";

    for(int i = 0; i < detectedFood.size(); ++i) {
        cout << detectedFood[i]->getX() << " " << detectedFood[i]->getY() << " / ";
    }
    cout << "\n";
*/
    //vector<Food*> newFoodCoordinates(detectedFood);
    for (int i = 0; i < detectedFood.size(); ++i) {
        int x = detectedFood[i]->getXCoord();
        int y = detectedFood[i]->getYCoord();
        //cout << "key-->" << field[y][x] << " ";
        if (field[y][x] != FOOD) {
            detectedFood.erase(detectedFood.begin()+i);
            break;
        }
    }
    //cout << "\n";

    /*
    cout << foodCoordinates.size()<<"\n";
    for(int i = 0; i < foodCoordinates.size(); ++i) {
        cout << foodCoordinates[i]->getX() << " " << foodCoordinates[i]->getY() << " / ";
    }
    cout << "\n";
*/
}

void Field::updateMaterialsCoordinatesList() {
    for (int i = 0; i < detectedMaterials.size(); ++i) {
        int x = detectedMaterials[i]->getX();
        int y = detectedMaterials[i]->getY();
        if (field[y][x] != MATERIALS) {
            detectedMaterials.erase(detectedMaterials.begin() + i);
            break;
        }
    }

}
