#ifndef DEAD_H
#define DEAD_H
#include "Ant.h"

class Child;
class Collecter;
class Cleaner;
class Builder;
class Soldier;
class Nurse;

class Dead: public Ant {
public:
    Dead(vector<Child*>& list, Child* &child);
    Dead(vector<Collecter*>& list, Collecter* &collector);
    Dead(vector<Cleaner*>& list, Cleaner* &cleaner);
    Dead(vector<Builder*>& list, Builder* &builder);
    Dead(vector<Soldier*>& list, Soldier* &soldier);
    Dead(vector<Nurse*>& list, Nurse* &nurse);

    virtual void work(Field *field) override { cout << "bam-bam" << "\n"; }

private:
};

#endif //DEAD_H
