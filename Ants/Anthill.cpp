#include <iostream>
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

using std::cout;
using std::cin;
using std::string;

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

	
	childList = new vector<Child>(childrenConunt);
	builderList = new vector<Builder> (builderCount);
	cleanerList = new vector<Cleaner> (cleanerConut);
	collecterList = new vector<Collecter> (collecterCount);
	nurseList = new vector<Nurse> (nurseCount);
	soldierList = new vector<Soldier> (soldierCount);

	antCount = childrenConunt + builderCount + cleanerConut + collecterCount + nurseCount + soldierCount;

}
