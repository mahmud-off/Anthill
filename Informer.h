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
    void callToGetHelpToFightOpponent(int x, int y);

    // informers for all ants
    void anthillWasAttacked(); // if opponents attack anthill
private:
    vector<Collecter*> collectersInformerSubscribers;
    vector<Builder*> buildersInformerSubscribers;
    vector<Soldier*> soldiersInformerSubscribers;
    vector<Nurse*> nursesInformerSubscribers;
    vector<Ant*> allAntsInformerSubscribers;
};

#endif //INFORMER_H
