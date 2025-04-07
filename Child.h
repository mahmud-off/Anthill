//#pragma once

#include "Ant.h"
#ifndef CHILD_H
#define CHILD_H

class Child :Ant {
public:
	Child();
	//virtual ~Child();
	virtual void work() override { ; }
	string getRole() { return Ant::getRole(); }
private:
};

#endif CHILD_H