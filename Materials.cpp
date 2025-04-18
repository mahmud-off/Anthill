#include "Materials.h"
#include "Game.h"


Materials::Materials(int x, int y, int w, Game* game) {
    this->x = x;
    this->y = y;
    this->weight = w;
    initMaterials(x, y, w, game);
}

sf::RectangleShape &Materials::getMaterialsShape() {
    return this->materialsShape;
}

void Materials::initMaterials(int x, int y, int weight, Game *game) {
    this->getMaterialsShape().setPosition((float) x, (float) y);
    this->getMaterialsShape().setSize(sf::Vector2f(10.f, 10.f));
    this->getMaterialsShape().setTexture(&game->textureForMaterial);
    this->getMaterialsShape().setScale(5.f, 5.f);
}

int Materials::getX() {
    return x;
}

int Materials::getY() {
    return y;
}
