#include "Enemy.h"
#include <ctime>
#include <cstdlib>
#include <math.h>
#include "AntHill.h"
#include "builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collecter.h"
#include "Nurse.h"
#include "Soldier.h"


Enemy::Enemy(int x, int y) // Coordinates compute in Field
{
    //cout << "Enemy was created\n";
    srand(time(0));
    health = 100;
    hit = 5 + rand() % 10;
    weight = 5 + rand() % 10;
    posX = x;
    posY = y;
}

Enemy::~Enemy() {
    //cout << "Enemy was deleted from " << this->posX << " " << this->posY << "\n";
}


void Enemy::hitAttackedAnt(Ant *attackedAnt) {
    if (attackedAnt->getHealth() - this->getPower() <= 0) {
        // attackedAnt become killed
        attackedAnt->setHealth(0); // when update - it will be deleted
    } else {
        attackedAnt->setHealth(attackedAnt->getHealth() - this->getPower());
    }
}

void Enemy::atackAntInField(Anthill *anthill, Field *field) {
    if (this->canFindAntsInField(anthill)) {
        Ant *attackedAnt = this->findNearestAntInField(anthill);
        this->hitAttackedAnt(attackedAnt);
        Informer informer;
        informer.callToGetHelpFromSoldier(attackedAnt, attackedAnt->getPosX(), attackedAnt->getPosY(), field, this);
    }
}


int antNotInAnthill(Ant *ant, Anthill *anthil) {
    // check if ant coordinates not in the anthill
    return 1;
}

bool Enemy::canFindAntsInField(Anthill *anthill) {
    // ant must be NOT in anthill
    for (int i = 0; i < anthill->getCollecterList().size(); i++) {
        auto ant = anthill->getCollecterList()[i];
        if (distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView) {
            if (antNotInAnthill(ant, anthill)) {
                return true;
            }
        }
    }
    for (int i = 0; i < anthill->getCleanerList().size(); i++) {
        auto ant = anthill->getCleanerList()[i];
        if (distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView) {
            if (antNotInAnthill(ant, anthill)) {
                return true;
            }
        }
    }
    for (int i = 0; i < anthill->getBuilderList().size(); i++) {
        auto ant = anthill->getBuilderList()[i];
        if (distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView) {
            if (antNotInAnthill(ant, anthill)) {
                return true;
            }
        }
    }
    for (int i = 0; i < anthill->getNurseList().size(); i++) {
        auto ant = anthill->getNurseList()[i];
        if (distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView) {
            if (antNotInAnthill(ant, anthill)) {
                return true;
            }
        }
    }
    for (int i = 0; i < anthill->getChildList().size(); i++) {
        auto ant = anthill->getChildList()[i];
        if (distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView) {
            if (antNotInAnthill(ant, anthill)) {
                return true;
            }
        }
    }
    return false;
}
Ant* Enemy::findNearestAntInField(Anthill* anthill)
{
    return nullptr;
}
/*
Ant *Enemy::findNearestAntInField(Anthill *anthill) {
    double minDist = INT_MAX; //minimal distance
    Ant *attackedAnt = nullptr;
    for (int i = 0; i < anthill->getCollecterList().size(); i++) {
        auto ant = anthill->getCollecterList()[i];
        double temp = distance(this->posX, this->posY, ant->getPosX(), ant->getPosY());
        if (temp <= roView && temp < minDist && antNotInAnthill(ant, anthill)) {
            minDist = temp;
            attackedAnt = ant;
        }
    }
    for (int i = 0; i < anthill->getBuilderList().size(); i++) {
        auto ant = anthill->getBuilderList()[i];
        double temp = distance(this->posX, this->posY, ant->getPosX(), ant->getPosY());
        if (temp <= roView && temp < minDist && antNotInAnthill(ant, anthill)) {
            minDist = temp;
            attackedAnt = ant;
        }
    }
    for (int i = 0; i < anthill->getChildList().size(); i++) {
        auto ant = anthill->getChildList()[i];
        double temp = distance(this->posX, this->posY, ant->getPosX(), ant->getPosY());
        if (temp <= roView && temp < minDist && antNotInAnthill(ant, anthill)) {
            minDist = temp;
            attackedAnt = ant;
        }
    }
    for (int i = 0; i < anthill->getCleanerList().size(); i++) {
        auto ant = anthill->getCleanerList()[i];
        double temp = distance(this->posX, this->posY, ant->getPosX(), ant->getPosY());
        if (temp <= roView && temp < minDist && antNotInAnthill(ant, anthill)) {
            minDist = temp;
            attackedAnt = ant;
        }
    }
    for (int i = 0; i < anthill->getNurseList().size(); i++) {
        auto ant = anthill->getNurseList()[i];
        double temp = distance(this->posX, this->posY, ant->getPosX(), ant->getPosY());
        if (temp <= roView && temp < minDist && antNotInAnthill(ant, anthill)) {
            minDist = temp;
            attackedAnt = ant;
        }
    }
    return attackedAnt;
}
*/

double Enemy::distance(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

//
double hFunc(pair<int, int> p1, pair<int, int> p2) {
    return sqrt((p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second));
}

vector<pair<int, int> > A_StarSearch(pair<int, int> start, pair<int, int> end) {
    vector<pair<int, int> > path; // path from start to end

    vector<pair<int, int> > options; // варианты куда можно пойти от точки старт (право лево вверх вниз)

    while (start != end) {
        options.push_back({start.first + 1, start.second});
        options.push_back({start.first - 1, start.second});
        options.push_back({start.first, start.second + 1});
        options.push_back({start.first, start.second - 1});

        vector<pair<double, pair<int, int> > > vH; // vector of h(option[i]) for every options
        for (auto x: options) {
            vH.push_back({hFunc(x, end), x});
        }
        sort(vH.begin(), vH.end());
        path.push_back(vH[0].second);
        start = vH[0].second;
    }
    return path;
}

bool Enemy::canFindFoodInAnthill(Anthill *anthill) {
    if (distance(this->posX, this->posY, anthill->getFoodStorage_X(), anthill->getFoodStorage_Y()) <= roView) {
        return true;
    }
    return false;
}

void Enemy::moveToFoodStorage(Anthill *anthill) {
    pair<int, int> enemiesCoordinates = {this->getPosX(), this->getPosY()};
    pair<int, int> foodStorageCoordinates = {anthill->getFoodStorage_X(), anthill->getFoodStorage_Y()};
    vector<pair<int, int>> pathToFoodStorage = A_StarSearch(enemiesCoordinates, foodStorageCoordinates);
    // draw path to food storage
}


void Enemy::stealFoodFromAnthill(Anthill *anthill) {
    if (this->canFindFoodInAnthill(anthill)) {
        this->moveToFoodStorage(anthill);
        if (anthill->getScale() != 0) {
            anthill->setScale(anthill->getScale() - 1);
        }
    }
}
