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

Soldier::Soldier(vector<Collecter *> &list, Collecter *&collecter) {
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

void Soldier::fightEnemy(Enemy enemy) {
    if (this->getHealth() - enemy.getPower() < 0) { // enemy hitted soldier and soldier died
        this->setHealth(0);
        // need to delete soldier here
    }
    else {
        this->setHealth(this->getHealth() - enemy.getPower()); // soldier didn't die
    }
    if (enemy.getHealth() - this->getPower() < 0) { // soldier hitted enemy and enemy died
        enemy.setHealth(0);
        // need to delete enemy here
    }
    else {
        enemy.setHealth(enemy.getHealth() - this->getPower()); // enemy didn't die
    }
}




void Soldier::helpToFightEnemy(int x, int y, Field field) {
    vector<pair<int, int>> paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, {x, y}, field);
    // drawing path from points in paths with graphic
}

