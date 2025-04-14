#ifndef GAME_H
#define GAME_H


#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>

#include<vector>
#include<ctime>


class Game{
private:
	//Инициализируем все, связанное с окном
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	
	sf::RectangleShape ant;
	std::vector <sf::RectangleShape> ants;


	//Таймер для спавна муравьев
	float antSpawnTimer;
	float antSpawnTimerMax;
	int maxAnts;


	void initvar();
	void initWindow();
	void initAnt();
public:
	Game();
	
	const bool getWindowIsOpen() const;
	void pollEvents();

	void spawnAnts();

	void update();
	void upadateAnts();

	void render();
	void renderAnts();



	~Game();

};
#endif
