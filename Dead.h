#ifndef DEAD_H
#define DEAD_H
#include "Ant.h"

class Child;
class Collecter;
class Cleaner;
class Builder;
class Soldier;
class Nurse;
class Game;

class Dead: public Ant {
public:
    Dead(vector<Child*>& list, Child* &child, Game *game);
    Dead(vector<Collecter*>& list, Collecter* &collector, Game *game);
    Dead(vector<Cleaner*>& lsist, Cleaner* &cleaner, Game *game);
    Dead(vector<Builder*>& list, Builder* &builder, Game *game);
    Dead(vector<Soldier*>& list, Soldier* &soldier, Game *game);
    Dead(vector<Nurse*>& list, Nurse* &nurse, Game *game);
    Dead(int x, int y, int weight, Game *game) { this->x = x;this->y = y;this->weight = weight; }
    int getX() {return this->getPosX();};
    int getY() { return this->getPosY(); };
    void initDead(Game *game);
    void work(Field *field, Anthill *anthill, Game *game) override {
        ;//stay_on_your_Point(x,y);
    }

private:
    int x;
    int y;
    int weight;
};

#endif //DEAD_H
