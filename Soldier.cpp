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




void Soldier::helpToFightOpponent(int x, int y, Field field) {
    vector<pair<int, int>> paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, {x, y}, field);
    // drawing path from points in paths with graphic
}

