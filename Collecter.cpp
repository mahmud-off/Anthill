#include "Collecter.h"
#include "Field.h"
#include "Informer.h"

Collecter::Collecter() {
	cout << "collecter created\n";
	this->setRole("collecter");
}

void Collecter::collectFood(Field field) {
	if (this->getWeight() >= this->findNearestPoint(this->getPosX(), this->getPosY(), field.foodCoordinates).first) { // food is too heavy
		// informer function will be here
		pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field.foodCoordinates);
		Informer informer;
		informer.callToGetHelpToCollectFood(p.first, p.second, field);
	}
	else { // food is ok
		pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field.foodCoordinates);
		vector<pair<int, int>> paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, p);
		// drawing path from points in paths with graphic
		// drawing reverse path to anthill
		field.field[p.first][p.second] = ""; // already no food in this point
		field.updateFoodCoordinatesList();
	}
}

void Collecter::helpToCollectFood(int x, int y) {
	vector<pair<int, int>> paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, {x, y});
	// drawing path from points in paths with graphic
}

