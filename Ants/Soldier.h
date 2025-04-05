//#pragma once
#include "Ant.h"
#ifndef SOLDIER_H
#define SOLDIER_H

class Soldier :Ant {
public:
	Soldier() { ; }
	//virtual ~Soldier();
	virtual void work() override { ; }
private:
	int hit; // урон
};

#endif SOLDIER_H