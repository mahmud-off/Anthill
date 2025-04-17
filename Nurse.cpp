#include "Nurse.h"
#include "Cleaner.h"
Nurse::Nurse()
{
	//cout << "nurse created\n";
	this->setRole("nurse");
	this->setWorkStatus("find_new_position");
	this->setAge(getRandomPoint(400, 800));
	this->initNurse();
}

void Nurse::work(Field* field, Anthill* anthill){
	string work_status = getWorkStatus();

	if (work_status == "moving") {
		this->updateMovement(field, anthill, "find_new_position");

		this->changeStatus(); // change status to busy
	}
	else if (work_status == "find_new_position") {
		pair<int,int> randomPointInNursery= randomAntNurseryPos(anthill);
		this->setEndPoint(randomPointInNursery);

		this->setWorkStatus("moving");
	}

}

Nurse::Nurse(vector<Cleaner *> &list, Cleaner *&cleaner) {
	//cout << "nurse from collecter" << endl;
	this->setAge(cleaner->getAge());
	this->setRole("nurse");
	this->setWorkStatus("find_new_position");
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
	this->initNurse();
}
void Nurse::initNurse() {
	this->getShape().setSize(sf::Vector2f(10.f, 10.f));
	this->getShape().setFillColor(sf::Color::Yellow);
}
Nurse::~Nurse() {
    //cout << "nurse was deleted\n";
}
