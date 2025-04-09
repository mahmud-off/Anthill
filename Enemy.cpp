#include "Enemy.h"
#include <ctime>
#include <cstdlib>

Enemy::Enemy(int x, int y) // Coordinates compute in Field
{
    cout << "Enemy was created\n";
    srand(time(0));
    hp = 100;
    hit = 5 + rand() % 10;
    weight = 5 + rand() % 10;
    posX = x;
    posY = y;
}

Enemy::~Enemy()
{
    cout << "Enemy was deleted from " << this->posX << " " << this->posY << "\n";
}
