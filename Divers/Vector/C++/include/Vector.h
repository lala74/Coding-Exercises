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

template <class T>
class Vector
{
public:
    Vector();
    ~Vector();
    T& operator[](int i);
    int Size() { return mSize; };

    int PushBack(T value);
    int PopBack();
    int Clear();

private:
    T* mData;
    int mSize = 0;
    int mCap = 0;
};

template <class T>
Vector<T>::Vector()
{
}

template <class T>
Vector<T>::~Vector()
{
    Clear();
}

template <class T>
T& Vector<T>::operator[](int index)
{
    if (index >= mSize) {
        assert((index < mSize) && "Index out of bound");
    }
    return mData[index];
}

template <class T>
int Vector<T>::PushBack(T value)
{
    if (mCap == 0) {
        mCap = 1;
    }
    if (mSize + 1 > mCap) {
        mCap *= 2;
    }
    std::cout << "Cap:" << mCap << std::endl;

    auto newData = new T[mCap];
    for (int i = 0; i < mSize; i++) {
        newData[i] = mData[i];
    }
    newData[mSize] = value;
    if (mData != nullptr) {
        delete mData;
        mData = nullptr;
    }
    mData = newData;
    newData = nullptr;
    ++mSize;
    for (int j = 0; j < mSize; j++) {
        std::cout << mData[j] << " ";
    }
    std::cout << std::endl;

    return 0;
}

template <class T>
int Vector<T>::PopBack()
{
    if (mSize == 0) {
        std::cout << "Empty container" << std::endl;
        return 0;
    }
    if (mSize == 1) {
        Clear();
        return 0;
    }
    --mSize;
    return 0;
}

template <class T>
int Vector<T>::Clear()
{
    mSize = 0;
    mCap = 0;
    if (mData != nullptr) {
        delete mData;
        mData = nullptr;
    }
    return 0;
}

#endif /* VECTOR_H */

