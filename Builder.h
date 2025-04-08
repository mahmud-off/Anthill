//#pragma once
#include "Ant.h"
#ifndef BUILDER_H
#define BUILDER_H

class Builder :Ant {
public:
	Builder();
	//virtual ~Builder();
	virtual void work() override { ; }



	using Ant::moveRight;
	using Ant::moveLeft;
	using Ant::moveUp;
	using Ant::moveDown;

private:
};

#endif BUILDER_H