#pragma once

#include "Collector.h"

using namespace std;

class Anthill{

public:
	Anthill();
	~Anthill();

	vector<Collector*>& getCollectorList() {return collectors;}

	void createAnt(const sf::Vector2f& position);

private:
	vector<Collector*> collectors; // Вектор для хранения муравьев
};
