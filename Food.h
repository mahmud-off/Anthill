#ifndef FOOD_H
#define FOOD_H

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>


using namespace std;
#include <random>

class Food{
public:
	Food(int x, int y, int w);

	sf::CircleShape& getFoodShape();
	void initFood(int x,int y,int weight = 0);
	int getWeight() { return this->weight; };
	
	int getX();
	int getY();

private:
	sf::CircleShape foodShape;
	int weight;
	int x;
	int y;

};

#endif