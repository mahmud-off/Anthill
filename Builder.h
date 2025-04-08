//#pragma once
#include "Ant.h"
#ifndef BUILDER_H
#define BUILDER_H

class Builder : public Ant {
public:
	Builder();

	Builder(vector<Ant*>& list, Ant* &collecter);

	virtual ~Builder();
	virtual void work() override { ; }



	using Ant::moveRight;
	using Ant::moveLeft;
	using Ant::moveUp;
	using Ant::moveDown;
	using Ant::setPosX;
	using Ant::setPosY;

private:
};

#endif BUILDER_H