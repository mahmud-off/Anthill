//#pragma once
#include "Ant.h"
#ifndef SOLDIER_H
#define SOLDIER_H

class Soldier : Ant {
public:
    int constEating = 5;
    Soldier();

    //virtual ~Soldier();
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
