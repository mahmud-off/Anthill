#include "Informer.h"

void Informer::callToGetHelpToCollectFood(int x, int y, Field field) {
    for (int i = 0; i < this->collectersInformerSubscribers.size(); i++) {
        Collecter *curCollecter = collectersInformerSubscribers[i];
        curCollecter->helpToCollectFood(x, y, field);
    }
    // collecting food together
    field.field[x][y] = ""; // already no food in this point
    field.updateFoodCoordinatesList();
}

void Informer::callToGetHelpToCollectMaterials(int x, int y, Field field) {
    for (int i = 0; i < this->buildersInformerSubscribers.size(); i++) {
        Builder *curBuilder = buildersInformerSubscribers[i];
        curBuilder->helpToCollectMaterial(x, y, field);
    }
    // collecting materials together
    field.field[x][y] = ""; // already no food in this point
    field.updateMaterialsCoordinatesList();
}

void Informer::callToGetHelpToFightOpponent(int x, int y, Field field) {
    for (int i = 0; i < this->soldiersInformerSubscribers.size(); i++) {
        Soldier *curSoldier = soldiersInformerSubscribers[i];
        curSoldier->helpToFightOpponent(x, y, field);
    }
}
