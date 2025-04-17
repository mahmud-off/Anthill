#ifndef MATERIALS_H
#define MATERIALS_H

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>


using namespace std;
#include <random>

class Materials {
public:
	Materials(int x, int y, int w);
	sf::CircleShape& getMaterialsShape();
	void initMaterials(int x, int y, int weight = 0);
	int getWeight() { return this->weight; };

	int getX();
	int getY();

private:
	int x;
	int y;
	sf::CircleShape materialsShape;
	int weight;

};

#endif