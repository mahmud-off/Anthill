#include "Game.h"


int getRandom(int min_n, int max_n) {
	static mt19937 generator(random_device{}());
	uniform_int_distribution<int> distribution(min_n, max_n);

	return distribution(generator);
};


Game::Game():anthill(1000,0,0),field(0,0) {
	this->initVar();
	this->initWindow();
	anthill.setxy(this->antHillX, this->antHillY,this->antHillWidth,this->antHillHeight);
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
		this->anthill.getCollecterList()[i]->setPosX(getRandom(this->antHillX,this->antHillWidth + this->antHillX));
		this->anthill.getCollecterList()[i]->setPosY(getRandom(this->antHillY,this->antHillY + this->antHillHeight  ));
		this->anthill.getCollecterList()[i]->getShape().setPosition((float)this->anthill.getCollecterList()[i]->getPosX(),
			(float)this->anthill.getCollecterList()[i]->getPosY());
	}

	for (int i = 0;i < this->anthill.getBuilderList().size() - 1;i++) {
		this->anthill.getBuilderList()[i]->setPosX(getRandom(this->antHillX,this->antHillWidth + this->antHillX));
		this->anthill.getBuilderList()[i]->setPosY(getRandom(this->antHillY,this->antHillY + this->antHillHeight));
		this->anthill.getBuilderList()[i]->getShape().setPosition((float)this->anthill.getBuilderList()[i]->getPosX(),
			(float)this->anthill.getBuilderList()[i]->getPosY());
	}

	for (int i = 0;i < this->anthill.getSoldierList().size() - 1;i++) {
		this->anthill.getSoldierList()[i]->setPosX(getRandom(this->antHillX,this->antHillWidth + this->antHillX));
		this->anthill.getSoldierList()[i]->setPosY(getRandom(this->antHillY,this->antHillY + this->antHillHeight));
		this->anthill.getSoldierList()[i]->getShape().setPosition((float)this->anthill.getSoldierList()[i]->getPosX(),
			(float)this->anthill.getSoldierList()[i]->getPosY());
	}

	for (int i = 0;i < this->anthill.getNurseList().size() - 1;i++) {
		this->anthill.getNurseList()[i]->setPosX(getRandom(this->antHillX,this->antHillWidth + this->antHillX));
		this->anthill.getNurseList()[i]->setPosY(getRandom(this->antHillY,this->antHillY + this->antHillHeight));
		this->anthill.getNurseList()[i]->getShape().setPosition((float)this->anthill.getNurseList()[i]->getPosX(),
			(float)this->anthill.getNurseList()[i]->getPosY());
	}

	for (int i = 0;i < this->anthill.getChildList().size() - 1;i++) {
		this->anthill.getChildList()[i]->setPosX(getRandom(this->bornRoomX, this->antHillWidth + this->antHillX));
		
		this->anthill.getChildList()[i]->setPosY(getRandom(this->BornRoomY , this->BornRoomY + this->bornRoomHeight));

		this->anthill.getChildList()[i]->getShape().setPosition((float)this->anthill.getChildList()[i]->getPosX(),(float)this->anthill.getChildList()[i]->getPosY());
		//cout << "---------" << (float)this->anthill.getChildList()[i]->getPosX() << "  " << (float)this->anthill.getChildList()[i]->getPosY() << "\n";
		//cout << this->anthill.getChildList()[i]->get_shape().getFillColor().toInteger()<<"\n";
	}

	for (int i = 0;i < this->anthill.getCleanerList().size() - 1;i++) {
		this->anthill.getCleanerList()[i]->setPosX(getRandom(this->antHillX,this->antHillWidth + this->antHillX));
		this->anthill.getCleanerList()[i]->setPosY(getRandom(this->antHillY,this->antHillY + this->antHillHeight));
		this->anthill.getCleanerList()[i]->getShape().setPosition((float)this->anthill.getCleanerList()[i]->getPosX(),
			(float)this->anthill.getCleanerList()[i]->getPosY());
	}
}


void Game::update()
{
	this->pollEvents();
	//testing
	for (int i = 0; i < this->anthill.getCollecterList().size(); ++i) {
	Collecter* ant = this->anthill.getCollecterList()[i];

	ant->setEndPoint({ 0,0 });

	ant->updateMovement(&this->field, &this->anthill);
	}

	//ant->setPosX(getRandom(0,1024));
	//ant->setPosY()

	//this->upadateAnts();
}

void Game::render()
{
	this->window->clear();
	this->renderCollecter();
	this->renderSoldier();
	this->renderCleaner();
	this->renderChild();
	this->renderNurse();
	this->renderBuilder();
	this->window->display(); 
}

void Game::renderCollecter()
{
	for (int i = 0;i<anthill.getCollecterList().size()-1;i++) {
		this->window->draw(anthill.getCollecterList()[i]->getShape());
	}
}

void Game::renderCleaner()
{
	for (int i = 0;i < anthill.getCleanerList().size() - 1;i++) {
		this->window->draw(anthill.getCleanerList()[i]->getShape());
	}
}

void Game::renderFood() {
	for (int i = 0;i < field.foodCoordinates.size();i++)
	{

	}
}

void Game::renderSoldier()
{
	for (int i = 0;i < anthill.getSoldierList().size() - 1;i++) {
		this->window->draw(anthill.getSoldierList()[i]->getShape());
	}
}

void Game::renderChild()
{
	for (int i = 0;i < anthill.getChildList().size() - 1;i++) {

		this->window->draw(anthill.getChildList()[i]->getShape());
	}
}

void Game::renderNurse()
{
	for (int i = 0;i < anthill.getNurseList().size() - 1;i++) {
		this->window->draw(anthill.getNurseList()[i]->getShape());
	}
}

void Game::renderBuilder() {
	for (int i = 0;i < anthill.getBuilderList().size() - 1;i++) {
		this->window->draw(anthill.getBuilderList()[i]->getShape());
	}
}




Game::~Game() {
	delete this->window;
}