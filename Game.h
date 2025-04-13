#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Ant.h"

using namespace std;

class Game{
public:
	Game();
	~Game();

	const bool running() const;

	void pollEvents();
	void update();
	void render();

private:
	sf::RenderWindow* window;
	sf::VideoMode videomode;
	Ant ant;

	void initVariables();
	void initWindow();
};

