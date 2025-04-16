#ifndef ANT_H
#define ANT_H

#include <vector>
#include <iostream>
// #include "Field.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>


class Field;
class Anthill;
class Food;
class Materials;

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
	pair<int, pair<int, int>> findNearestPointCollecter(int x1, int y1, vector<Food *> v); // nearest point with food or materials from ant
	pair<int, pair<int, int>> findNearestPointBuilder(int x1, int y1, vector<Materials*> v); // nearest point with food or materials from ant
	vector<pair<int, int>> A_StarSearch(pair<int, int> start, pair<int, int> end, Field *field); // shortest path from start to end

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
	void setStatus(string status) { this->status = status; }

	//functions
	virtual void work(Field *field, Anthill *anthill) = 0;

	void printPosition()const{cout << "Ant's position : " << x << " " << y << "\n";}


	// moving
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();

	void randomMoving(int heightOfField, int widthOfField);
	void moveByCoordinates(pair<int,int> point);

	//compare
	bool operator==(const Ant* right)const;

	string status; // free / busy
	void changeStatus();
	sf::RectangleShape& getShape();

private:
	sf::RectangleShape shape;
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