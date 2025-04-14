#ifndef BUILDER_H
#define BUILDER_H

#include "Ant.h"
#include "Collecter.h"


class Builder : public Ant {
public:
	Builder();

	Builder(vector<Collecter*>& list, Collecter* &collecter);

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