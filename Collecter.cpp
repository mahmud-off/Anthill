#include "Collecter.h"

#include "AntHill.h"
#include "Child.h"
#include "Field.h"
#include "Game.h"
#include "Informer.h"

Collecter::Collecter(Game *game) {
    //getShape().setPosition(position);
    this->setRole("collecter");
	this->setWorkStatus("find_food");
	this->setAge(getRandomPoint(200, 250));
	initCollecter(game);
}

Collecter::Collecter(int weight, Game *game) {
    //getShape().setPosition(position);
    this->setRole("collecter");
	this->setWorkStatus("find_food");
    this->setWeight(weight);
	initCollecter(game);
}


Collecter::Collecter(vector<Child*>& list, Child* &child, Game* game)
{
	//cout << "collecter from child" << endl;
	this->setAge(child->getAge());
	this->setRole("collecter");
	this->setWorkStatus("find_food");
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
	initCollecter(game);
}

Collecter::~Collecter() {
    //cout << "collecter was deleted\n";
}

void Collecter::initCollecter(Game *game)
{
	this->getShape().setSize(sf::Vector2f(10.f, 10.f));
	this->getShape().setTexture(&game->textureForCollecter);
	this->getShape().setScale(5.f, 5.f);
}
void Collecter::work(Field* field, Anthill* anthill, Game* game) {
	string work_status = getWorkStatus();

	if (work_status == "moving_food") {
		this->updateMovement(field, anthill, "collect_food");

		//cout << "bam" << " ";

		//this->changeStatus(); // change status to busy
	}else if (work_status == "collect_food") {
		collectFood(field, anthill);
		this->setWorkStatus("find_home");

	}else if (work_status == "find_home") { // && informer->collecterWhoNeedHelp.size() == 0
		this->findHome(anthill);
		this->setWorkStatus("moving_home");

	}else if(work_status == "moving_home"){
		this->updateMovement(field, anthill, "find_food");

	}else if (work_status == "find_food") {
		growthFood(anthill);
		this->findFood(field, game);

		if (field->foodCoordinates.size() != 0) {
			this->changeStatus();
			this->findFood(field, game);
			this->setWorkStatus("moving_food");
		}
		else {
			this->randomMoving(field);
		}

		//cout << this->getWorkStatus() << "\n";
	}
	/*else if (work_status == help") {
		findNearestPoint of collecterWhoNeedHelp
		this->setEndPoint({point.first, point.second})
	 }
	 */
}
void Collecter::changeStatus() {
	if (this->getStatus() == "free") {
		this->status = "busy";
	}
	else if (this->getStatus() == "busy") {
		this->status = "free";
	}
}
void Collecter::growthFood(Anthill* anthill) {
	anthill->setFoodCount(anthill->getFoodCount() + 1); // change foodCount by 1
}


void Collecter::collectFood(Field *field, Anthill *anthill) {
	//if (this->getWeight() < this->findNearestPoint(this->getPosX(), this->getPosY(), field->foodCoordinates).first) {
	//    // food is too heavy
	//    pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field->foodCoordinates).second;
	//    Informer informer;
	//    informer.callToGetHelpToCollectFood(this, p.first, p.second, field, this->findNearestPoint(this->getPosX(), this->getPosY(), field->foodCoordinates).first);
	//    /*this->setWorkStatus("collect_food");*/
	//}else if (this->getWorkStatus() == "collect_food") {
	//    return;
	//}else {
	// weight is ok
	//pair<int, int> p = this->findNearestPointCollecter(this->getPosX(), this->getPosY(), field->foodCoordinates).second;
	//vector<pair<int, int> > paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, p, field);
	// drawing path from points in paths with graphic
	// drawing reverse path back to anthill
	this->changeStatus(); // change status to free
	//cout << "Check Ant's point" << field->field[this->getPosY()][this->getPosX()] << " \n";
	field->field[this->getPosY()][this->getPosX()] = "";// already no food in this point
	field->updateFoodCoordinatesList();

	anthill->setFoodCount(anthill->getFoodCount() + 1); // change foodCount by 1
	//}
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