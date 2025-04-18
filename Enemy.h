#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>


// #include "AntHill.h"

class Anthill;
class Ant;
class Field;

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

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
    void stealFoodFromAnthill(Anthill *anthill, Field *field);
    bool canFindFoodInAnthill(Anthill *anthill);
    void moveToFoodStorage(Anthill *anthill);

    int roView = 100;
    double distance(int x1, int y1, int x2, int y2);

    // getters
    int getPower() { return this->hit; }
    int getHealth() { return this->health; }
    int getPosX() { return this->posX; }
    int getPosY() { return this->posY; }
    string getWorkStatus() { return this->work_status; }
    Ant* getAnt() { return ant; }

    // setters
    void setHealth(int health) { this->health = health; }
    void setPosX(int x) { posX = x; }
    void setPosY(int y) { posY = y; }
    void setAnt(Ant* ant) { this->ant = ant; }
    void setWorkStatus(string new_work_status) { work_status = new_work_status; }

    //functions
    void work(Field* field, Anthill* anthill);
    void updateMovement(Field* field, Anthill* anthill, string new_work);
    void randomMoving(Field* filed);

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
    Ant* ant;
    string work_status;
    //sf::RectangleShape shape;

    sf::CircleShape enemyShape;
};


#endif 
