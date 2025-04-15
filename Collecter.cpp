#include "Collecter.h"

#include "AntHill.h"
#include "Child.h"
#include "Field.h"
#include "Informer.h"

Collecter::Collecter() {
    //getShape().setPosition(position);
    this->setRole("collecter");
	initCollecter();
}

Collecter::Collecter(int weight) {
    //getShape().setPosition(position);
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
	initCollecter();
}

Collecter::~Collecter() {
    cout << "collecter was deleted\n";
}

void Collecter::initCollecter()
{
	this->getShape().setSize(sf::Vector2f(10.f, 10.f));
	this->getShape().setFillColor(sf::Color::Cyan);
}
void Collecter::work(Field* field, Anthill* anthill) {
    string role = getRole();
    if (role == "moving") {
        updateMovement(field, anthill);
    }else if(role == "go_home") {

    }
}

void Collecter::changeStatus() {
	if (this->getStatus() == "free") {
		this->status = "busy";
	}
	else if (this->getStatus() == "busy") {
		this->status = "free";
	}
}

void Collecter::collectFood(Field *field, Anthill *anthill) {
	this->changeStatus(); // change status to busy
    if (this->getWeight() < this->findNearestPoint(this->getPosX(), this->getPosY(), field->foodCoordinates).first) {
        // food is too heavy
        pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field->foodCoordinates).second;
        Informer informer;
        informer.callToGetHelpToCollectFood(this, p.first, p.second, field, this->findNearestPoint(this->getPosX(), this->getPosY(), field->foodCoordinates).first);
    } else {
        // weight is ok
        pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field->foodCoordinates).second;
        //vector<pair<int, int> > paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, p, field);
        // drawing path from points in paths with graphic
        // drawing reverse path back to anthill
    	this->changeStatus(); // change status to free
        field->field[p.first][p.second] = ""; // already no food in this point
        field->updateFoodCoordinatesList();
    }
	anthill->setFoodCount(anthill->getFoodCount() + 1); // change foodCount by 1
}

void Collecter::helpToCollectFood(int x, int y, Field* field){
    return;
}

/*
int getRandom(int min_n, int max_n) {
    static mt19937 generator(random_device{}());
    uniform_int_distribution<int> distribution(min_n, max_n);

    return distribution(generator);
};
*/