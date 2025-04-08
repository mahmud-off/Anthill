//#pragma once

#include <iostream>

using namespace std;

#ifndef ANT_H
#define ANT_H

class Ant {
public:
	Ant();
	virtual ~Ant();

	//access
	int getAge()const { return age; }
	string getRole()const { return role; }
	int getHealth()const { return health; }

	//setters
	void setAge(int n){ age = n; }
	void setRole(string n) { role = n; }
	void setHealth(int n) { health = n; }

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
	int posX;
	int posY;
};

#endif ANT_H