#include "AntHill.h"
#include "builder.h"
#include "Collecter.h"
#include "Field.h"
#include "Informer.h"

#define CONST_MAKE_ANTHILL_BIGGER 5

Builder::Builder() {
    cout << "builder created\n";
    this->setRole("builder");
}

Builder::Builder(int weight) {
    cout << "builder created\n";
    this->setRole("builder");
    this->setWeight(weight);
}


void Builder::collectMaterials(Field *field, Anthill *anthill) {
	this->changeStatus(); // change status to busy
    if (this->getWeight() < this->findNearestPoint(this->getPosX(), this->getPosY(), field->materialsCoordinates).first) {
    	// material is too heavy
        pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field->materialsCoordinates).second;
        Informer informer;
        informer.callToGetHelpToCollectMaterials(this, p.first, p.second, field, this->findNearestPoint(this->getPosX(), this->getPosY(), field->materialsCoordinates).first);
    }
    else {
    	// material weight is ok
        pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field->materialsCoordinates).second;
        vector<pair<int, int>> paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, p, field);
        // drawing path from points in paths with graphic
        // drawing reverse path back to anthill
    	this->changeStatus(); // change status to free
        field->field[p.first][p.second] = ""; // already no food in this point
        field->updateMaterialsCoordinatesList();
    }
	anthill->setMaterialsCount(anthill->getMaterialsCount() + 1); // increase materials by 1
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

void Builder::helpToCollectMaterial(int x, int y, Field *field) {
	this->changeStatus(); // change status to busy
    vector<pair<int, int>> paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, {x, y}, field);
    // drawing path from points in paths with graphic
}

void Builder::buildAnthill(Anthill *anthill) {
	anthill->setScale(anthill->getScale() + CONST_MAKE_ANTHILL_BIGGER);
}

