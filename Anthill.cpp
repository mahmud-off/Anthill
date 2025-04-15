#include <iostream>
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

#include "Informer.h"

#define ANTHILL_DESTROYING 5

#define MAX_WEIGHT_FOR_COLLECTER 10
#define MIN_WEIGHT_FOR_COLLECTER 5

#define MAX_WEIGHT_FOR_BUILDER 15
#define MIN_WEIGHT_FOR_BUILDER 10

#define MAX_POWER_FOR_SOLDIERS 10
#define MIN_POWER_FOR_SOLDIERS 4

//Constants for change roles
//for children
#define CHILDREN_AGE 5
#define COLLECTOR_WEIGHT 3
//for collector
#define COLLECTOR_AGE 10
#define BUILDER_WEIGHT 3
//for cleaner
#define CLEANER_AGE 10

#define MATERIALS_NEEDED_TO_INCREASE_ANTHILL 10


using std::cout;
using std::cin;
using std::string;
using namespace std;

Anthill::Anthill(int scale, int x, int y) {
    this->scale = scale;
    this->x = x;
    this->y = y;
}

void Anthill::generateAnts(int x, int y, Informer *informer) {
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
        informer->addToAllAntsInformerSubscribers(childList.back());
        childList[i]->setPosX(x);
        childList[i]->setPosY(y);
    }

    for (int i = 0; i < builderCount; i++) {
        srand(time(0));
        int weight = rand() % (MAX_WEIGHT_FOR_BUILDER - MIN_WEIGHT_FOR_BUILDER + 1) + MIN_WEIGHT_FOR_BUILDER;
        builderList.push_back(new Builder(weight));
        builderList[i]->setPosX(x);
        builderList[i]->setPosY(y);
        informer->addToBuildersInformerSubscribers(builderList.back());
        informer->addToAllAntsInformerSubscribers(builderList.back());
    }

    for (int i = 0; i < cleanerCount; i++) {
        cleanerList.push_back(new Cleaner());
        cleanerList[i]->setPosX(x);
        cleanerList[i]->setPosY(y);
        informer->addToAllAntsInformerSubscribers(cleanerList.back());
    }


    for (int i = 0; i < collecterCount; i++) {
        srand(time(0));
        int weight = rand() % (MAX_WEIGHT_FOR_COLLECTER - MIN_WEIGHT_FOR_COLLECTER + 1) + MIN_WEIGHT_FOR_COLLECTER;
        collecterList.push_back(new Collecter(weight));
        collecterList[i]->setPosX(x);
        collecterList[i]->setPosY(y);
        informer->addToAllAntsInformerSubscribers(collecterList.back());
        informer->addToCollectorsInformerSubscribers(collecterList.back());
    }


    for (int i = 0; i < nurseCount; i++) {
        nurseList.push_back(new Nurse());
        nurseList[i]->setPosX(x);
        nurseList[i]->setPosY(y);
        informer->addToAllAntsInformerSubscribers(nurseList.back());
        informer->addToNursesInformerSubscribers(nurseList.back());
    }


    for (int i = 0; i < soldierCount; i++) {
        srand(time(0));
        int power = rand() % (MAX_POWER_FOR_SOLDIERS - MIN_POWER_FOR_SOLDIERS + 1) + MIN_POWER_FOR_SOLDIERS;
        soldierList.push_back(new Soldier(power));
        soldierList[i]->setPosX(x);
        soldierList[i]->setPosY(y);
        informer->addToAllAntsInformerSubscribers(soldierList.back());
        informer->addToSoldiersInformerSubscribers(soldierList.back());
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

void Anthill::increaseAnthill() {
    if (this->getMaterialsCount() >= MATERIALS_NEEDED_TO_INCREASE_ANTHILL) {
        for (int i = 0; i < this->getBuilderList().size(); i++) {
            auto currentBuilder = this->getBuilderList()[i];
            if (currentBuilder->getStatus() == "free") {
                currentBuilder->changeStatus(); // change status to busy
                currentBuilder->buildAnthill(this);
                currentBuilder->changeStatus(); // change status to free
            }
            else if (currentBuilder->getStatus() == "busy") {
                continue;
            }
        }
    }
}


void Anthill::update() {

    //1.Rolling shifts check
        //Check for each type of ant

    //Children check
    for(int i = 0; i < this->getChildList().size(); ++i) {
        Child* temp = getChildList()[i];
        if(temp->getAge() >= CHILDREN_AGE) {
            if(temp->getWeight() >= COLLECTOR_WEIGHT) {
                //change role to collector
                Collecter* newCollector = new Collecter(this->getChildList(), temp);
                this->getCollecterList().push_back(newCollector);
                continue;
            }
            if(temp->getHealth() <= 50) {
                //change role to cleaner
                Cleaner* newCleaner = new Cleaner(this->getChildList(), temp);
                this->getCleanerList().push_back(newCleaner);
                continue;
            }
            if(this->getCollecterList().size() < this->getCleanerList().size()) {
                //change role to collector
                Collecter* newCollector = new Collecter(this->getChildList(), temp);
                this->getCollecterList().push_back(newCollector);
            }
            else {
                //change role to cleaner
                Cleaner* newCleaner = new Cleaner(this->getChildList(), temp);
                this->getCleanerList().push_back(newCleaner);
            }
        }
    }

    //Collector check
    for(int i =0 ;i < this->getCollecterList().size(); ++i) {
        Collecter* temp = this->getCollecterList()[i];
        if(temp->getAge() >= COLLECTOR_AGE) {
            if(temp->getAge() < 50 || temp->getWeight() >= 3) {
                //change role to Builder
                Builder* newBuilder = new Builder(this->getCollecterList(), temp);
                this->getBuilderList().push_back(newBuilder);
            }
            if(this->getBuilderList().size() < this->getSoldierList().size()) {
                //change role to Builder
                Builder* newBuilder = new Builder(this->getCollecterList(), temp);
                this->getBuilderList().push_back(newBuilder);
            }
            else {
                //change role to Soldier
                Soldier* newSoldier = new Soldier(this->getCollecterList(), temp);
                this->getSoldierList().push_back(newSoldier);
            }
        }
    }

    //Cleaner check
    for(int i = 0; i < this->getCleanerList().size(); ++i) {
        Cleaner* temp = this->getCleanerList()[i];
        if(temp->getAge() >= CLEANER_AGE) {
            if(this->getNurseList().size() < this->getCleanerList().size()) {
                //change to Nurse
                Nurse* newNurse = new Nurse(this->getCleanerList(), temp);
                this->getNurseList().push_back(newNurse);
            }
        }
    }


    //2.Ordinary tasks for every ant
        // call virtual func work {...} for each ant

    //3.Recompute of AntHill's parameters
        //+- food count or others parameters

}
