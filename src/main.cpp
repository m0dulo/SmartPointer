#include <iostream>
#include "smartpointer.h"

class SomeClass : public RefBase {
public:
    SomeClass() {std::cout << "SomeClass default constructer || address: "  << this << std::endl;}
    ~SomeClass() {std::cout << "SomeClass deconstructor || address: " << this << std::endl;}
    void func() {std::cout << "SomeClass func()" <<std::endl;}
};

class OtherClass: public RefBase{
public:
    OtherClass() {std::cout << "OtherClass default constructor !"<<std::endl;};
    ~OtherClass() {std::cout << "OtherClass deconstructor !"<<std::endl;};
    void foo() {std::cout << "OtherClass foo()" <<std::endl;}
};

void testcase_2() {
    std::cout << "=======testcase_2=========" <<std::endl;
    SomeClass *psomeclass = new SomeClass();
    SmartPointer<SomeClass> spsomeclass = psomeclass;

    SmartPointer<OtherClass> spotherclass = new OtherClass();
    SmartPointer<OtherClass> spotherclass2 = spotherclass;

    if (spsomeclass == nullptr) std::cout<< "spsomeclass is NULL pointer" << std::endl;
    if (spotherclass != nullptr) std::cout<< "spotherclass is not NULL pointer" << std::endl;
    if (spsomeclass == psomeclass)
       std::cout<< "spsomeclass and psomeclass are same pointer" << std::endl;
    if (spsomeclass != psomeclass)
       std::cout<< "spsomeclass and psomeclass are not same pointer" << std::endl;
//     if (spsomeclass != spotherclass) // ERROR !
//        std::cout<< "spsomeclass and spotherclass are not same pointer" << std::endl;
//     if (spsomeclass == spotherclass) // ERROR !
//        std::cout<< "spsomeclass and spotherclass are same pointer" << std::endl;
    if (spotherclass == spotherclass2) std::cout<< "spotherclass and spotherclass2 are same pointer" << std::endl;
    if (spotherclass != spotherclass2) std::cout<< "spotherclass and spotherclass2 are not same pointer" << std::endl;
    std::cout << "==========================" <<std::endl;

}

void testcase_1(void)
{
    std::cout << "=======testcase_1=========" <<std::endl;
    SmartPointer<SomeClass> spsomeclass = new SomeClass();
    (*spsomeclass).func();
    spsomeclass->func();
    std::cout << "==========================\n" <<std::endl;
}



void testcase_base() {
    SmartPointer<SomeClass> spunknow;
    SmartPointer<SomeClass> spnull = nullptr;
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
    spclass2 = nullptr;
}

int main() {
    testcase_base();
    testcase_1();
    testcase_2();
    return 0;
}
