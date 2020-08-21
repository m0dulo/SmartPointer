#ifndef SMARTPOINTER_H_
#define SMARTPOINTER_H_

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
    }

    ~SmartPointer() {
        std::cout << "release smart pointer at " << static_cast<const void*>(mPointer) << std::endl;
        if(mPointer) delete mPointer;
    }

    SmartPointer(const SmartPointer &other)
        : mPointer(other.mPointer) {
        std::cout << "Copy smart pointer at " << static_cast<const void*>(other.mPointer) << std::endl;
    }

    SmartPointer& operator = (const SmartPointer &other) {
        if(this == &other) return *this;
        if(mPointer) delete mPointer;
        mPointer = other.mPointer;
        std::cout << "Assign smart pointer at " << static_cast<const void*>(other.mPointer) << std::endl;
        return *this;
    }
};

#endif // SMARTPOINTER_H_
