#include <iostream>
#include "AntHill.h"
#include "Field.h"


#define FIELD_HEIGHT 250
#define FIELD_WIDTH 250

int main() {
    Field field(FIELD_HEIGHT, FIELD_WIDTH);
    Anthill anthill(100, FIELD_HEIGHT / 2, FIELD_WIDTH / 2);
    anthill.generateAnts(FIELD_HEIGHT / 2, FIELD_WIDTH / 2);
    field.ResourceSpawn();

    //test
    // Example the rolling growth
    cout << "\nCollecter size before -> " << anthill.getCollecterList().size()<<"\n";
    cout << "Builder list before -> " << anthill.getBuilderList().size()<<"\n\n";
    Builder* pop = new Builder(anthill.getCollecterList(),  anthill.getCollecterList()[0]);
    anthill.getBuilderList().push_back(pop);
    cout << "\nCollecter size after -> " << anthill.getCollecterList().size()<<"\n";
    cout << "Builder list after -> " << anthill.getBuilderList().size()<<"\n\n";



    // test
    Ant* c = anthill.getCollecterList()[0];
    pair<int, int> p = c->findNearestPoint(c->getPosX(), c->getPosY(), field.foodCoordinates);
    vector<pair<int, int>> paths = c->A_StarSearch({c->getPosX(), c->getPosY()}, p);
    for (auto x : paths) {
        cout << x.first << " " << x.second << "\n";
    }

    //Enemies' test
    cout << "\nEnemies count: " <<field.getEnemiesList().size() << "\n";
    field.createEnemy();
    cout << "Enemies count: " <<field.getEnemiesList().size() << "\n";

    cout << "Ant nearly --> " << field.getEnemiesList()[0]->findAnts(anthill) << "\n";
    cout << "Ant nearly --> " << field.getEnemiesList()[0]->PositionOfNearestAnt(anthill).first << " " << field.getEnemiesList()[0]->PositionOfNearestAnt(anthill).second << "\n";

    cout << "Food nearly --> " << field.getEnemiesList()[0]->findFood(field.foodCoordinates) << "\n";
    cout << "Food nearly --> " << field.getEnemiesList()[0]->PositionOfNearestFood(field.foodCoordinates).first << " " << field.getEnemiesList()[0]->PositionOfNearestFood(field.foodCoordinates).second<< "\n";

    //movement to food
    //field.getEnemiesList()[0]->moveByCoordinates(field.getEnemiesList()[0]->PositionOfNearestFood(field.foodCoordinates));
    field.getEnemiesList()[0]->moveToRandomPointInROView(field.getHeight(), field.getWidth());
    field.deleteEnemy(field.getEnemiesList()[0]);
    cout << "Enemies count: " <<field.getEnemiesList().size() << "\n";


}
