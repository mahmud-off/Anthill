#include "Collecter.h"
#include "Field.h"
#include "Informer.h"

Collecter::Collecter() {
    cout << "collecter created\n";
    this->setRole("collecter");
	initCollecter();
}

Collecter::Collecter(int weight) {
    cout << "collecter created\n";
    this->setRole("collecter");
    this->setWeight(weight);
	initCollecter();
}


Collecter::Collecter(vector<Child*>& list, Child* &child)
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

void Collecter::changeStatus() {
	if (this->getStatus() == "free") {
		this->status = "busy";
	}
	else if (this->getStatus() == "busy") {
		this->status = "free";
	}
}

void Collecter::initCollecter()
{
	this->coll.setSize(sf::Vector2f(10.f, 10.f));
	this->coll.setFillColor(sf::Color::Cyan);
}


void Collecter::collectFood(Field field) {
	this->changeStatus(); // change status to busy
    if (this->getWeight() < this->findNearestPoint(this->getPosX(), this->getPosY(), field.foodCoordinates).first) {
        // food is too heavy
        pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field.foodCoordinates).second;
        Informer informer;
        informer.callToGetHelpToCollectFood(this, p.first, p.second, field, this->findNearestPoint(this->getPosX(), this->getPosY(), field.foodCoordinates).first);
    } else {
        // weight is ok
        pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field.foodCoordinates).second;
        vector<pair<int, int> > paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, p, field);
        // drawing path from points in paths with graphic
        // drawing reverse path to anthill
        field.field[p.first][p.second] = ""; // already no food in this point
        field.updateFoodCoordinatesList();
    }
}

void Collecter::helpToCollectFood(int x, int y, Field field) {
	this->changeStatus();
    vector<pair<int, int> > paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, {x, y}, field);
    // drawing path from points in paths with graphic
}
