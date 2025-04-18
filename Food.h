#ifndef FOOD_H
#define FOOD_H

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>


class Game;

using namespace std;
#include <random>

class Food{
public:
	Food(int x, int y, int w, Game *game);

	sf::RectangleShape& getFoodShape();
	void initFood(int x,int y,int weight, Game *game);
	int getWeight() { return weight; };
	
	int getX();
	int getY();

	//for test
	int getXCoord(){return x;}
	int getYCoord(){return y;}


private:
	sf::RectangleShape foodShape;
	int weight;
	int x;
	int y;

};

#endif