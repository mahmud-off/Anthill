#include "Anthill.h"

Anthill::Anthill(){}

Anthill::~Anthill(){}


void Anthill::createAnt(const sf::Vector2f& position){
	collectors.emplace_back(new Collector(position));

	cout << "Ant has created;" << endl;

}

