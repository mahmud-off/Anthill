#include "Food.h"




sf::CircleShape& Food::getFoodShape()
{
    return this->foodShape;
}

void Food::initFood(int x, int y)
{
    this->getFoodShape().setPosition((float)x, (float)y);
    this->getFoodShape().setRadius(5.f);
    this->getFoodShape().setFillColor(sf::Color::Blue);
}



