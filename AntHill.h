//#pragma once
#include "Ant.h"
#include "builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collecter.h"
#include "Nurse.h"
#include "Soldier.h"
#include <iostream>
#include <vector>

#define RoleCount 6;

using std::cout;
using std::cin;
using std::string;

#ifndef ANTHILL_H
#define ANTHILL_H


class Anthill {
public:
	Anthill();
	void makeMove();
	void dailyResourceExpenditure(); // ежедневаня трата ресурсов муравейника, состоит из трат еды и ежедневного осыпания муравейника

private:
	// resources spending
	void antsDailyEat();
	void anthillDestroying(); // осыпь муравейника

	int scale;
	int childrenConunt;
	int builderCount;
	int cleanerConut;
	int collecterCount;
	int nurseCount;
	int soldierCount;
	int foodCount;
	int antCount;

	vector<Child> childList;
	vector<Builder> builderList;
	vector<Cleaner> cleanerList;
	vector<Collecter> collecterList;
	vector<Nurse> nurseList;
	vector<Soldier> soldierList;

};

#endif ANTHILL_H