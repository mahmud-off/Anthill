#include "Informer.h"

void Informer::callToGetHelpToCollectFood(Collecter *collecterWhoNeedHelp, int x, int y, Field field, int foodWeight) {
    int antWeight = collecterWhoNeedHelp->getWeight();
    int summaryWeight = antWeight;
    vector<Collecter*> collectersCameToHelp; // collecters who were free and came to help
    collectersCameToHelp.push_back(collecterWhoNeedHelp);
    for (int i = 0; i < this->collectersInformerSubscribers.size(); i++) {
        Collecter *curCollecter = collectersInformerSubscribers[i];
        if (curCollecter->getStatus() == "free") {
            curCollecter->changeStatus();
            collectersCameToHelp.push_back(curCollecter);
            curCollecter->helpToCollectFood(x, y, field);
            summaryWeight += curCollecter->getWeight();
            if (summaryWeight >= foodWeight) {
                // no more collecters needed
                // all collecters go home
                for (int i = 0; i < collectersCameToHelp.size(); i++) {
                    auto currentCollecter = collectersCameToHelp[i];
                    // go home
                }
                // set status free for all of them
                for (int i = 0; i < collectersCameToHelp.size(); i++) {
                    auto currentCollecter = collectersCameToHelp[i];
                    currentCollecter->changeStatus();
                }
            }
        }
        else if (curCollecter->getStatus() == "busy") {
            continue;
        }
    }
    // collecting food together
    field.field[x][y] = ""; // already no food in this point
    field.updateFoodCoordinatesList();
}

void Informer::callToGetHelpToCollectMaterials(int x, int y, Field field) {
    for (int i = 0; i < this->buildersInformerSubscribers.size(); i++) {
        Builder *curBuilder = buildersInformerSubscribers[i];
        curBuilder->helpToCollectMaterial(x, y, field);
        cout << i + 1 << " builders came to help\n";
    }
    // collecting materials together
    field.field[x][y] = ""; // already no food in this point
    field.updateMaterialsCoordinatesList();
}

void Informer::callToGetHelpToFightEnemy(int x, int y, Field field, Enemy enemy) {
    for (int i = 0; i < this->soldiersInformerSubscribers.size(); i++) {
        Soldier *curSoldier = soldiersInformerSubscribers[i];
        curSoldier->helpToFightEnemy(x, y, field);
        curSoldier->fightEnemy(enemy, field);
        if (enemy.getHealth() <= 0) {
            // if enemy died -> no need to help
            break;
        }
        // if enemy is alive -> next soldier goes to help
    }
}

void Informer::addToBuildersInformerSubscribers(Builder *newBuilder) {
    this->buildersInformerSubscribers.push_back(newBuilder);
}

void Informer::addToCollectorsInformerSubscribers(Collecter *newCollecter) {
    this->collectersInformerSubscribers.push_back(newCollecter);
}

void Informer::addToSoldiersInformerSubscribers(Soldier *newSoldier) {
    this->soldiersInformerSubscribers.push_back(newSoldier);
}

void Informer::addToNursesInformerSubscribers(Nurse *newNurse) {
    this->nursesInformerSubscribers.push_back(newNurse);
}

void Informer::addToAllAntsInformerSubscribers(Ant *newAnt) {
    this->allAntsInformerSubscribers.push_back(newAnt);
}



