﻿    #include <iostream>
#include "AntHill.h"
#include "Ant.h"
#include "builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collecter.h"
#include "Nurse.h"
#include "Soldier.h"
#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <time.h>

#define ANTHILL_DESTROYING 5

using std::cout;
using std::cin;
using std::string;
using namespace std;

Anthill::Anthill(int scale, int x, int y) {
    this->scale = scale;
    this->x = x;
    this->y = y;
}

void Anthill::generateAnts(int x, int y) {
    this->foodCount = 0.7 * this->scale;
    this->antCount = 0.3 * this->scale;
    this->childrenCount = 0.2 * this->antCount;
    this->builderCount = 0.2 * this->antCount;
    this->cleanerCount = 0.1 * this->antCount;
    this->collecterCount = 0.2 * this->antCount;
    this->nurseCount = 0.1 * this->antCount;
    this->soldierCount = 0.2 * this->antCount;

    for (int i = 0; i < childrenCount; i++) {
        childList.push_back(new Child());
        childList[i]->setPosX(x);
        childList[i]->setPosY(y);
    }

    for (int i = 0; i < builderCount; i++) {
        builderList.push_back(new Builder());
        builderList[i]->setPosX(x);
        builderList[i]->setPosY(y);
    }

    for (int i = 0; i < cleanerCount; i++) {
        cleanerList.push_back(new Cleaner());
        cleanerList[i]->setPosX(x);
        cleanerList[i]->setPosY(y);
    }


    for (int i = 0; i < collecterCount; i++) {
        collecterList.push_back(new Collecter());
        collecterList[i]->setPosX(x);
        collecterList[i]->setPosY(y);
    }


    for (int i = 0; i < nurseCount; i++) {
        nurseList.push_back(new Nurse());
        nurseList[i]->setPosX(x);
        nurseList[i]->setPosY(y);
    }


    for (int i = 0; i < soldierCount; i++) {
        soldierList.push_back(new Soldier());
        soldierList[i]->setPosX(x);
        soldierList[i]->setPosY(y);
    }
}


void childMakeMove(Child ant) {
    srand(time(0));
    int numberOfMovement = rand() % 4;
    if (numberOfMovement == 0) {
        ant.moveRight();
    } else if (numberOfMovement == 1) {
        ant.moveLeft();
    } else if (numberOfMovement == 2) {
        ant.moveUp();
    } else if (numberOfMovement == 3) {
        ant.moveDown();
    }
}

void builderMakeMove(Builder ant) {
    srand(time(0));
    int numberOfMovement = rand() % 4;
    if (numberOfMovement == 0) {
        ant.moveRight();
    } else if (numberOfMovement == 1) {
        ant.moveLeft();
    } else if (numberOfMovement == 2) {
        ant.moveUp();
    } else if (numberOfMovement == 3) {
        ant.moveDown();
    }
}

void cleanerMakeMove(Cleaner ant) {
    srand(time(0));
    int numberOfMovement = rand() % 4;
    if (numberOfMovement == 0) {
        ant.moveRight();
    } else if (numberOfMovement == 1) {
        ant.moveLeft();
    } else if (numberOfMovement == 2) {
        ant.moveUp();
    } else if (numberOfMovement == 3) {
        ant.moveDown();
    }
}

void collecterMakeMove(Collecter ant) {
    srand(time(0));
    int numberOfMovement = rand() % 4;
    if (numberOfMovement == 0) {
        ant.moveRight();
    } else if (numberOfMovement == 1) {
        ant.moveLeft();
    } else if (numberOfMovement == 2) {
        ant.moveUp();
    } else if (numberOfMovement == 3) {
        ant.moveDown();
    }
}

void nurseMakeMove(Nurse ant) {
    srand(time(0));
    int numberOfMovement = rand() % 4;
    if (numberOfMovement == 0) {
        ant.moveRight();
    } else if (numberOfMovement == 1) {
        ant.moveLeft();
    } else if (numberOfMovement == 2) {
        ant.moveUp();
    } else if (numberOfMovement == 3) {
        ant.moveDown();
    }
}

void soldierMakeMove(Soldier ant) {
    srand(time(0));
    int numberOfMovement = rand() % 4;
    if (numberOfMovement == 0) {
        ant.moveRight();
    } else if (numberOfMovement == 1) {
        ant.moveLeft();
    } else if (numberOfMovement == 2) {
        ant.moveUp();
    } else if (numberOfMovement == 3) {
        ant.moveDown();
    }
}

void Anthill::antsDailyEat() {
    for (auto ant: childList) {
        this->foodCount -= ant->constChildEating;
    }
    for (auto ant: builderList) {
        this->foodCount -= ant->constBuilderEating;
    }
    for (auto ant: cleanerList) {
        this->foodCount -= ant->constCleanerEating;
    }
    for (auto ant: collecterList) {
        this->foodCount -= ant->constCollecterEating;
    }
    for (auto ant: nurseList) {
        this->foodCount -= ant->constNurseEating;
    }
    for (auto ant: soldierList) {
        this->foodCount -= ant->constSoldierEating;
    }
}

void Anthill::anthillDestroying() {
    this->scale -= ANTHILL_DESTROYING;
}


void Anthill::dailyResourceExpenditure() {
    this->antsDailyEat();
    this->anthillDestroying();
}
