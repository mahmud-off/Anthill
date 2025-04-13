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
Game::Game(): ant(sf::Vector2f(20.f, 20.f)) {
	this->initVariables();
	this->initWindow();
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

	ant.updateMovement();
}

void Game::render(){
	window->clear(sf::Color(93,161,48,54)); // зелёный фон 

	ant.draw(*window);

	window->display();
}

void Game::pollEvents() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window->close();
	}
}