#ifndef CLEANER_H
#define CLEANER_H

#include "Ant.h"
// #include "Child.h"
// #include "Field.h"

class Child;
class Field;
class Anthill;
class Dead;


class Cleaner : public Ant {
public:

	
	Cleaner();

	Cleaner(vector<Child*>& list, Child* &child);

	void initCleaner();

	// void cleanDeadAnts(Field field);
	// pair<int, int> getPositionOfNearestDeadAnt(Field field);
	// bool canFindDeadAnts(Field field);
	// double distance(int x1, int y1, int x2, int y2);

	virtual ~Cleaner();
	Cleaner(vector<Ant*>& list, Ant* &child);
	void work(Field* field, Anthill* anthill) override;
	void remove_dead(Field* field, Anthill* anthill);

	using Ant::setPosX;
	using Ant::setPosY;

private:
	int roView = 100; // range of view
};

#endif