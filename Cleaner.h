//#pragma once
#include "Ant.h"
#ifndef CLEANER_H
#define CLEANER_H

class Cleaner :Ant {
public:
	Cleaner();
	//virtual ~Cleaner();
	virtual void work() override { ; }
private:
};

#endif CLEANER_H