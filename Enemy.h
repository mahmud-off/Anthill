#include <iostream>

// #include "AntHill.h"


using namespace std;

#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    Enemy(int x, int y);
    ~Enemy();

    // getters
    int getPower() { return this->hit; }
    int getHealth() { return this->health; }

    // setters
    int setHealth(int health) { this->health = health; }


    vector<pair<int, int>> A_StarSearch(pair<int, int> start, pair<int, int> end);


    //functions
    bool findAnts(Anthill antHill);
    pair<int, int> PositionOfNearestAnt(Anthill antHill); // in their range of view

    bool findFood(vector<pair<int,int>> foodCoordinates);
    pair<int, int> PositionOfNearestFood(vector<pair<int, int>> foodCoordinates);

    void moveByCoordinates(pair<int, int> coords);

    void moveToRandomPointInROView(int heightOfField, int widthOfField);

private:
    //parameters
    int health; // health
    int hit; // damage
    int weight;
    int posX;
    int posY;

    int roView = 100; // range of view

    double distance(int x1, int y1, int x2, int y2);



};


#endif //ENEMY_H
