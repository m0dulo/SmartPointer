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
   SmartPointer<const char> spstr = "Hello World~!";
}

int main() {
    testcase1();
    return 0;
}
