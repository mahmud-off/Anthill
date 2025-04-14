#ifndef GAME_H
#define GAME_H


#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>


class Game{
private:

	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	sf::RectangleShape enemy;


	void initvar();
	void initWindow();
	void initEnemies();
public:
	Game();
	
	const bool getWindowIsOpen() const;
	void pollEvents();
	void update();
	void render();
	

	~Game();

};
#endif
