#include "builder.h"
#include "Field.h"
#include "Informer.h"

Builder::Builder() {
    cout << "builder created\n";
    this->setRole("builder");
    this->initBuilder();
}

Builder::Builder(int weight) {
    cout << "builder created\n";
    this->setRole("builder");
    this->setWeight(weight);
    this->initBuilder();
}


void Builder::collectMaterials(Field field) {
    if (this->getWeight() < this->findNearestPoint(this->getPosX(), this->getPosY(), field.materialsCoordinates).first) { // material is too heavy
        // informer function will be here
    	// for testing
    	cout << "material isn't available" << this->findNearestPoint(this->getPosX(), this->getPosY(), field.materialsCoordinates).first << "\n";
        pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field.materialsCoordinates).second;
        Informer informer;
        informer.callToGetHelpToCollectMaterials(p.first, p.second, field);
    }
    else { // material is ok
        pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field.materialsCoordinates).second;
        vector<pair<int, int>> paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, p, field);
        // drawing path from points in paths with graphic
        // drawing reverse path to anthill

    	// for testing
    	for (auto x: paths) {
    		cout << x.first << " " << x.second << "\n";
    	}
    	//
        field.field[p.first][p.second] = ""; // already no food in this point
        field.updateMaterialsCoordinatesList();
    }
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

void Builder::initBuilder() {
    this->bui.setSize(sf::Vector2f(10.f, 10.f));
    this->bui.setFillColor(sf::Color::White);
}

Builder::~Builder() {
	cout << "builder was deleted\n";
}

void Builder::helpToCollectMaterial(int x, int y, Field field) {
    vector<pair<int, int>> paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, {x, y}, field);
    // drawing path from points in paths with graphic
}

