#include <iostream>
#include "smartpointer.h"

class SomeClass : public RefBase {
public:
    SomeClass() {std::cout << "SomeClass default constructer || address: "  << this << std::endl;}
    ~SomeClass() {std::cout << "SomeClass deconstructor || address: " << this << std::endl;}
};


void testcase() {
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
    testcase();

    return 0;
}
