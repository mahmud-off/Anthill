#ifndef INFORMER_H
#define INFORMER_H

#include <vector>

#include "builder.h"
#include "Collecter.h"
#include "Nurse.h"
#include "Soldier.h"

using namespace std;

class Informer {
public:
    void callToGetHelpToCollectMaterials(int x, int y, Field field);
    void callToGetHelpToCollectFood(int x, int y, Field field); // coordinates where was the food
    void callToGetHelpToFightEnemy(int x, int y, Field field, Enemy enemy);

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

#endif //INFORMER_H
