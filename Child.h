#ifndef CHILD_H
#define CHILD_H

#include "Ant.h"

class Game;


using namespace std;

class Child : public Ant {
public:
    Child(Game *game);

    void initChild(Game *game);

    virtual ~Child() override { /*cout << "child was deleted";*/ };
    void work(Field *field, Anthill *anthill, Game *game) override { ; }

private:
};

#endif 
