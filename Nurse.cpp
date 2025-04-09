#include "Nurse.h"

Nurse::Nurse()
{
	cout << "nurse created\n";
	this->setRole("nurse");
}

Nurse::Nurse(vector<Ant *> &list, Ant *&cleaner) {
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
}

Nurse::~Nurse() {
	cout << "nurse was deleted\n";
}
