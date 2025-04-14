#ifndef COLLECTER_H
#define COLLECTER_H

#include "Ant.h"
// #include "Child.h"
// #include "Field.h"

class Child;
class Field;

class Collecter : public Ant {
public:
    Collecter();
    Collecter(int weight);
    void collectFood(Field *field);
    void helpToCollectFood(int x, int y, Field *field); // coordinates
    // void setStatus(string status) { this->status = status; }
    void changeStatus();

    int getWeight() { return this->getWeight(); }

    Collecter(vector<Child*>& list, Child* &child);

    virtual ~Collecter();
    virtual void work(Field *field) override { collectFood(field); }
    //
    // using Ant::moveRight;
    // using Ant::moveLeft;
    // using Ant::moveUp;
    // using Ant::moveDown;
    // using Ant::setPosX;
    // using Ant::setPosY;
    // using Ant::findNearestPoint;
    // using Ant::A_StarSearch;
    // using Ant::getPosX;
    // using Ant::getPosY;
    // using Ant::getStatus;

private:
};

#endif // COLLECTER_H