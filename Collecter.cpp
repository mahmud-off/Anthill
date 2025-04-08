#include "Collecter.h"

Collecter::Collecter()
{
	cout << "collecter created\n";
	this->setRole("collecter");
}


Collecter::Collecter(vector<Ant*>& list, Ant* &child)
{
	cout << "collecter from child" << endl;
	this->setAge(child->getAge());
	this->setRole("collecter");
	this->setHealth(child->getHealth());
	this->setWeight(child->getWeight());
	this->setPosX(child->getPosX());
	this->setPosY(child->getPosY());
	for(int i = 0; i < list.size(); ++i) {
		if(list[i] == child) {
			delete list[i];
			list.erase(list.begin()+i);
			break;
		}
	}
}

Collecter::~Collecter() {
	cout << "collecter was deleted\n";
}
