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
    cout << "\nCollecter size before -> " << anthill.collecterList.size()<<"\n";
    cout << "Builder list before -> " << anthill.builderList.size()<<"\n\n";
    Builder* pop = new Builder(anthill.collecterList,  anthill.collecterList[0]);
    anthill.builderList.push_back(pop);
    cout << "\nCollecter size after -> " << anthill.collecterList.size()<<"\n";
    cout << "Builder list after -> " << anthill.builderList.size()<<"\n\n";



    // test
    Ant* c = anthill.collecterList[0];
    pair<int, int> p = c->findNearestPoint(c->getPosX(), c->getPosY(), field.foodCoordinates);
    vector<pair<int, int>> paths = c->A_StarSearch({c->getPosX(), c->getPosY()}, p);
    for (auto x : paths) {
        cout << x.first << " " << x.second << "\n";
    }

    //Enemies' test
    cout << "\nEnemies count: " <<field.enemies.size() << "\n";
    field.createEnemy();
    cout << "Enemies count: " <<field.enemies.size() << "\n";
    field.deleteEnemy(field.enemies[0]);
    cout << "Enemies count: " <<field.enemies.size() << "\n";


}
