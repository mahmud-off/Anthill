#include "Materials.h"





sf::CircleShape& Materials::getMaterialsShape()
{
    return this->materialsShape;
}

void Materials::initMaterials(int x, int y, int weight)
{
    this->getMaterialsShape().setPosition((float)x, (float)y);
    this->getMaterialsShape().setRadius(5.f);
    this->getMaterialsShape().setFillColor(sf::Color::Green);
}

int Materials::getX()
{
    return (int)this->materialsShape.getPosition().x;
}

int Materials::getY()
{
    return (int)this->materialsShape.getPosition().y;
}



