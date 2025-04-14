#include "Game.h"

Game::Game():anthill(0,0,0)  {
	this->initvar();
	this->initWindow();
	this->initAnt();

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

	
	this->antSpawnTimerMax = 100.f;
	this->antSpawnTimer = this->antSpawnTimerMax;
	this->maxAnts = 5;

	this->widthRoom = 10;
	this->heightRoom = 50;
}

void Game::initWindow()
{
	this->videoMode.height = 800;
	this->videoMode.width = 600;
	
	this->window = new sf::RenderWindow(this->videoMode, "Anthill", sf::Style::Default);
	this->window->setFramerateLimit(60);
}

void Game::initAnt()
{
	//this->enemy.setPosition(100.f,100.f);
	this->ant.setSize(sf::Vector2f(100.f,100.f));
	this->ant.setScale(sf::Vector2f(0.5f,0.5f));
	this->ant.setFillColor(sf::Color::Cyan);
	//this -> enemy.setOutlineColor(sf::Color::Green);
	//this->enemy.setOutlineThickness(1.f);

}

void Game::spawnAnts()
{
	this->ant.setPosition(
		(float)(rand() % (int)(this->window->getSize().x - this->ant.getSize().x)),
		(float)(rand() % (int)(this->window->getSize().y - this->ant.getSize().y)));
	this->ant.setFillColor(sf::Color::Green);
	this->ants.push_back(ant);
}


void Game::createWorld()
{
	this->anthill.generateAnts(this->window->getSize().x/2,this->window->getSize().y/2);
	for (int i = 0;i< this->anthill.getCollecterList().size();i++) {
		this->anthill.getCollecterList()[i]->setPosX(rand() % this -> widthRoom + (this->window->getSize().x / 2));
		this->anthill.getCollecterList()[i]->setPosY(rand() % this -> heightRoom + (this->window->getSize().y / 2));
	}
}


void Game::update()
{
	this->pollEvents();
	this->upadateAnts();
}

void Game::upadateAnts()
{
	if (this->ants.size() < this->maxAnts) {
		if (this->antSpawnTimer >= this->antSpawnTimerMax) {
			this->spawnAnts();
			this->antSpawnTimer = 0.f;
		}
		else {
			this->antSpawnTimer += 1.f;
		}
	}
}


void Game::render()
{
	this->window->clear();
	this->renderAnts();
	this->window->display(); 
}

void Game::renderAnts()
{
	for (auto& e : this->ants) {
		 
		this->window->draw(e);
	}
}

Game::~Game() {
	delete this->window;
}