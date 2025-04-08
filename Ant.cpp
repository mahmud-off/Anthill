#include "Ant.h"
#include "AntHill.h"

#define STEP 1

Ant::Ant() {
    cout << "ant created\n";
    age = 0;
    role = "None";
    health = 100;
    weight = 0; //���� ���� ������� ������ � �����-�� ���������
    posX = 0;
    posY = 0;
}

Ant::~Ant() {
    cout << "\nAnt destructor;!!!\n";
}

void Ant::moveRight() {
    posX += 1 * STEP;
}

void Ant::moveLeft() {
    posX -= 1 * STEP;
}

void Ant::moveUp() {
    posY += 1 * STEP;
}

void Ant::moveDown() {
    posY -= 1 * STEP;
}

