#include "Collecter.h"
#include "Field.h"
#include "Informer.h"

Collecter::Collecter() {
    cout << "collecter created\n";
    this->setRole("collecter");
}

Collecter::Collecter(int weight) {
    cout << "collecter created\n";
    this->setRole("collecter");
    this->setWeight(weight);
}


Collecter::Collecter(vector<Ant *> &list, Ant * &child) {
    cout << "collecter from child" << endl;
    this->setAge(child->getAge());
    this->setRole("collecter");
    this->setHealth(child->getHealth());
    this->setWeight(child->getWeight());
    this->setPosX(child->getPosX());
    this->setPosY(child->getPosY());
    for (int i = 0; i < list.size(); ++i) {
        if (list[i] == child) {
            delete list[i];
            list.erase(list.begin() + i);
            break;
        }
    }
}

Collecter::~Collecter() {
    cout << "collecter was deleted\n";
}

void Collecter::collectFood(Field field) {
    if (this->getWeight() < this->findNearestPoint(this->getPosX(), this->getPosY(), field.foodCoordinates).first) {
        // food is too heavy
        // cout << "food isn't available!\n";
        // cout << this->findNearestPoint(this->getPosX(), this->getPosY(), field.foodCoordinates).first << "\n";
        // informer function will be here
        pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field.foodCoordinates).second;
        Informer informer;
        informer.callToGetHelpToCollectFood(p.first, p.second, field);
    } else {
        // food is ok
        pair<int, int> p = this->findNearestPoint(this->getPosX(), this->getPosY(), field.foodCoordinates).second;
        vector<pair<int, int> > paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, p, field);
        // drawing path from points in paths with graphic
        // drawing reverse path to anthill

        //for testing
        for (auto x: paths) {
            cout << x.first << " " << x.second << "\n";
        }
        //

        field.field[p.first][p.second] = ""; // already no food in this point
        field.updateFoodCoordinatesList();
    }
}

void Collecter::helpToCollectFood(int x, int y, Field field) {
    vector<pair<int, int> > paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, {x, y}, field);
    // drawing path from points in paths with graphic
}
