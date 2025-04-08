﻿#include <iostream>
#include "AntHill.h"
#include "Ant.h"
#include "builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collecter.h"
#include "Nurse.h"
#include "Soldier.h"
#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <time.h>

#define ANTHILL_DESTROYING 5

using std::cout;
using std::cin;
using std::string;
using namespace std;

Anthill::Anthill()
{
	cout << "Enter a scale: ";
	cin >> scale;
	cout << "Enter a food count: ";
	cin >> foodCount;
	cout << "Enter a children count: ";
	cin >> childrenConunt;
	cout << "Enter a builder count: ";
	cin >> builderCount;
	cout << "Enter a cleaner count: ";
	cin >> cleanerConut;
	cout << "Enter a collecter count: ";
	cin >> collecterCount;
	cout << "Enter a nurse count: ";
	cin >> nurseCount;
	cout << "Enter a soldier count: ";
	cin >> soldierCount;

	
	childList = vector<Child>(childrenConunt);
	builderList = vector<Builder> (builderCount);
	cleanerList = vector<Cleaner> (cleanerConut);
	collecterList = vector<Collecter> (collecterCount);
	nurseList = vector<Nurse> (nurseCount);
	soldierList = vector<Soldier> (soldierCount);

	antCount = childrenConunt + builderCount + cleanerConut + collecterCount + nurseCount + soldierCount;

}

void childMakeMove(Child ant) {
	srand(time(0));
	int numberOfMovement = rand() % 4;
	if (numberOfMovement == 0) {
		ant.moveRight();
	}
	else if (numberOfMovement == 1) {
		ant.moveLeft();
	}
	else if (numberOfMovement == 2) {
		ant.moveUp();
	}
	else if (numberOfMovement == 3) {
		ant.moveDown();
	}
}

void builderMakeMove(Builder ant) {
	srand(time(0));
	int numberOfMovement = rand() % 4;
	if (numberOfMovement == 0) {
		ant.moveRight();
	}
	else if (numberOfMovement == 1) {
		ant.moveLeft();
	}
	else if (numberOfMovement == 2) {
		ant.moveUp();
	}
	else if (numberOfMovement == 3) {
		ant.moveDown();
	}
}

void cleanerMakeMove(Cleaner ant) {
	srand(time(0));
	int numberOfMovement = rand() % 4;
	if (numberOfMovement == 0) {
		ant.moveRight();
	}
	else if (numberOfMovement == 1) {
		ant.moveLeft();
	}
	else if (numberOfMovement == 2) {
		ant.moveUp();
	}
	else if (numberOfMovement == 3) {
		ant.moveDown();
	}
}

void collecterMakeMove(Collecter ant) {
	srand(time(0));
	int numberOfMovement = rand() % 4;
	if (numberOfMovement == 0) {
		ant.moveRight();
	}
	else if (numberOfMovement == 1) {
		ant.moveLeft();
	}
	else if (numberOfMovement == 2) {
		ant.moveUp();
	}
	else if (numberOfMovement == 3) {
		ant.moveDown();
	}
}

void nurseMakeMove(Nurse ant) {
	srand(time(0));
	int numberOfMovement = rand() % 4;
	if (numberOfMovement == 0) {
		ant.moveRight();
	}
	else if (numberOfMovement == 1) {
		ant.moveLeft();
	}
	else if (numberOfMovement == 2) {
		ant.moveUp();
	}
	else if (numberOfMovement == 3) {
		ant.moveDown();
	}
}

void soldierMakeMove(Soldier ant) {
	srand(time(0));
	int numberOfMovement = rand() % 4;
	if (numberOfMovement == 0) {
		ant.moveRight();
	}
	else if (numberOfMovement == 1) {
		ant.moveLeft();
	}
	else if (numberOfMovement == 2) {
		ant.moveUp();
	}
	else if (numberOfMovement == 3) {
		ant.moveDown();
	}
}

void Anthill::antsDailyEat() {
	for (auto ant : childList) {
		this->foodCount -= ant.constEating;
	}
	for (auto ant : builderList) {
		this->foodCount -= ant.constEating;
	}
	for (auto ant : cleanerList) {
		this->foodCount -= ant.constEating;
	}
	for (auto ant : collecterList) {
		this->foodCount -= ant.constEating;
	}
	for (auto ant : nurseList) {
		this->foodCount -= ant.constEating;
	}
	for (auto ant : soldierList) {
		this->foodCount -= ant.constEating;
	}
}

void Anthill::anthillDestroying() {
	this->scale -= ANTHILL_DESTROYING;
}


void Anthill::dailyResourceExpenditure() {
	this->antsDailyEat();
	this->anthillDestroying();
}

