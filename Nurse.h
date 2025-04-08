//#pragma once

#include "Ant.h"
#ifndef NURSE_H
#define NURSE_H


class Nurse :Ant {
public:
	Nurse();
	//virtual ~Nurse();
	virtual void work() override { ; }

	using Ant::moveRight;
	using Ant::moveLeft;
	using Ant::moveUp;
	using Ant::moveDown;
private:
};

#endif NURSE_H