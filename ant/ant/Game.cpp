#include "Game.h"

Game::Game() {
	this->initvar();
	this->initWindow();
	this->initEnemies();

}

const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape) {
				this->window->close();
			}
			break;
		}
	}
}

void Game::initvar()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 800;
	this->videoMode.width = 600;
	
	this->window = new sf::RenderWindow(this->videoMode, "Anthill", sf::Style::Default);
	this->window->setFramerateLimit(144);
}

void Game::initEnemies()
{
	//this->enemy.setPosition(100.f,100.f);
	this->enemy.setSize(sf::Vector2f(100.f,100.f));
	this->enemy.setScale(sf::Vector2f(0.5f,0.5f));
	this->enemy.setFillColor(sf::Color::Cyan);
	//this -> enemy.setOutlineColor(sf::Color::Green);
	//this->enemy.setOutlineThickness(1.f);

}

void Game::update()
{
	this->pollEvents();
}
void Game::render()
{
	this->window->clear();
	this->window->draw(this->enemy);
	this->window->display(); 
}

Game::~Game() {
	delete this->window;
}