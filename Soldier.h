//#pragma once
#ifndef SOLDIER_H
#define SOLDIER_H

#include "Ant.h"
#include "Enemy.h"

class Soldier : public Ant {
public:
    Soldier();
    Soldier(int power);

    void helpToFightEnemy(int x, int y, Field field);
    void fightEnemy(Enemy enemy);

    //virtual ~Soldier();
    virtual void work(Field field) override { ; }
    Soldier(vector<Ant*>& list, Ant* &collecter);

    virtual ~Soldier();

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

#endif SOLDIER_H
