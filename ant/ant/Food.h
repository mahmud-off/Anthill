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
	sf::CircleShape& getFoodShape();
	void initFood(int x,int y);
private:
	sf::CircleShape foodShape;

};

#endif