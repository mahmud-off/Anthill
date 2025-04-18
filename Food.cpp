#include "Food.h"
#include "Game.h"


Food::Food(int x, int y, int w, Game* game) {
    this->x = x;
    this->y = y;
    this->weight = w;
    initFood(x, y, w, game);
}

sf::RectangleShape &Food::getFoodShape() {
    return this->foodShape;
}

void Food::initFood(int x, int y, int weight, Game *game) {
    this->getFoodShape().setPosition((float) x, (float) y);
    this->getFoodShape().setSize(sf::Vector2f(10.f, 10.f));
    this->getFoodShape().setTexture(&game->textureForFood);
    this->getFoodShape().setScale(5.f, 5.f);
}

int Food::getX() {
    return (int) this->foodShape.getPosition().x;
}

int Food::getY() {
    return (int) this->foodShape.getPosition().y;
}
