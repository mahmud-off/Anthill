//#pragma once

#include "Ant.h"
#ifndef NURSE_H
#define NURSE_H


class Nurse :Ant {
public:
	Nurse();
	//virtual ~Nurse();
	virtual void work() override { ; }

	//кормит личинок (всех тех, у кого нет роли)
	//спасает их, если нападение.
private:
};

#endif NURSE_H