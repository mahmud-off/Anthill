#include <iostream>
#include "AntHill.h"
#include "Field.h"
//#include "Ant.h"

#define FIELD_HEIGHT 250
#define FIELD_WIDTH 250

int main() {
    Field field(FIELD_WIDTH, FIELD_HEIGHT);
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



    // test foodCoordinates
    // for (int i = 0; i < field.foodCoordinates.size(); i++) {
    //     auto cur = field.foodCoordinates[i];
    //     cout << cur.first << " " << cur.second.first << " " << cur.second.second << "\n";
    // }

    // test collecters work
    cout << anthill.collecterList[1]->getWeight() << "\n";
    anthill.collecterList[2]->work(field);

    // test builders work
    //Enemies' test
    cout << "\nEnemies count: " <<field.enemies.size() << "\n";
    field.createEnemy();
    cout << "Enemies count: " <<field.enemies.size() << "\n";
    field.deleteEnemy(field.enemies[0]);
    cout << "Enemies count: " <<field.enemies.size() << "\n";


}
