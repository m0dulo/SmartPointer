#include <iostream>
#include "smartpointer.h"

class SomeClass {
public:
    SomeClass() {std::cout << "SomeClass default constructer" << std::endl;}
};

void testcase1() {
   SmartPointer<char> spunknow;
   SmartPointer<char> spnull = nullptr;
   SmartPointer<SomeClass> spclass = new SomeClass;
}

void testcase2() {
    SmartPointer<SomeClass> spclass1 = new SomeClass;
    std::cout << std::endl;
    spclass1 = spclass1;
    std::cout << std::endl;
    SmartPointer<SomeClass> spclassother = spclass1;
    std::cout << std::endl;
    SmartPointer<SomeClass> spclass2 = new SomeClass;
    std::cout << std::endl;
    spclass2 = spclass1;
    std::cout << std::endl;
}

int main() {
    testcase2();
    testcase1();
    return 0;
}
