#include "Dead.h"

#include "Child.h"
#include "Collecter.h"
#include "Cleaner.h"
#include "Builder.h"
#include "Soldier.h"
#include "Nurse.h"

Dead::Dead(vector<Child *> &list, Child *&child)
{
    cout << "child died" << endl;
    this->setRole("dead");
    this->setPosX(child->getPosX());
    this->setPosY(child->getPosY());
    for(int i = 0; i < list.size(); ++i) {
        if(list[i] == child) {
            delete list[i];
            list.erase(list.begin()+i);
            break;
        }
    }
}

Dead::Dead(vector<Collecter *> &list, Collecter *&collector)
{
    cout << "collector died" << endl;
    this->setRole("dead");
    this->setPosX(collector->getPosX());
    this->setPosY(collector->getPosY());
    for(int i = 0; i < list.size(); ++i) {
        if(list[i] == collector) {
            delete list[i];
            list.erase(list.begin()+i);
            break;
        }
    }
}

Dead::Dead(vector<Cleaner *> &list, Cleaner *&cleaner)
{
    cout << "cleaner died" << endl;
    this->setRole("dead");
    this->setPosX(cleaner->getPosX());
    this->setPosY(cleaner->getPosY());
    for(int i = 0; i < list.size(); ++i) {
        if(list[i] == cleaner) {
            delete list[i];
            list.erase(list.begin()+i);
            break;
        }
    }
}

Dead::Dead(vector<Builder *> &list, Builder *&builder)
{
    cout << "build died" << endl;
    this->setRole("dead");
    this->setPosX(builder->getPosX());
    this->setPosY(builder->getPosY());
    for(int i = 0; i < list.size(); ++i) {
        if(list[i] == builder) {
            delete list[i];
            list.erase(list.begin()+i);
            break;
        }
    }
}

Dead::Dead(vector<Soldier *> &list, Soldier *&soldier)
{
    cout << "soldier died" << endl;
    this->setRole("dead");
    this->setPosX(soldier->getPosX());
    this->setPosY(soldier->getPosY());
    for(int i = 0; i < list.size(); ++i) {
        if(list[i] == soldier) {
            delete list[i];
            list.erase(list.begin()+i);
            break;
        }
    }
}

Dead::Dead(vector<Nurse *> &list, Nurse *&nurse)
{
    cout << "nurse died" << endl;
    this->setRole("dead");
    this->setPosX(nurse->getPosX());
    this->setPosY(nurse->getPosY());
    for(int i = 0; i < list.size(); ++i) {
        if(list[i] == nurse) {
            delete list[i];
            list.erase(list.begin()+i);
            break;
        }
    }
}
