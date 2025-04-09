//#pragma once
#include "Ant.h"
#include "Field.h"
#ifndef BUILDER_H
#define BUILDER_H

class Builder : public Ant {
public:
	Builder();
	Builder(int weight);
	virtual ~Builder();
	Builder(vector<Ant*>& list, Ant* &collecter);
	virtual void work(Field field) override { collectMaterials(field); }


	void collectMaterials(Field field);
	void helpToCollectMaterial(int x, int y, Field field); // coordinates

	using Ant::moveRight;
	using Ant::moveLeft;
	using Ant::moveUp;
	using Ant::moveDown;
	using Ant::setPosX;
	using Ant::setPosY;

private:
};

#endif BUILDER_H