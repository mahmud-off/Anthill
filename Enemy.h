#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <SFML/Graphics.hpp>

// #include "AntHill.h"

class Anthill;
class Ant;
class Field;

using namespace std;

class Enemy {
public:
    Enemy(int x, int y, int hit);
    ~Enemy();

    // 1 - atack ants
    void atackAntInField(Anthill *anthill, Field *field);
    bool canFindAntsInField(Anthill *anthill);
    Ant* findNearestAntInField(Anthill *anthill);
    void hitAttackedAnt(Ant *attackedAnt);

    // 2 - steal food from anthill
    void stealFoodFromAnthill(Anthill *anthill);
    bool canFindFoodInAnthill(Anthill *anthill);
    void moveToFoodStorage(Anthill *anthill);

    int roView = 100;
    double distance(int x1, int y1, int x2, int y2);

    // getters
    int getPower() { return this->hit; }
    int getHealth() { return this->health; }
    int getPosX() { return this->posX; }
    int getPosY() { return this->posY; }

    // setters
    void setHealth(int health) { this->health = health; }

   sf::CircleShape& getEnemyShape() { return this->enemyShape; }
    void setHit(int hit) { this->hit = hit; }
    void initEnemy(int x, int y, int hit);

private:
    //parameters
    int health; // health
    int hit; // damage
    int weight;
    int posX;
    int posY;

    sf::CircleShape enemyShape;
};


#endif 
