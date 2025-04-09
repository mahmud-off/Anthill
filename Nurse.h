//#pragma once

#include "Ant.h"
#ifndef NURSE_H
#define NURSE_H


class Nurse : public Ant {
public:
	Nurse();
	//virtual ~Nurse();
	virtual void work(Field field) override { ; }

	using Ant::moveRight;
	using Ant::moveLeft;
	using Ant::moveUp;
	using Ant::moveDown;
	using Ant::setPosX;
	using Ant::setPosY;

private:
};

#endif NURSE_H