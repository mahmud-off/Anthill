//#pragma once

#include "Ant.h"
#ifndef CHILD_H
#define CHILD_H

class Child :Ant {
public:
	int constEating = 1;
	Child();
	//virtual ~Child();
	virtual void work() override { ; }
	string getRole() { return Ant::getRole(); }

	using Ant::moveRight;
	using Ant::moveLeft;
	using Ant::moveUp;
	using Ant::moveDown;
private:
};

#endif CHILD_H