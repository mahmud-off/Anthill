#include "builder.h"

Builder::Builder()
{
	cout << "builder created\n";
	this->setRole("builder");
}

Builder::Builder(vector<Collecter *> &list, Collecter *&collecter) {
	cout << "builder from collecter" << endl;
	this->setAge(collecter->getAge());
	this->setRole("builder");
	this->setHealth(collecter->getHealth());
	this->setWeight(collecter->getWeight());
	this->setPosX(collecter->getPosX());
	this->setPosY(collecter->getPosY());
	for(int i = 0; i < list.size(); ++i) {
		if(list[i] == collecter) {
			delete list[i];
			list.erase(list.begin()+i);
			break;
		}
	}
}

Builder::~Builder() {
	cout << "builder was deleted\n";
}
