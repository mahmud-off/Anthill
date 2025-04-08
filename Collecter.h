//#pragma once
#include "Ant.h"
#include "Field.h"
#ifndef COLLECTER_H
#define COLLECTER_H

class Collecter : Ant {
public:
    int constEating = 3;

    void collectFood(Field field);
    void helpToCollectFood(int x, int y); // coordinates

    Collecter();

    //virtual ~Collecter();
    virtual void work() override { ; }

    using Ant::moveRight;
    using Ant::moveLeft;
    using Ant::moveUp;
    using Ant::moveDown;
    using Ant::setPosX;
    using Ant::setPosY;
    using Ant::findNearestPoint;
    using Ant::A_StarSearch;
    using Ant::getPosX;
    using Ant::getPosY;

private:
};

#endif COLLECTER_H
