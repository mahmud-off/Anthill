#include "Soldier.h"

Soldier::Soldier() {
    cout << "soldier created\n";
    this->setRole("soldier");
    // hit = 10; // power of hit
}

Soldier::Soldier(int power) {
    cout << "soldier created\n";
    this->setRole("soldier");
    this->setPower(power);
}

Soldier::Soldier(vector<Ant *> &list, Ant *&collecter) {
    cout << "soldier from collecter" << endl;
    this->setAge(collecter->getAge());
    this->setRole("soldier");
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

Soldier::~Soldier() {
    cout << "soldier was deleted\n";
}





void Soldier::helpToFightOpponent(int x, int y, Field field) {
    vector<pair<int, int>> paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, {x, y}, field);
    // drawing path from points in paths with graphic
}

