#ifndef DEAD_H
#define DEAD_H
#include "Ant.h"

class Child;
class Collecter;
class Cleaner;
class Builder;
class Soldier;
class Nurse;

class Dead: public Ant {
public:
    Dead(vector<Child*>& list, Child* &child);
    Dead(vector<Collecter*>& list, Collecter* &collector);
    Dead(vector<Cleaner*>& lsist, Cleaner* &cleaner);
    Dead(vector<Builder*>& list, Builder* &builder);
    Dead(vector<Soldier*>& list, Soldier* &soldier);
    Dead(vector<Nurse*>& list, Nurse* &nurse);
    Dead(int x, int y, int weight) { this->x = x;this->y = y;this->weight = weight; }
    int getX() {return this->getPosX();};
    int getY() { return this->getPosY(); };
    void initDead( );
    void work(Field *field, Anthill *anthill) override {
        ;//stay_on_your_Point(x,y);
    }

private:
    int x;
    int y;
    int weight;
};

#endif //DEAD_H
