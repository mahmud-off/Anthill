#include "Child.h"

Child::Child()
{
	cout << "child created\n";
	this->setRole("child");
	this->initChild();
}

void Child::initChild(){
	this->get_shape().setSize(sf::Vector2f(10.f, 10.f));
	this->get_shape().setFillColor(sf::Color::Red);
}
