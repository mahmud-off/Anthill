#include "Child.h"

Child::Child()
{
	cout << "child created\n";
	this->setRole("child");
}

Child::~Child() {
	cout << "child was deleted\n";
}
