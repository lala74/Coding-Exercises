//
// Copyright (c) 2022 Axon Enterprise
//
/**
 * @author      : La Minh Duc
 * @file        : Vector.h
 * @created     : Sunday Jan 02, 2022 18:54:07 +07
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>
#include <cstdlib>
#include <iostream>

template<class T>
class Vector
{
public:
    Vector() { reAllocate(2); };
    ~Vector(){};

    T& operator[](size_t index)
    {
        if (index >= mSize) {
            assert((index < mSize) && "Index out of bound");
        }
        return mData[index];
    }

    const T& operator[](size_t index) const
    {
        if (index >= mSize) {
            assert((index < mSize) && "Index out of bound");
        }
        return mData[index];
    };

    size_t Size() { return mSize; }

    void PushBack(T&& value)
    {
        if (mSize == mCap) {
            reAllocate(mCap * 2);
        }
        mData[mSize] = std::move(value);
        ++mSize;
    }

    void PopBack()
    {
        if (mSize == 0) {
            std::cout << "Empty container" << std::endl;
            return;
        }
        mData[mSize - 1].~T();
        --mSize;
    }

    int Clear()
    {
        mSize = 0;
        mCap = 0;
        if (mData != nullptr) {
            delete mData;
            mData = nullptr;
        }
        return 0;
    }

private:
    void reAllocate(int newCap)
    {
        mCap = newCap;
        if (mSize > mCap) {
            mSize = mCap;
        }
        T* newData = new T[newCap];
        for (size_t i = 0; i < mSize; ++i) {
            newData[i] = std::move(mData[i]);
        }
        delete[] mData;
        mData = newData;
    }

private:
    T* mData = nullptr;
    size_t mSize = 0;
    size_t mCap = 0;
};

#endif /* VECTOR_H */

