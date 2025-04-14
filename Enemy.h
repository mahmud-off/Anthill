#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

class Anthill;

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


    bool findAnts(Anthill antHill);

private:
    //parameters
    int health; // health
    int hit; // damage
    int weight;
    int posX;
    int posY;

    int roView = 100;

    double distance(int x1, int y1, int x2, int y2);

};


#endif //ENEMY_H