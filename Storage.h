#ifndef STORAGE_H
#define STORAGE_H

//#include "Food.h"
#include <vector>

#include <random>

class Food;

using namespace std;
class Storage {
public:
	void addFood();
	void delFood();
	void createStorage(int count, int x, int y, int h, int w);
	int getCount() { return this->count; };

	pair<int,int> newCoordinateStorage();
	void addFoodCoordinate(pair<int , int> coordinateFoodStorage,int weight);


	vector<Food *> storageFood;
	void setHYHW(int x, int y, int height, int width);

	int getX() { return this->storageX; }
	int getY() { return this->storageY; }

private:
	int count;
	int storageX;
	int storageY;
	int storageHeight;
	int storageWidth;

};

#endif