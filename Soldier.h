#ifndef SOLDIER_H
#define SOLDIER_H

#include "Ant.h"
#include "Collecter.h"


class Soldier : public Ant {
public:
    Soldier();

    Soldier(vector<Collecter*>& list, Collecter* &collecter);

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
