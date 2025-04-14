#include <iostream>
#include "AntHill.h"
#include "Field.h"
#include "Informer.h"

#define FIELD_HEIGHT 250
#define FIELD_WIDTH 250

int main() {
    Informer informer;
    Field field(FIELD_WIDTH, FIELD_HEIGHT);
    Anthill anthill(100, FIELD_WIDTH / 2, FIELD_HEIGHT / 2);
    anthill.generateAnts(FIELD_WIDTH / 2, FIELD_HEIGHT / 2, &informer);
    field.ResourceSpawn();

    //test
    // Example the rolling growth
    // cout << "\nCollecter size before -> " << anthill.collecterList.size()<<"\n";
    // cout << "Builder list before -> " << anthill.builderList.size()<<"\n\n";
    // Builder* pop = new Builder(anthill.collecterList,  anthill.collecterList[0]);
    // anthill.builderList.push_back(pop);
    // cout << "\nCollecter size after -> " << anthill.collecterList.size()<<"\n";
    // cout << "Builder list after -> " << anthill.builderList.size()<<"\n\n";


    // test foodCoordinates
    // for (int i = 0; i < field.foodCoordinates.size(); i++) {
    //     auto cur = field.foodCoordinates[i];
    //     cout << cur.first << " " << cur.second.first << " " << cur.second.second << "\n";
    // }

    // test collecters work
    // cout << anthill.collecterList[1]->getWeight() << "\n";
    // anthill.collecterList[1]->work(field);

    // test builders and builder informers work
    // cout << anthill.builderList[1]->getWeight() << "\n";
    // anthill.builderList[1]->work(field);
    // //Enemies' test
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

    // test informer
    // cout << anthill.builderList.size() << " " << informer.getBuildersInformerSubscribers().size() << "\n";
    // cout << anthill.collecterList.size() << " " << informer.getCollectersInformerSubscribers().size() << "\n";
    // cout << anthill.nurseList.size() << " " << informer.getNursesInformerSubscribers().size() << "\n";
    // cout << anthill.soldierList.size() << " " << informer.getSoldiersInformerSubscribers().size() << "\n";
}
