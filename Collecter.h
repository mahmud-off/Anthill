//#pragma once
#include "Ant.h"
#ifndef COLLECTER_H
#define COLLECTER_H

class Collecter :Ant {
public:
	Collecter();
	//virtual ~Collecter();
	virtual void work() override { ; }

	using Ant::moveRight;
	using Ant::moveLeft;
	using Ant::moveUp;
	using Ant::moveDown;
private:
};

#endif COLLECTER_H