#include "Cleaner.h"
#include "Anthill.h"
#include "Child.h"
#include "Dead.h"

Cleaner::Cleaner() {
    //cout << "cleaner created\n";
    this->setRole("cleaner");
    this->setWorkStatus("find_dead");
    this->initCleaner();

}

Cleaner::Cleaner(vector<Child *> &list, Child *&child) {
/*    cout << "cleaner from child" << endl;*/
    this->setAge(child->getAge());
    this->setRole("cleaner");
    this->setWorkStatus("find_dead");
    this->setHealth(child->getHealth());
    this->setWeight(child->getWeight());
    this->setPosX(child->getPosX());
    this->setPosY(child->getPosY());
    for (int i = 0; i < list.size(); ++i) {
        if (list[i] == child) {
            //delete list[i];
            list.erase(list.begin() + i);
            break;
        }
    }
    initCleaner();
}

void Cleaner:: initCleaner()
{
    this->getShape().setSize(sf::Vector2f(10.f, 10.f));
    this->getShape().setFillColor(sf::Color::Green);
}

Cleaner::~Cleaner() {
    //cout << "cleaner was deleted\n";
}



void Cleaner::work(Field* field, Anthill* anthill) {
    string work_status = getWorkStatus();

    if (work_status == "moving_dead") {
        this->updateMovement(field, anthill, "remove_dead");
    }
    else if (work_status == "remove_dead") {
        remove_dead(field, anthill);
        this->setWorkStatus("find_home");
    }
    else if (work_status == "find_home") { // && informer->collecterWhoNeedHelp.size() == 0
        this->findHome(anthill);
        this->setWorkStatus("moving_home");
    }
    else if (work_status == "moving_home") {
        this->updateMovement(field, anthill, "find_dead");
    }
    else if (work_status == "find_dead") {



        if (anthill->getDeadAntsList().size() != 0) {
            this->findDeadAnts(anthill);
            this->setWorkStatus("moving_dead");
        }
        else {
            this->randomMoving(field);
        }


    }

}

void Cleaner::remove_dead(Field* field, Anthill* anthill) {
    vector<Dead*>& deadList = anthill->detectedDead;

    if (deadList.size()){
        for (int i = 0; i < deadList.size(); ++i) {
            if (deadList[i]->getPosX() == this->getPosX() && deadList[i]->getPosY() == this->getPosY()) {
                deadList.erase(deadList.begin() + i);
                return;
            }
        }
    }

    this->randomMoving(field);

}

 //void Cleaner::cleanDeadAnts(Field field) {
 //    if (!canFindDeadAnts(field)) { // if can't find ants
 //        return;
 //    }
 //    pair<int, int> deadAntPosition = getPositionOfNearestDeadAnt(field);
 //    vector<pair<int, int>> pathToDeadAnt = this->A_StarSearch({this->getPosX(), this->getPosY()}, deadAntPosition, field);
 //    // cleaner go to dead ant
 //    // delete ant
 //    pair<int, int> enterCoordinates = make_pair(field.anthill->getEnterPosX(), field.anthill->getEnterPosY());
 //    pair<int, int> graveCoordinates = make_pair(field.anthill->getEnterPosX(), field.anthill->getEnterPosY());
 //    // cleaner go to enter with dead ant
 //    vector<pair<int, int>> pathToEnter = this->A_StarSearch({this->getPosX(), this->getPosY()}, enterCoordinates, field);
 //    // cleaner go to grave
 //    vector<pair<int, int>> pathFromEnterToGrave = this->A_StarSearch(enterCoordinates, graveCoordinates, field);
 //    // cleaner go back
 //}

// pair<int, int> Cleaner::getPositionOfNearestDeadAnt(Field field) {
//     double minDist = INT_MAX; //minimal distance
//     pair<int, int> coordinates(this->getPosX(), this->getPosY());
//     for (int i = 0; i < field.deadAnts.size(); i++) {
//         auto currentAnt = field.deadAnts[i];
//         double temp = distance(this->getPosX(), this->getPosY(), currentAnt->getPosX(), currentAnt->getPosY());
//         if (temp <= roView && temp < minDist) {
//             minDist = temp;
//             coordinates.first = currentAnt->getPosX();
//             coordinates.second = currentAnt->getPosY();
//         }
//     }
// }
//
// bool Cleaner::canFindDeadAnts(Field field) {
//     for (int i = 0; i < field.deadAnts.size(); i++) {
//         auto ant = field.deadAnts[i];
//         if (distance(this->getPosX(), this->getPosY(), ant->getPosX(), ant->getPosY()) <= roView)
//             return true;
//     }
//     return false;
// }
//
// double Cleaner::distance(int x1, int y1, int x2, int y2) {
//     return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
// }