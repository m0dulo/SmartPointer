#ifndef REFBASE_H_
#define REFBASE_H_

class RefBase {
private:
    int mCount;
public:
    RefBase()
        : mCount(0) {}

    void incRefCount() {
        mCount++;
    }

    int decRefCount() {
        return --mCount;
    }

    int getRefCount() const {
        return mCount;
    }

    virtual ~RefBase() {}
};

#endif // REFBASE_H_