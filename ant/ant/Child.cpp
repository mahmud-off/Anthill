#include "Child.h"

Child::Child()
{
	cout << "child created\n";
	this->setRole("child");
	this->initChild();
}

void Child::initChild(){
	this->chi.setSize(sf::Vector2f(10.f, 10.f));
	this->chi.setFillColor(sf::Color::Red);
}
