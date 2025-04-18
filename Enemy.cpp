#include "Enemy.h"
#include <ctime>
#include <cstdlib>
#include <utility>
#include <math.h>
#include "AntHill.h"
#include "builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collecter.h"
#include "Field.h"
#include "Nurse.h"
#include "Soldier.h"
#include "Storage.h"

int getRandomPoint_move_enemy(int min_n, int max_n) {
    static mt19937 generator(random_device{}());
    uniform_int_distribution<int> distribution(min_n, max_n);

    return distribution(generator);
}


Enemy::Enemy(int x, int y, int hit) // Coordinates compute in Field
{
    //cout << "Enemy was created\n";
    srand(time(0));
    work_status = "find_new_ant";
    health = 100;
    hit = 5 + rand() % 10;
    weight = 5 + rand() % 10;
    posX = x;
    posY = y;
    initEnemy(x, y, hit);
}

Enemy::~Enemy() {
    //cout << "Enemy was deleted from " << this->posX << " " << this->posY << "\n";
}

void Enemy::initEnemy(int x, int y, int hit) {
    this->getEnemyShape().setPosition((float)x, (float)y);
    this->getEnemyShape().setFillColor(sf::Color::Cyan);
    this->getEnemyShape().setRadius(5.f);
    this->setHit(hit);
}


void Enemy::hitAttackedAnt(Ant *attackedAnt) {
    if (attackedAnt->getHealth() - this->getPower() <= 0) {
        // attackedAnt become killed

        attackedAnt->setHealth(0); // when update - it will be deleted
        this->setWorkStatus("find_new_ant");
    } else {
        attackedAnt->setHealth(attackedAnt->getHealth() - this->getPower());

    }
}

void Enemy::atackAntInField(Anthill *anthill, Field *field) {
    if (this->getPosX() == this->ant->getPosX() && this->getPosY() == this->ant->getPosY()) {
        this->hitAttackedAnt(this->ant);
        cout << 1;
        //Informer informer;
        //informer.callToGetHelpFromSoldier(this->ant, this->ant->getPosX(), this->ant->getPosY(), field, this);
        cout << 2;
        this->setWorkStatus("find_new_ant");
        cout << this->ant->getHealth() << "\n";
    }
    /*
    else {
        this->setWorkStatus("fight");
        this->updateMovement(field, anthill, "fight");
        this->atackAntInField(anthill, field);
    }
    */
}


int antNotInAnthill(Ant* ant, Anthill* anthill) {
    
    if (!(ant->getPosX() >= anthill->getPosX() && ant->getPosX() <= anthill->getPosX() + anthill->getWidth() && ant->getPosY() >= anthill->getPosY() && ant->getPosY() <= anthill->getPosY() + anthill->getHeight())){
        //cout << "lohhhh" << "\n";
        return 1;
    }

    return 0;
}

bool Enemy::canFindAntsInField(Anthill *anthill) {
    // ant must be NOT in anthill
    for (int i = 0; i < anthill->getCollecterList().size(); i++) {
        auto ant = anthill->getCollecterList()[i];
        if (distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView && distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) > 0) {
            if (antNotInAnthill(ant, anthill)) {
                return true;
            }  
        }
    }
    for (int i = 0; i < anthill->getCleanerList().size(); i++) {
        auto ant = anthill->getCleanerList()[i];
        if (distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView && distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) > 0) {
            if (antNotInAnthill(ant, anthill)) {
                return true;
            }
        }
    }
    for (int i = 0; i < anthill->getBuilderList().size(); i++) {
        auto ant = anthill->getBuilderList()[i];
        if (distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView && distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) > 0) {
            if (antNotInAnthill(ant, anthill)) {
                return true;
            }
        }
    }
    for (int i = 0; i < anthill->getNurseList().size(); i++) {
        auto ant = anthill->getNurseList()[i];
        if (distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView && distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) > 0) {
            if (antNotInAnthill(ant, anthill)) {
                return true;
            }
        }
    }
    for (int i = 0; i < anthill->getChildList().size(); i++) {
        auto ant = anthill->getChildList()[i];
        if (distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) <= roView && distance(this->posX, this->posY, ant->getPosX(), ant->getPosY()) > 0) {
            if (antNotInAnthill(ant, anthill)) {
                return true;
            }
        }
    }
    return false;
}


