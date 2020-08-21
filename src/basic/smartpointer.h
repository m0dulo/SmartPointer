#ifndef SMARTPOINTER_H_
#define SMARTPOINTER_H_

#include "refbase.h"

template <typename T>
class SmartPointer {
private:
    T *mPointer;
public:
    SmartPointer()
        : mPointer(nullptr) {
        std::cout << "create unknown smart pointer" << std::endl;
    }
    SmartPointer(T *p)
        : mPointer(p) {
        std::cout << "create smart pointer at " << static_cast<const void*>(p) << std::endl;
        if (mPointer) mPointer->incRefCount();
    }

    ~SmartPointer() {
        std::cout << "release smart pointer at " << static_cast<const void*>(mPointer) << std::endl;
        if(mPointer && mPointer->decRefCount() == 0) delete mPointer;
    }

    SmartPointer(const SmartPointer &other)
        : mPointer(other.mPointer) {
        std::cout << "Copy smart pointer at " << static_cast<const void*>(other.mPointer) << std::endl;
        if(mPointer) mPointer->incRefCount();
    }

    SmartPointer& operator = (const SmartPointer &other) {
        if(this == &other) return *this;
        T *temp(other.mPointer);
        if(temp) temp->incRefCount();
        if(mPointer && mPointer->decRefCount() == 0) delete mPointer;
        mPointer = temp;
        std::cout << "Assign smart pointer at " << static_cast<const void*>(other.mPointer) << std::endl;
        return *this;
    }
};

#endif // SMARTPOINTER_H_
