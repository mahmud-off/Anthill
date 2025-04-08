//#pragma once

#include "Ant.h"
#ifndef NURSE_H
#define NURSE_H


class Nurse : public Ant {
public:
	Nurse();

	Nurse(vector<Ant*>& list, Ant* &cleaner);
	virtual ~Nurse();
	virtual void work() override { ; }

	using Ant::moveRight;
	using Ant::moveLeft;
	using Ant::moveUp;
	using Ant::moveDown;
	using Ant::setPosX;
	using Ant::setPosY;

private:
};

#endif NURSE_H