#ifndef COLLECTER_H
#define COLLECTER_H

#include "Ant.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
// #include "Child.h"
// #include "Field.h"

class Child;
class Field;
class Anthill;
class Game;

class Collecter : public Ant {
public:
    Collecter(Game *game);
    Collecter(int weight, Game *game);
    void collectFood(Field *field, Anthill *anthill);
    void helpToCollectFood(int x, int y, Field *field); // coordinates
    // void setStatus(string status) { this->status = status; }

    void initCollecter(Game *game);

    int getWeight() { return Ant::getWeight(); }

    Collecter(vector<Child*>& list, Child* &child, Game *game);

    virtual ~Collecter();
    
    void work(Field* field, Anthill* anthill, Game* game) override;
    void changeStatus();
    void growthFood(Anthill* anthill);
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
