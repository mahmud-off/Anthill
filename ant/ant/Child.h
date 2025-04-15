#ifndef CHILD_H
#define CHILD_H

#include "Ant.h"


#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>

using namespace std;

class Child : public Ant {
public:

    sf::RectangleShape chi;
    Child();

    void initChild();

    virtual ~Child() override { cout << "child was deleted"; };
    virtual void work(Field field) override { ; }

    // using Ant::moveRight;
    // using Ant::moveLeft;
    // using Ant::moveUp;
    // using Ant::moveDown;
    // using Ant::setPosX;
    // using Ant::setPosY;

private:
};

#endif 
