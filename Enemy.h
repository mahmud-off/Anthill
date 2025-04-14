#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

// #include "AntHill.h"


using namespace std;


class Enemy {
public:
    Enemy(int x, int y);
    ~Enemy();

    // getters
    int getPower() { return this->hit; }
    int getHealth() { return this->health; }

    // setters
    int setHealth(int health) { this->health = health; }

private:
    //parameters
    int health; // health
    int hit; // damage
    int weight;
    int posX;
    int posY;
};


#endif //ENEMY_H