#include "Nurse.h"
#include "Cleaner.h"
#include "Game.h"

Nurse::Nurse(Game *game)
{
	cout << "nurse created\n";
	this->setRole("nurse");
	this->initNurse(game);
}

void Nurse::work(Field* field, Anthill* anthill, Game* game){
	string work_status = getWorkStatus();

	if (work_status == "moving") {
		this->updateMovement(field, anthill, "find_new_position");

		this->changeStatus(); // change status to busy
	}
	else if (work_status == "find_new_position") {
		pair<int,int> randomPointInNursery= randomAntNurseryPos();
		this->setEndPoint(randomPointInNursery);

		this->setWorkStatus("moving");
	}

}

Nurse::Nurse(vector<Cleaner *> &list, Cleaner *&cleaner, Game *game) {
	cout << "nurse from collecter" << endl;
	this->setAge(cleaner->getAge());
	this->setRole("nurse");
	this->setHealth(cleaner->getHealth());
	this->setWeight(cleaner->getWeight());
	this->setPosX(cleaner->getPosX());
	this->setPosY(cleaner->getPosY());
	for(int i = 0; i < list.size(); ++i) {
		if(list[i] == cleaner) {
			delete list[i];
			list.erase(list.begin()+i);
			break;
		}
	}
	this->initNurse(game);
}
void Nurse::initNurse(Game *game) {
	this->getShape().setSize(sf::Vector2f(10.f, 10.f));
	this->getShape().setTexture(&game->textureForNurse);
	this->getShape().setScale(5.f, 5.f);
}
Nurse::~Nurse() {
    cout << "nurse was deleted\n";
}
