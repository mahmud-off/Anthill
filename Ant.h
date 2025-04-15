#ifndef ANT_H
#define ANT_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <random>

// #include "Field.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

class Anthill;
class Field;

using namespace std;

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
	
	//access
	int getAge()const { return age; }
	string getRole()const { return role; }
	int getHealth()const { return health; }
	int getWeight()const {return weight; }
	int getPosX() { return this->x; }
	int getPosY() { return this->y; }
	int getWeight() { return weight; }
	int getPower() { return this->power; }
	string getStatus() { return this->status; }

	//setters
	void setAge(int n){ age = n; }
	void setRole(string n) { role = n; }
	void setHealth(int n) { health = n; }
	void setPosX(int x) { this->x = x; }
	void setPosY(int y) { this->y = y; }
	void setWeight(int weight) { this->weight = weight; }
	void setPower(int power) { this->power = power; }

	//functions
	virtual void work(Field *field) = 0;

	void updateMovement(Field* field, Anthill* anthil);

	// set new target
	void goHome(Anthill* anthill);
	void findFood(Field* field);
	void findMaterial(Field* field);
	void build();
	//void findDeadAnts();

	pair<int, int> randomAntHill(Anthill* anthill);
	void randomMoving(Field* filed);

	void printPosition()const{cout << "Ant's position : " << x << " " << y << "\n";}
	
	//compare
	bool operator==(const Ant* right)const;

	string status; // free / busy

private:
	int age;
	string role;
	int health; // 0 - 100
	int weight; // ������� ����� �������
	int x; // coordinates
	int y;
	int id;
	int power;
	sf::RectangleShape shape; // Заменяем спрайт на прямоугольник
	pair<int, int> endPoint;
};

#endif ANT_H