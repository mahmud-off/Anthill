#ifndef INFORMER_H
#define INFORMER_H

#include <vector>

// #include "Builder.h"
// #include "Collecter.h"
// #include "Nurse.h"
// #include "Soldier.h"

class Builder;
class Collecter;
class Nurse;
class Soldier;
class Field;
class Enemy;
class Ant;

using namespace std;

class Informer {
public:
    void callToGetHelpToCollectMaterials(Builder *builderWhoNeedHelp, int x, int y, Field *field, int materialWeight);
    void callToGetHelpToCollectFood(Collecter *collecterWhoNeedHelp, int x, int y, Field *field, int foodWeight); // coordinates where was the food
    void callToGetHelpFromSoldier(Ant *antWhoWasAttacked, int x, int y, Field *field, Enemy *enemyWhoAttackedAnt);

    // informers for all ants
    void anthillWasAttacked(); // if opponents attack anthill

    //lists of subscribers
    void addToBuildersInformerSubscribers(Builder*);
    void addToCollectorsInformerSubscribers(Collecter*);
    void addToSoldiersInformerSubscribers(Soldier*);
    void addToNursesInformerSubscribers(Nurse*);
    void addToAllAntsInformerSubscribers(Ant*);

    // getters for testing
    vector<Collecter*> getCollectersInformerSubscribers() { return collectersInformerSubscribers; }
    vector<Builder*> getBuildersInformerSubscribers() { return buildersInformerSubscribers; }
    vector<Soldier*> getSoldiersInformerSubscribers() { return soldiersInformerSubscribers; }
    vector<Nurse*> getNursesInformerSubscribers() { return nursesInformerSubscribers; }
    vector<Ant*> getAllAntsInformerSubscribers() { return allAntsInformerSubscribers; }

private:
    vector<Collecter*> collectersInformerSubscribers;
    vector<Builder*> buildersInformerSubscribers;
    vector<Soldier*> soldiersInformerSubscribers;
    vector<Nurse*> nursesInformerSubscribers;
    vector<Ant*> allAntsInformerSubscribers;
};

#endif
