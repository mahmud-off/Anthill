#ifndef STORAGE_H
#define STORAGE_H
#include "AntHill.h"
//#include "Food.h"
#include <vector>

#include <random>

class Food;


class Storage {
public:
	void addFood();
	void delFood();
	Storage(int count);

	vector<Food *> storage;
	void setHYHW(int x, int y, int height, int width);
private:
	int count;
	int storageX;
	int storageY;
	int storageHeight;
	int storageWidth;

};

#endif