//#pragma once
#include <vector>
#include <iostream>
#include "Field.h"

using namespace std;

#ifndef ANT_H
#define ANT_H

class Ant {
public:

	int constChildEating = 1;
	int constCleanerEating = 2;
	int constNurseEating = 2;
	int constSoldierEating = 5;
	int constBuilderEating = 5;
	int constCollecterEating = 3;

	Ant();
	virtual ~Ant();

	//functions for collecters and builders
	pair<int, pair<int, int>> findNearestPoint(int x1, int y1, vector<pair<int, pair<int, int>>> v); // nearest point with food or materials from ant
	vector<pair<int, int>> A_StarSearch(pair<int, int> start, pair<int, int> end, Field field); // shortest path from start to end

	//access
	int getAge()const { return age; }
	string getRole()const { return role; }
	int getHealth()const { return health; }
	int getWeight()const {return weight; }
	int getPosX() { return this->x; }
	int getPosY() { return this->y; }
	int getWeight() { return weight; }
	int getPower() { return this->power; }

	//setters
	void setAge(int n){ age = n; }
	void setRole(string n) { role = n; }
	void setHealth(int n) { health = n; }
	void setPosX(int x) { this->x = x; }
	void setPosY(int y) { this->y = y; }
	void setWeight(int weight) { this->weight = weight; }
	void setPower(int power) { this->power = power; }

	//functions
	virtual void work(Field field) = 0;

	// moving
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();

	//compare
	bool operator==(const Ant* right)const;

private:
	int age;
	string role;
	int health; // 0 - 100
	int weight; // ������� ����� �������
	int x; // coordinates
	int y;
	int id;
	int power;

};

#endif ANT_H