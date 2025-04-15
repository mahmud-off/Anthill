#ifndef GAME_H
#define GAME_H


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include <vector>
#include <ctime>
#include <iostream>
#include <random>


#include "Anthill.h"
#include "Informer.h"
#include "Field.h"

using namespace std;

class Game{

private:
	//экземпл€ры классов, св€занные с окнами
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	
	//экземпл€ры классов, св€занные с общей экосистемой муравейника
	Anthill anthill;
	Informer informer;
	Field field;

	//родильна€ комната
	int bornRoomWidth;
	int bornRoomHeight;
	int bornRoomX;
	int BornRoomY;

	//муравейник
	int antHillWidth;
	int antHillHeight;
	int antHillX;
	int antHillY;

	//функкции инициализации
	void initVar();
	void initWindow();
public:
	Game();
	
	void createWorld();

	const bool getWindowIsOpen() const;
	void pollEvents();


	void update();

	void render();
	void renderCollecter();
	void renderCleaner();
	void renderSoldier();

	void renderChild();

	void renderNurse();

	void renderBuilder();

	

	~Game();

};
#endif