Ant* Enemy::findNearestAntInField(Anthill *anthill) {
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

double Enemy::distance(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int getRandomPoint___(int min_n, int max_n) {
    static mt19937 generator(random_device{}());
    uniform_int_distribution<int> distribution(min_n, max_n);

    return distribution(generator);
}

void Enemy::work(Field* field, Anthill* anthill){
    string now_work_status = getWorkStatus();

    if(now_work_status == "moving_ant") {
        updateMovement(field, anthill, "find_new_ant");
    }else if(now_work_status == "find_new_ant") {
        this->ant->setEndPoint({getRandomPoint___(0, field->getWidth()-3), getRandomPoint___(0, field->getHeight()-3)});
    }
/*
    if (now_work_status == "moving_ant") {
        //this->updateMovement(field, anthill, "fight");
        this->updateMovement(field, anthill, "fight");
    }
    else if (now_work_status == "fight") {
        atackAntInField(anthill, field);
    }
    else if (work_status == "find_new_ant") {
        
        if (canFindAntsInField(anthill)) {
            this->ant = findNearestAntInField(anthill);
            this->setWorkStatus("moving_ant");
        }
        else {
            randomMoving(field);
        }
    }
    */

}

void Enemy::randomMoving(Field* filed) {
    int randMove = getRandomPoint_move_enemy(-1, 1);
    setPosX(getPosX() + randMove);

    randMove = getRandomPoint_move_enemy(-1, 1);
    setPosY(getPosY() + randMove);

    enemyShape.setPosition(sf::Vector2f(getPosX(), getPosY()));

}

void Enemy::updateMovement(Field* field, Anthill* anthill, string new_work){
    if (getPosX() != this->ant->getPosX() || getPosY() != this->ant->getPosY() && !( getPosX()+1 >= anthill->getPosX() && getPosX()-1 <= (anthill->getPosX() + anthill->getWidth()) && getPosY()+1 >= anthill->getPosY() && getPosY()-1 <= (anthill->getPosY() + anthill->getHeight()))){
        if (getPosX() < this->ant->getPosX()) setPosX(getPosX() + 1);
        else if (getPosX() > this->ant->getPosX()) setPosX(getPosX() - 1);

        if (getPosY() < this->ant->getPosY()) setPosY(getPosY() + 1);
        else if (getPosY() > this->ant->getPosY()) setPosY(getPosY() - 1);

        enemyShape.setPosition(sf::Vector2f(getPosX(), getPosY()));
        //printPosition();
    }
    else {
        this->setWorkStatus(std::move(new_work));
    }
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
    if (distance(this->posX, this->posY, anthill->storage->getX(), anthill->storage->getY()) <= roView) {
        return true;
    }
    return false;
}

void Enemy::moveToFoodStorage(Anthill *anthill) {
    pair<int, int> enemiesCoordinates = {this->getPosX(), this->getPosY()};
    pair<int, int> foodStorageCoordinates = {anthill->storage->getX(), anthill->storage->getY()};
    vector<pair<int, int>> pathToFoodStorage = A_StarSearch(enemiesCoordinates, foodStorageCoordinates);
    // draw path to food storage
}


void Enemy::stealFoodFromAnthill(Anthill *anthill, Field *field) {
    if (this->canFindFoodInAnthill(anthill)) {
        this->moveToFoodStorage(anthill);
        if (anthill->getScale() != 0) {
            anthill->setScale(anthill->getScale() - 1);
            Informer informer;
            informer.anthillWasAttacked(anthill, anthill->storage->getX(), anthill->storage->getY(), field, this);
        }
    }
}
