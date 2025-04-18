#ifndef STORAGE_H
#define STORAGE_H
#include "AntHill.h"
//#include "Food.h"
#include <vector>

#include <random>

class Food;
class Game;


class Storage {
public:
	void addFood(Game *game);
	void delFood();
	void createStorage(int count, int x, int y, int h, int w, Game *game);
	int getCount() { return this->count; };

	vector<Food *> storage;
	void setHYHW(int x, int y, int height, int width);

	int getX() { return this->storageX; }
	int getY() { return this->storageY; }
	int getW() { return this->storageWidth; }
	int getH() { return this->storageHeight; }

private:
	int count;
	int storageX;
	int storageY;
	int storageHeight;
	int storageWidth;

};

#endif