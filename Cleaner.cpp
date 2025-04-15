#include "Cleaner.h"

#include "AntHill.h"
#include "Child.h"
#include "Dead.h"

Cleaner::Cleaner() {
    cout << "cleaner created\n";
    this->setRole("cleaner");
}

Cleaner::Cleaner(vector<Child *> &list, Child *&child) {
    cout << "cleaner from child" << endl;
    this->setAge(child->getAge());
    this->setRole("cleaner");
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

Cleaner::~Cleaner() {
    cout << "cleaner was deleted\n";
}

void Cleaner::cleanDeadAnts(Field *field, Anthill *anthill) {
    if (!canFindDeadAnts(field, anthill)) { // if can't find ants
        return;
    }
    Dead* deadAnt = this->findNearestDeadAnt(field, anthill);
    pair<int, int> deadAntPosition = {deadAnt->getPosX(), deadAnt->getPosY()};
    vector<pair<int, int>> pathToDeadAnt = this->A_StarSearch({this->getPosX(), this->getPosY()}, deadAntPosition, field);
    // draw cleaner path to dead ant
    // delete ant
    pair<int, int> enterCoordinates = make_pair(anthill->getEnterPosX(), anthill->getEnterPosY());
    pair<int, int> graveCoordinates = make_pair(anthill->getEnterPosX(), anthill->getEnterPosY());
    // cleaner go to enter with dead ant
    vector<pair<int, int>> pathToEnter = this->A_StarSearch({this->getPosX(), this->getPosY()}, enterCoordinates, field);
    // cleaner go to grave
    vector<pair<int, int>> pathFromEnterToGrave = this->A_StarSearch(enterCoordinates, graveCoordinates, field);
    // cleaner go back
}

Dead* Cleaner::findNearestDeadAnt(Field *field, Anthill *anthill) {
    double minDist = INT_MAX; //minimal distance
    pair<int, int> coordinates(this->getPosX(), this->getPosY());
    Dead* nearestDeadAnt;
    for (int i = 0; i < anthill->getDeadAntsList().size(); i++) {
        auto currentAnt = anthill->getDeadAntsList()[i];
        double temp = distance(this->getPosX(), this->getPosY(), currentAnt->getPosX(), currentAnt->getPosY());
        if (temp <= roView && temp < minDist) {
            minDist = temp;
            nearestDeadAnt = currentAnt;
            coordinates.first = currentAnt->getPosX();
            coordinates.second = currentAnt->getPosY();
        }
    }
    return nearestDeadAnt;
}
//
bool Cleaner::canFindDeadAnts(Field *field, Anthill *anthill) {
    for (int i = 0; i < anthill->getDeadAntsList().size(); i++) {
        auto ant = anthill->getDeadAntsList()[i];
        if (distance(this->getPosX(), this->getPosY(), ant->getPosX(), ant->getPosY()) <= roView)
            return true;
    }
    return false;
}
//
double Cleaner::distance(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}