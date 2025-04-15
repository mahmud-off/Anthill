#include "Game.h"

Game::Game():anthill(1000,0,0),field(0,0) {
	this->initVar();
	this->initWindow();
	anthill.setxy(this->videoMode.height/2, this->videoMode.width/2);
	field.setHW(this->videoMode.width, this->videoMode.height);
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



void Game::initVar()
{
	this->window = nullptr;


	this->bornRoomHeight = 200;
	this->bornRoomWidth = 200;
	this->bornRoomX = 900;
	this->BornRoomY = 400;

	this->antHillWidth = 800;
	this->antHillHeight = 500;
	this->antHillX = 460;
	this->antHillY = 250;
}

void Game::initWindow()
{
	this->videoMode.height = 1000;
	this->videoMode.width = 1920;
	
	this->window = new sf::RenderWindow(this->videoMode, "Anthill", sf::Style::Default);
	this->window->setFramerateLimit(60);
}


void Game::createWorld()
{
	this->anthill.generateAnts(this->window->getSize().x/2,this->window->getSize().y/2,&this->informer);
	for (int i = 0;i< this->anthill.getCollecterList().size()-1;i++) {
		this->anthill.getCollecterList()[i]->setPosX(rand() % this ->antHillWidth + this->antHillX);
		this->anthill.getCollecterList()[i]->setPosY(rand() % this ->antHillHeight + this->antHillY);
		this->anthill.getCollecterList()[i]->coll.setPosition((float)this->anthill.getCollecterList()[i]->getPosX(),
			(float)this->anthill.getCollecterList()[i]->getPosY());
	}

	for (int i = 0;i < this->anthill.getBuilderList().size() - 1;i++) {
		this->anthill.getBuilderList()[i]->setPosX(rand() % this->antHillWidth + antHillX);
		this->anthill.getBuilderList()[i]->setPosY(rand() % this->antHillHeight + antHillY);
		this->anthill.getBuilderList()[i]->bui.setPosition((float)this->anthill.getBuilderList()[i]->getPosX(),
			(float)this->anthill.getBuilderList()[i]->getPosY());
	}

	for (int i = 0;i < this->anthill.getSoldierList().size() - 1;i++) {
		this->anthill.getSoldierList()[i]->setPosX(rand() % this->antHillWidth + this->antHillX);
		this->anthill.getSoldierList()[i]->setPosY(rand() % this->antHillHeight + this->antHillY);
		this->anthill.getSoldierList()[i]->sol.setPosition((float)this->anthill.getSoldierList()[i]->getPosX(),
			(float)this->anthill.getSoldierList()[i]->getPosY());
	}

	for (int i = 0;i < this->anthill.getNurseList().size() - 1;i++) {
		this->anthill.getNurseList()[i]->setPosX(rand() % this->antHillWidth + antHillX);
		this->anthill.getNurseList()[i]->setPosY(rand() % this->antHillHeight + antHillY);
		this->anthill.getNurseList()[i]->nur.setPosition((float)this->anthill.getNurseList()[i]->getPosX(),
			(float)this->anthill.getNurseList()[i]->getPosY());
	}

	for (int i = 0;i < this->anthill.getChildList().size() - 1;i++) {
		this->anthill.getChildList()[i]->setPosX(rand() % this->bornRoomWidth + this->bornRoomX);
		this->anthill.getChildList()[i]->setPosY(rand() % this->bornRoomHeight + this->BornRoomY);
		this->anthill.getChildList()[i]->chi.setPosition((float)this->anthill.getChildList()[i]->getPosX(),
			(float)this->anthill.getChildList()[i]->getPosY());
	}

	for (int i = 0;i < this->anthill.getCleanerList().size() - 1;i++) {
		this->anthill.getCleanerList()[i]->setPosX(rand() % this->antHillWidth + this->antHillX);
		this->anthill.getCleanerList()[i]->setPosY(rand() % this->antHillHeight + this->antHillY);
		this->anthill.getCleanerList()[i]->cle.setPosition((float)this->anthill.getCleanerList()[i]->getPosX(),
			(float)this->anthill.getCleanerList()[i]->getPosY());
	}
}


void Game::update()
{
	this->pollEvents();
	//this->upadateAnts();
}

void Game::render()
{
	this->window->clear();
	this->renderColl();
	this->renderSol();
	this->renderCle();
	this->renderChi();
	this->renderNur();
	this->renderBui();
	this->window->display(); 
}

void Game::renderColl()
{
	for (int i = 0;i<anthill.getCollecterList().size()-1;i++) {
		this->window->draw(anthill.getCollecterList()[i]->coll);
	}
}

void Game::renderCle()
{
	for (int i = 0;i < anthill.getCleanerList().size() - 1;i++) {
		this->window->draw(anthill.getCleanerList()[i]->cle);
	}
}

void Game::renderSol()
{
	for (int i = 0;i < anthill.getSoldierList().size() - 1;i++) {
		this->window->draw(anthill.getSoldierList()[i]->sol);
	}
}

void Game::renderChi()
{
	for (int i = 0;i < anthill.getChildList().size() - 1;i++) {
		this->window->draw(anthill.getChildList()[i]->chi);
	}
}

void Game::renderNur()
{
	for (int i = 0;i < anthill.getNurseList().size() - 1;i++) {
		this->window->draw(anthill.getNurseList()[i]->nur);
	}
}

void Game::renderBui() {
	for (int i = 0;i < anthill.getBuilderList().size() - 1;i++) {
		this->window->draw(anthill.getBuilderList()[i]->bui);
	}
}

Game::~Game() {
	delete this->window;
}