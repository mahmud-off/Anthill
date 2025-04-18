#ifndef MATERIALS_H
#define MATERIALS_H

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>

class Game;


using namespace std;
#include <random>

class Materials {
public:
	Materials(int x, int y, int w, Game *game);
	sf::RectangleShape& getMaterialsShape();
	void initMaterials(int x, int y, int weight, Game *game = nullptr);
	int getWeight() { return this->weight; };

	int getX();
	int getY();

private:
	int x;
	int y;
	sf::RectangleShape materialsShape;
	int weight;

};

#endif