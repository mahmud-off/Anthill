#include "Nurse.h"

Nurse::Nurse()
{
	cout << "nurse created\n";
	this->setRole("nurse");
	this->initNurse();
}

Nurse::Nurse(vector<Cleaner *> &list, Cleaner *&cleaner) {
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
	this->initNurse();
}
void Nurse::initNurse() {
	this->get_shape().setSize(sf::Vector2f(10.f, 10.f));
	this->get_shape().setFillColor(sf::Color::Yellow);
}
Nurse::~Nurse() {
	cout << "nurse was deleted\n";
}
