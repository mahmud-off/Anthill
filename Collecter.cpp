#include "Collecter.h"

Collecter::Collecter()
{
	cout << "collecter created\n";
	this->setRole("collecter");
}

Collecter::Collecter(vector<Child> list, Child &child)
{
	cout << "collecter from child" << endl;
	this->setAge(child.getAge());
	//this->setPosX()
}
