#include "Collecter.h"
#include "Field.h"

Collecter::Collecter() {
    cout << "collecter created\n";
    this->setRole("collecter");
}

void Collecter::CollectFood(Field field) {
    if (this->getWeight() >= this->findNearestPoint(this->getPosX(), this->getPosY(), field.foodCoordinates).first) { // муравей не может поднять такой вес
        // notification function will be here
    }
    else { // если муравей может поднять данный вес
        pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field.foodCoordinates);
        vector<pair<int, int>> paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, p);
        // drawing path from points in paths with graphic
        // drawing reverse path to anthill
        field.field[p.first][p.second] = ""; // already no food in this point
        field.updateFoodCoordinatesList();
    }
}

