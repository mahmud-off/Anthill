#ifndef SOLDIER_H
#define SOLDIER_H

#include "Ant.h"
#include "Enemy.h"
#include "Collecter.h"

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>

class Soldier : public Ant {
public:
    sf::RectangleShape sol;

    Soldier();
    Soldier(int power);

    Soldier(vector<Collecter*>& list, Collecter* &collecter);
    void helpToFightEnemy(int x, int y, Field field);
    void initSoldier();
    void fightEnemy(Enemy enemy, Field field);

    virtual ~Soldier();
    virtual void work(Field field) override { ; }
    Soldier(vector<Ant*>& list, Ant* &collecter);

    using Ant::moveRight;
    using Ant::moveLeft;
    using Ant::moveUp;
    using Ant::moveDown;
    using Ant::setPosX;
    using Ant::setPosY;
    using Ant::getPower;

    // getters



private:
    int hit; // ����
};

#endif 
