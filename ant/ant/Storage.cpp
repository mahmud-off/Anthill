#include "Storage.h"
#include "Food.h"

int getRandomStorage(int min_n, int max_n) {
	static mt19937 generator(random_device{}());
	uniform_int_distribution<int> distribution(min_n, max_n);

	return distribution(generator);
};

void Storage::addFood()
{
	this->storage.push_back(new Food(this->storageX, this->storageY, 3));
	storage[storage.size()-1]->initFood(getRandomStorage(this->storageX, this->storageX + this->storageWidth), getRandomStorage(this->storageY, this->storageY + this->storageHeight));
	this->count++;
}

void Storage::delFood()
{
	delete storage[storage.size() - 1];
	this->storage.pop_back();
	this->count--;
}

void Storage::createStorage(int count,int x,int y,int h,int w) {
	this->count = count;
	this->storageX = x;
	this->storageY = y;
	this->storageWidth = w;
	this->storageHeight = h;

	for (int i = 0;i < count;i++) {
		this->storage.push_back(new Food(this->storageX, this->storageY, 3));
		storage[i]->initFood(getRandomStorage(this->storageX, this->storageX + this->storageWidth), getRandomStorage(this->storageY, this->storageY + this->storageHeight));
	}
}



void Storage::setHYHW(int x, int y, int height, int width)
{
	this->storageX = x;
	this->storageHeight = height;
	this->storageWidth = width;
	this->storageY = y;
	this->count = count;

}
