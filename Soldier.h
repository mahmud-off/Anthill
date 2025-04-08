//#pragma once
#include "Ant.h"
#ifndef SOLDIER_H
#define SOLDIER_H

class Soldier : Ant {
public:
    Soldier();

    //virtual ~Soldier();
    virtual void work() override { ; }

    using Ant::moveRight;
    using Ant::moveLeft;
    using Ant::moveUp;
    using Ant::moveDown;

private:
    int hit; // ����
};

#endif SOLDIER_H
