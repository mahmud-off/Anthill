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
#include "Dead.h"
#include "Food.h"
#include "Materials.h"
#include "Storage.h"
#include "Game.h"

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

	void initTexture();
	void initSprite();

	void initTextureForChild();
	void initSpriteForChild();

	void initTextureForSoldier();
	void initSpriteForSoldier();

	void initTextureForEnemy();
	void initSpriteForEnemy();

	void initTextureForBuilder();
	void initSpriteForBuilder();

	void initTextureForCollecter();
	void initSpriteForCollecter();

	void initTextureForMaterial();
	void initSpriteForMaterial();

	void initTextureForFood();
	void initSpriteForFood();

	void initTextureForNurse();
	void initSpriteForNurse();

	void initTextureForCleaner();
	void initSpriteForCleaner();

	//???????? ?????????????
	void initVar();
	void initWindow();

	// tics
	int tics = 0;
public:
	Game();
	sf::Sprite sprite;
	sf::Texture fon;

	sf::Sprite spriteForChildren;
	sf::Texture textureForChildren;

	sf::Sprite spriteForSoldiers;
	sf::Texture textureForSoldiers;

	sf::Sprite spriteForEnemy;
	sf::Texture textureForEnemy;

	sf::Sprite spriteForBuilder;
	sf::Texture textureForBuilder;

	sf::Sprite spriteForCollecter;
	sf::Texture textureForCollecter;

	sf::Sprite spriteForMaterial;
	sf::Texture textureForMaterial;

	sf::Sprite spriteForFood;
	sf::Texture textureForFood;

	sf::Sprite spriteForNurse;
	sf::Texture textureForNurse;

	sf::Sprite spriteForCleaner;
	sf::Texture textureForCleaner;

	void createWorld();

	const bool getWindowIsOpen() const;
	void pollEvents();


	void update();

	void renderSprite(sf::Sprite sprite);

	void render();

	void renderCollecter();
	void renderSoldier();
	void renderChild();
	void renderDead();
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