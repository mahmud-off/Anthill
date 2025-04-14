#ifndef CHILD_H
#define CHILD_H

#include "Ant.h"

using namespace std;

class Child : public Ant {
public:

    Child();

    virtual ~Child();
    virtual void work(Field field) override { ; }
    string getRole() { return Ant::getRole(); }

    using Ant::moveRight;
    using Ant::moveLeft;
    using Ant::moveUp;
    using Ant::moveDown;
    using Ant::setPosX;
    using Ant::setPosY;

private:
};

#endif CHILD_H
