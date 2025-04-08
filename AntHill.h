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
	vector<Collecter> collecterList; // for testing only

	Anthill(int scale, int x, int y);
	void generateAnts(int posX, int posY); // positions of ants in the beginning
	void dailyResourceExpenditure(); // ежедневаня трата ресурсов муравейника, состоит из трат еды и ежедневного осыпания муравейника

private:
	//coordinates
	int x;
	int y;


	// resources spending
	void antsDailyEat();
	void anthillDestroying(); // осыпь муравейника

	int foodCount;
	int scale;
	int childrenCount;
	int builderCount;
	int cleanerCount;
	int collecterCount;
	int nurseCount;
	int soldierCount;

	int antCount;

	vector<Child> childList;
	vector<Builder> builderList;
	vector<Cleaner> cleanerList;
	// vector<Collecter> collecterList;
	vector<Nurse> nurseList;
	vector<Soldier> soldierList;

};

#endif ANTHILL_H