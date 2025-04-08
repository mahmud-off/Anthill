//#pragma once
#include "Ant.h"
#include "Field.h"
#ifndef BUILDER_H
#define BUILDER_H

class Builder :Ant {
public:
	int constEating = 5;
	Builder();
	//virtual ~Builder();
	virtual void work() override { ; }


	void collectMaterials(Field field);
	void helpToCollectMaterial(int x, int y); // coordinates

	using Ant::moveRight;
	using Ant::moveLeft;
	using Ant::moveUp;
	using Ant::moveDown;
	using Ant::setPosX;
	using Ant::setPosY;

private:
};

#endif BUILDER_H