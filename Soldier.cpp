#include "Soldier.h"

Soldier::Soldier() {
    cout << "soldier created\n";
    this->setRole("soldier");
    hit = 10; // power of hit
}

void Soldier::helpToFightOpponent(int x, int y) {
    vector<pair<int, int>> paths = this->A_StarSearch({this->getPosX(), this->getPosY()}, {x, y});
    // drawing path from points in paths with graphic
}

