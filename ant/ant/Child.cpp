#include "Child.h"

Child::Child()
{
	cout << "child created\n";
	this->setRole("child");
	this->initChild();
}

void Child::initChild(){
	this->getShape().setSize(sf::Vector2f(10.f, 10.f));
	this->getShape().setFillColor(sf::Color::Red);
}
