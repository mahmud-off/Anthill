#ifndef CLEANER_H
#define CLEANER_H
#include "Ant.h"
#include "Child.h"


class Cleaner : public Ant {
public:

	Cleaner();

	Cleaner(vector<Child*>& list, Child* &child);

	void cleanDeadAnts(Field field);
	pair<int, int> getPositionOfNearestDeadAnt(Field field);
	bool canFindDeadAnts(Field field);
	double distance(int x1, int y1, int x2, int y2);

	virtual ~Cleaner();
	Cleaner(vector<Ant*>& list, Ant* &child);
	virtual void work(Field field) override { cleanDeadAnts(field); }


	using Ant::moveRight;
	using Ant::moveLeft;
	using Ant::moveUp;
	using Ant::moveDown;
	using Ant::setPosX;
	using Ant::setPosY;
	using Ant::A_StarSearch;

private:
	int roView = 100; // range of view
};

#endif CLEANER_H