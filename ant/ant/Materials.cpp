#include "Materials.h"




Materials::Materials(int x, int y, int w) {
    this->x = x;
    this->y = y;
    this->weight = w;
    initMaterials(x, y, w);
}
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
    return x;
}

int Materials::getY()
{
    return y;
}



