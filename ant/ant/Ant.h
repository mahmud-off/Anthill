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
<<<<<<< HEAD:ant/ant/Ant.h
class Food;
class Materials;
=======
class Field;
class Dead;
>>>>>>> ivan:Ant.h

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

<<<<<<< HEAD:ant/ant/Ant.h
	//functions for collecters and builders
	pair<int, pair<int, int>> findNearestPointCollecter(int x1, int y1, vector<Food *> v); // nearest point with food or materials from ant
	pair<int, pair<int, int>> findNearestPointBuilder(int x1, int y1, vector<Materials*> v); // nearest point with food or materials from ant
	vector<pair<int, int>> A_StarSearch(pair<int, int> start, pair<int, int> end, Field *field); // shortest path from start to end

=======
>>>>>>> ivan:Ant.h
	//access
	int getAge()const { return age; }
	string getRole()const { return role; }
	int getHealth()const { return health; }
	int getWeight()const {return weight; }
	int getPosX() { return this->x; }
	int getPosY() { return this->y; }
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
	void setStatus(string status) { this->status = status; }
	void setEndPoint(pair<int, int> point) { endPoint = point; }

	pair<int, pair<int, int>> findNearestPoint(int x1, int y1, vector<pair<int, pair<int, int>>> v); // nearest point with food or materials from ant
	
	//Base function for ant actions
	virtual void work(Field* field, Anthill* anthil) = 0;

	// Movent to point
	void updateMovement(Field* field, Anthill* anthil);

	// Определение координат
	void findFood(Field* field);
	void findMaterial(Field* field);
	void findDeadAnts(Anthill* anthill);
	void goHome(Anthill* anthill);
	void findEnemy(Field* field);

	// Рабочие действия
	void build();
	void attack();
	void removeDeadAnt();

	//void safeChild();



	pair<int, int> randomAntHill(Anthill* anthill);
	void randomMoving(Field* filed);

	void printPosition()const{cout << "Ant's position : " << x << " " << y << "\n";}
	
	//compare
	bool operator==(const Ant* right)const;

	string status; // free / busy
	void changeStatus();
	sf::RectangleShape& getShape();

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