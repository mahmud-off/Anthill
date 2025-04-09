#include "builder.h"
#include "Field.h"
#include "Informer.h"

Builder::Builder() {
    cout << "builder created\n";
    this->setRole("builder");
}

Builder::Builder(int weight) {
    cout << "builder created\n";
    this->setRole("builder");
    this->setWeight(weight);
}


void Builder::collectMaterials(Field field) {
    if (this->getWeight() >= this->findNearestPoint(this->getPosX(), this->getPosY(), field.materialsCoordinates).first) { // material is too heavy
        // informer function will be here
        pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field.materialsCoordinates).second;
        Informer informer;
        informer.callToGetHelpToCollectMaterials(p.first, p.second, field);
    }
    else { // material is ok
        pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field.materialsCoordinates).second;
        vector<pair<int, int>> paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, p, field);
        // drawing path from points in paths with graphic
        // drawing reverse path to anthill
        field.field[p.first][p.second] = ""; // already no food in this point
        field.updateMaterialsCoordinatesList();
    }
}

void Builder::helpToCollectMaterial(int x, int y, Field field) {
    vector<pair<int, int>> paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, {x, y}, field);
    // drawing path from points in paths with graphic
}

