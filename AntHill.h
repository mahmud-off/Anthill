#ifndef ANTHILL_H
#define ANTHILL_H

//#include "Ant.h"
// #include "Builder.h"
// #include "Child.h"
// #include "Cleaner.h"
// #include "Collecter.h"
// #include "Nurse.h"
// #include "Soldier.h"
#include <iostream>
#include <vector>

class Builder;
class Child;
class Cleaner;
class Collecter;
class Nurse;
class Soldier;
class Dead;

#include "Informer.h"

#define RoleCount 6;
#define ENTER_COORDINATE_X 100
#define ENTER_COORDINATE_Y 100

using std::cout;
using std::cin;
using std::string;


class Anthill {
public:
    //getters
    vector<Collecter *> &getCollecterList() { return collecterList; }
    vector<Child *> &getChildList() { return childList; }
    vector<Cleaner *> &getCleanerList() { return cleanerList; }
    vector<Builder *> &getBuilderList() { return builderList; }
    vector<Nurse *> &getNurseList() { return nurseList; }
    vector<Soldier *> &getSoldierList() { return soldierList; }
    vector<Dead *> &getDeadAntsList(){return deadAntsList; }
    int getScale() { return this->scale; }
    int getMaterialsCount() { return this->materialsCount; }
    int getFoodCount() { return this->foodCount; }

    int getEnterPosX() { return this->enterX; }
    int getEnterPosY() { return this->enterY; }
    int getFoodStorage_X() { return this->foodStorage_X; }
    int getFoodStorage_Y() { return this->foodStorage_Y; }

    int getW() { return this->width; }
    int getH() { return this->height; }
    int getX() { return this->x; }
    int getY() { return this->y; }

    //setters
    void setScale(int scale) { this->scale = scale; }
    void setMaterialsCount(int materialsCount) { this->materialsCount = materialsCount; }
    void setFoodCount(int foodCount) { this->foodCount = foodCount; }

    Anthill (int scale, int x, int y);

    void generateAnts(int posX, int posY, Informer *informer); // positions of ants in the beginning
    void dailyResourceExpenditure();

    void increaseAnthill();

    void setxy(int x, int y, int w, int h);

    // ежедневаня трата ресурсов муравейника, состоит из трат еды и ежедневного осыпания муравейника

    //update

    void update();


private:
    //coordinates
    int x;
    int y;
    int enterX; // position of anthill enter
    int enterY;
    int foodStorage_X;
    int foodStorage_Y;
    int width;
    int height;


    // resources spending
    void antsDailyEat();

    void anthillDestroying(); // осыпь муравейника

    int foodCount;
    int materialsCount;
    int scale;
    int childrenCount;
    int builderCount;
    int cleanerCount;
    int collecterCount;
    int nurseCount;
    int soldierCount;

    int antCount;

    vector<Collecter *> collecterList;
    vector<Child *> childList;
    vector<Builder *> builderList;
    vector<Cleaner *> cleanerList;
    vector<Nurse *> nurseList;
    vector<Soldier *> soldierList;
    //dead ants
    vector<Dead*> deadAntsList;
};

#endif ANTHILL_H