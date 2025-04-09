#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <string>
#include "Enemy.h"

using namespace std;

class Field {
public:

    Field(int height, int width);
    void ResourceSpawn();
    vector<pair<int, int>> foodCoordinates; // coordinates of cells with food
    vector<pair<int, int>> materialsCoordinates; // coordinates of cells with materials

    //Enemies
    void createEnemy();
    void deleteEnemy(Enemy* killed);
    //for testing
    vector<Enemy*> enemies;

private:
    // resource spawn
    void foodSpawn(int k);
    void materialsSpawn(int k);

    vector<vector<string>> field;
    int height;
    int width;

    //enemies
    //vector<Enemy*> enemies;

};

#endif //FIELD_H
