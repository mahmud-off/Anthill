//#pragma once
#include "Ant.h"
#ifndef SOLDIER_H
#define SOLDIER_H

class Soldier : public Ant {
public:
    Soldier();

    void helpToFightOpponent(int x, int y);

    //virtual ~Soldier();
    virtual void work(Field field) override { ; }

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
