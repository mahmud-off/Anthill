#include <iostream>
#include "AntHill.h"
#include "Field.h"

int main() {
    Anthill test;

    cout << "\n\n" << (*test.getChildList())[1].getRole() << "\n";

    std::cout << "Anthill is alive!!!\n";
}
