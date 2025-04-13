#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Anthill.h"

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
	Anthill anthill;

	void initVariables();
	void initWindow();
};

