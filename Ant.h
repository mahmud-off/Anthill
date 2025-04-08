//#pragma once

#include <iostream>

using namespace std;

#ifndef ANT_H
#define ANT_H

class Ant {
public:
	Ant();
	virtual ~Ant();

	//functions for collecters and builders
	pair<int, int> findNearestPoint(int x1, int y1, vector<pair<int, int>> v); // nearest point with food or materials from ant
	vector<pair<int, int>> A_StarSearch(pair<int, int> start, pair<int, int> end); // shortest path from start to end

	//access
	int getAge()const { return age; }
	string getRole()const { return role; }
	int getHealth()const { return health; }
	int getPosX() { return this->x; }
	int getPosY() { return this->y; }

	//setters
	void setAge(int n){ age = n; }
	void setRole(string n) { role = n; }
	void setHealth(int n) { health = n; }
	void setPosX(int x) { this->x = x; }
	void setPosY(int y) { this->y = y; }

	//functions
	virtual void work() = 0;

	// moving
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();

private:
	int age;
	string role;
	int health; // 0 - 100
	int weight; // ������� ����� �������
	int x; // coordinates
	int y;
};

#endif ANT_H