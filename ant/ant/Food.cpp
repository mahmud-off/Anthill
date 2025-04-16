#include "Food.h"




sf::CircleShape& Food::getFoodShape()
{
    return this->foodShape;
}

void Food::initFood(int x, int y,int weight)
{
    this->getFoodShape().setPosition((float)x, (float)y);
    this->getFoodShape().setRadius(5.f);
    this->getFoodShape().setFillColor(sf::Color::Blue);
}

int Food::getX()
{
    return (int)this->foodShape.getPosition().x;
}

int Food::getY()
{
    return (int)this->foodShape.getPosition().y;
}



