#include "Informer.h"

#include "builder.h"
#include "Collecter.h"
#include "Enemy.h"
#include "Field.h"
#include "Soldier.h"

void Informer::callToGetHelpToCollectFood(Collecter *collecterWhoNeedHelp, int x, int y, Field *field, int foodWeight) {
    int antWeight = collecterWhoNeedHelp->getWeight();
    int summaryWeight = antWeight;
    vector<Collecter *> collectersCameToHelp; // collecters who were free and came to help
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
        } else if (curCollecter->getStatus() == "busy") {
            continue;
        }
    }
    // collecting food together
    field->field[x][y] = ""; // already no food in this point
    field->updateFoodCoordinatesList();
}

void Informer::callToGetHelpToCollectMaterials(Builder *builderWhoNeedHelp, int x, int y, Field *field,
                                               int materialWeight) {
    int antWeight = builderWhoNeedHelp->getWeight();
    int summaryWeight = antWeight;
    vector<Builder *> buildersCameToHelp; // builders who were free and came to help
    buildersCameToHelp.push_back(builderWhoNeedHelp);
    for (int i = 0; i < this->buildersInformerSubscribers.size(); i++) {
        Builder *curBuilder = buildersInformerSubscribers[i];
        if (curBuilder->getStatus() == "free") {
            curBuilder->changeStatus();
            buildersCameToHelp.push_back(curBuilder);
            curBuilder->helpToCollectMaterial(x, y, field);
            summaryWeight += curBuilder->getWeight();
            if (summaryWeight >= materialWeight) {
                // no more builders needed
                // all builders go home
                for (int i = 0; i < buildersCameToHelp.size(); i++) {
                    auto currentBuilder = buildersCameToHelp[i];
                    // go home
                }
                // set status free for all of them
                for (int i = 0; i < buildersCameToHelp.size(); i++) {
                    auto currentBuilder = buildersCameToHelp[i];
                    currentBuilder->changeStatus();
                }
            }
        } else if (curBuilder->getStatus() == "busy") {
            continue;
        }
    }
    // collecting materials together
    field->field[x][y] = ""; // already no food in this point
    field->updateMaterialsCoordinatesList();
}

void Informer::callToGetHelpFromSoldier(Ant *antWhoWasAttacked, int x, int y, Field *field,
                                        Enemy *enemyWhoAttackedAnt) {
    int i = 0; // будет затираться при новом вайле
    while (enemyWhoAttackedAnt->getHealth() > 0) { // help until enemy die
        while (i < this->soldiersInformerSubscribers.size()) {
            auto curSoldier = this->soldiersInformerSubscribers[i];
            if (curSoldier->getStatus() == "free") {
                curSoldier->changeStatus(); // change status to busy
                curSoldier->setWorkStatus("help_moving");
                curSoldier->setEnemy(enemyWhoAttackedAnt);

                curSoldier->setEndPoint({antWhoWasAttacked->getPosX(), antWhoWasAttacked->getPosY()});

                curSoldier->fightEnemy(field);

                //curSoldier->helpToFightEnemy(enemyWhoAttackedAnt, field);
                //curSoldier->changeStatus(); // change status to free;
            } else if (curSoldier->status == "busy") {
                continue;
            }
            i++;
        }
    }
}

void Informer::anthillWasAttacked(Anthill *anthill, int x, int y, Field *field, Enemy *enemyWhoAttackedAnthill) {
    int i = 0;
    while (enemyWhoAttackedAnthill->getHealth() > 0) {// help until enemy die
        while (i < this->soldiersInformerSubscribers.size()) {
            auto curSoldier = this->soldiersInformerSubscribers[i];
            if (curSoldier->getStatus() == "free") {
                curSoldier->changeStatus(); // change status to busy
                curSoldier->setWorkStatus("help_moving");
                curSoldier->setEnemy(enemyWhoAttackedAnthill);

                curSoldier->setEndPoint({x, y});

                curSoldier->fightEnemy(field);
            } else if (curSoldier->status == "busy") {
                continue;
            }
            i++;
        }
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
