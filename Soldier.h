//#pragma once
#include "Ant.h"
#ifndef SOLDIER_H
#define SOLDIER_H

class Soldier : public Ant {
public:
    Soldier();
    Soldier(int power);

    void helpToFightOpponent(int x, int y, Field field);
    void fightOpponent();

    //virtual ~Soldier();
    virtual void work(Field field) override { ; }
    Soldier(vector<Ant*>& list, Ant* &collecter);

    virtual ~Soldier();
    virtual void work() override { ; }

    using Ant::moveRight;
    using Ant::moveLeft;
    using Ant::moveUp;
    using Ant::moveDown;
    using Ant::setPosX;
    using Ant::setPosY;

private:
    int hit; // ����
};

#endif SOLDIER_H
