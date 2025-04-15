#include "Game.h"
#include <iostream>

using namespace std;

// Private functions
void Game::initVariables(){
	this->window = nullptr;
}

void Game::initWindow(){
	this->window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Ants!");
}

// Constructor / Destructor
Game::Game() : anthill(1000,0,0){
	this->initVariables();
	this->initWindow();

	for (int i = 0; i < 3; ++i) {
		anthill.generateAnts();
	}
}
Game::~Game() {
	delete this->window;
}

const bool Game::running() const{
	return this->window->isOpen();
}

// Public function
void Game::update(){
	pollEvents();

	for (auto& collector : anthill.getCollecterList()) {
		collector->work();
	}
}

void Game::render(){
	window->clear(sf::Color(93,161,48,54)); // зелёный фон 

	for (auto& collector : anthill.getCollecterList()) {
		this->window->draw();
	}

	window->display();
}

void Game::pollEvents() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window->close();
	}
}