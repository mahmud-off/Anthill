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
class Materials;
class Food;
class Field;
class Dead;
class Game;

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
	pair<int, pair<int, int>> findNearestPointCollecter(int x1, int y1, vector<Food *> v, vector<Food*>& detectedFood, Game *game); // nearest point with food or materials from ant
	pair<int, pair<int, int>> findNearestPointBuilder(int x1, int y1, vector<Materials*> v, vector<Materials*>& detectedMaterials, Game *game); // nearest point with food or materials from ant
	pair<int, pair<int, int>> findNearestPointDead(int x1, int y1, vector<Dead*> v, vector<Dead*>& detectedDead); // nearest point with food or materials from ant
	vector<pair<int, int>> A_StarSearch(pair<int, int> start, pair<int, int> end, Field *field); // shortest path from start to end

	//access
	int getAge()const { return age; }
	string getRole()const { return role; }
	int getHealth()const { return health; }
	int getWeight()const {return weight; }
	int getPosX() { return this->x; }
	int getPosY() { return this->y; }
	int getPower() { return this->power; }
	string getStatus() { return this->status; }
	string getWorkStatus() { return this->work_status; }

	//setters
	void setAge(int n){ age = n; }
	void setRole(string n) { role = n; }
	void setHealth(int n) { health = n; }
	void setPosX(int x);
	void setPosY(int y);
	void setWeight(int weight) { this->weight = weight; }
	void setPower(int power) { this->power = power; }
	void setStatus(string status) { this->status = status; }
	void setEndPoint(pair<int, int> point) { endPoint = point; }
	void setWorkStatus(string new_work_status) { this->work_status = new_work_status; }

	pair<int, pair<int, int>> findNearestPoint(int x1, int y1, vector<pair<int, pair<int, int>>> v); // nearest point with food or materials from ant
	
	//Base function for ant actions
	virtual void work(Field* field, Anthill* anthil, Game *game) = 0;

	// Movent to point
	void updateMovement(Field* field, Anthill* anthil, string new_work);

	// Определение координат
	void findFood(Field* field, Game *game);
	void findMaterial(Field* field, Game *game);
	void findDeadAnts(Anthill* anthill);
	void findHome(Anthill* anthill);
	void findEnemy(Field* field);

	// Рабочие действия
	void build();
	void attack();
	void removeDeadAnt();

	//void safeChild();

	int getRandomPoint(int min_n, int max_n);

	void stay_on_your_Point(int x, int y);

	pair<int, int> randomAntHill(Anthill* anthill);
	pair<int, int> randomAntNurseryPos(Anthill* anthill);
	void randomMoving(Field* filed);

	void printPosition()const{/*cout << "Ant's position : " << x << " " << y << "\n";*/}
	
	//compare
	bool operator==(const Ant* right)const;

	string status; // free / busy
	void changeStatus();
	sf::RectangleShape& getShape();

private:
	int age;
	string role;
	string work_status;
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