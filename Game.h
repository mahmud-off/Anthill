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
#include "Storage.h"

#include "Ant.h"
#include "Builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collecter.h"
#include "Nurse.h"
#include "Soldier.h"
#include "Food.h"
#include "Materials.h"
#include "Storage.h"
using namespace std;

class Game{

private:
	//?????????? ???????, ????????? ? ??????
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	
	//?????????? ???????, ????????? ? ????? ??????????? ???????????
	Anthill anthill;
	Informer informer;
	Field field;
	Storage storage;

	//????????? ???????
	int bornRoomWidth;
	int bornRoomHeight;
	int bornRoomX;
	int BornRoomY;

	//??????????
	int antHillWidth;
	int antHillHeight;
	int antHillX;
	int antHillY;

	//???????? ?????????????
	//?????
	int storageX;
	int storageY;
	int storageHeight;
	int storageWidth;

	void initTexture(
);

	void initSprite();

	//???????? ?????????????
	void initVar();
	void initWindow();


public:
	Game();
	sf::Sprite sprite;
	sf::Texture fon;

	void createWorld();

	const bool getWindowIsOpen() const;
	void pollEvents();


	void update();

	void renderSprite(sf::Sprite sprite);

	void render();

	void renderCollecter();
	void renderSoldier();
	void renderChild();
	void renderNurse();
	void renderBuilder();
	void renderCleaner();

	void renderEnemy();

	void renderFoodStorage();
	void renderFood();
	void renderMaterials();


	

	~Game();

};
#endif
