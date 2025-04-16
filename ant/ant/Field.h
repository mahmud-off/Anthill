#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <string>
#include "Enemy.h"
#include "Food.h"

class Materials;

// class Enemy;


#define GRAVE_COORDINATE_X 200
#define GRAVE_COORDINATE_Y 200

using namespace std;

class Field {
public:
    //getters
    int getHeight() { return height; }
    int getWidth() { return width; }

    void setHW(int x,int y);

    void updateFoodCoordinatesList();

    void updateMaterialsCoordinatesList();

    vector<vector<string> > field;

    Field(int width, int height);

    void ResourceSpawn();

    //Enemies
    void createEnemy();

    void deleteEnemy(Enemy *killed);

    // vector<Ant*> deadAnts;


    //getters
    vector<Enemy *> &getEnemiesList() { return enemies; }
    int getHeight() const { return height; }
    int getWidth() const { return width; }
    int getGravePosX() { return this->gravePosX; }
    int getGravePosY() { return this->gravePosY; }


    vector<Food*> foodCoordinates; // coordinates of cells with food : weight and {x, y} - coords
    vector<Materials* > materialsCoordinates; // coordinates of cells with materials
private:

    // grave coordinates
    int gravePosX;
    int gravePosY;

    // resource spawn
    void foodSpawn(int k);

    void materialsSpawn(int k);


    int height;
    int width;

    //enemies
    vector<Enemy *> enemies;
};

#endif 
