#include "Cleaner.h"

Cleaner::Cleaner()
{
	cout << "cleaner created\n";
	this->setRole("cleaner");
}

Cleaner::Cleaner(vector<Child *> &list, Child *&child)
{
	cout << "cleaner from child" << endl;
	this->setAge(child->getAge());
	this->setRole("cleaner");
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

Cleaner::~Cleaner()
{
	cout << "cleaner was deleted\n";
}
