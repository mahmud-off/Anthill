#include <iostream>


using namespace std;

#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    Enemy(int x, int y);
    ~Enemy();
private:
    //parameters
    int hp; // health
    int hit; // damage
    int weight;
    int posX;
    int posY;
};


#endif //ENEMY_H
