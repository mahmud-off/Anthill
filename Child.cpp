#include "Child.h"
#include "Game.h"

Child::Child(Game *game)
{
	cout << "child created\n";
	this->setRole("child");
	this->initChild(game);
}

void Child::initChild(Game *game){
	this->getShape().setSize(sf::Vector2f(10.f, 10.f));
	this->getShape().setTexture(&game->textureForChildren);
	this->getShape().setScale(5.f, 5.f);
}
