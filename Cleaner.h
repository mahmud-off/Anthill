//#pragma once
#include "Ant.h"
#include "Child.h"
#ifndef CLEANER_H
#define CLEANER_H

class Cleaner : public Ant {
public:

	Cleaner();

	Cleaner(vector<Child*>& list, Child* &child);

	virtual ~Cleaner();
	Cleaner(vector<Ant*>& list, Ant* &child);
	virtual void work(Field field) override { ; }


	using Ant::moveRight;
	using Ant::moveLeft;
	using Ant::moveUp;
	using Ant::moveDown;
	using Ant::setPosX;
	using Ant::setPosY;

private:
};

#endif CLEANER_H