#include "Ant.h"

Ant::Ant()
{
	cout << "ant created\n";
	age = 0;
	role = "None";
	health = 100;
	weight = 0; //���� ���� ������� ������ � �����-�� ���������
}

Ant::~Ant()
{
	cout << "\nAnt destructor;!!!\n";
}
