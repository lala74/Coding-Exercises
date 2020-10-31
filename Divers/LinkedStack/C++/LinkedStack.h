#pragma once

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Node.h"

using namespace std;

enum errorCode { fail, success, overflow, underflow };
const int maxStack = 10;

template <class Entry>
class LinkedStack
{
public:
    LinkedStack();
    LinkedStack(const LinkedStack<Entry>& copyLinkedStack);
    ~LinkedStack();

    bool is_empty() const;
    errorCode push(const Entry& item);
    errorCode pop();
    errorCode top(Entry& item);

    string stack_export() const;

    void operator=(const LinkedStack<Entry>& copyLinkedStack);

private:
    bool is_full() const;

public:
    uint count;
    Node<Entry>* topNode;
};

/********************************* */
// Constuctor
template <class Entry>
LinkedStack<Entry>::LinkedStack() : count(0), topNode(nullptr)
{
}

template <class Entry>
LinkedStack<Entry>::~LinkedStack()
{
}

/********************************* */
// Public function
template <class Entry>
errorCode LinkedStack<Entry>::push(const Entry& item)
{
    Node<Entry>* newNode = new Node<Entry>(item, topNode);
    if(newNode == nullptr) {
        return errorCode::overflow;
    } else {
        topNode = newNode;
    }
    return errorCode::success;
}

template <class Entry>
errorCode LinkedStack<Entry>::top(Entry& item)
{
    if(is_empty()) {
        return errorCode::fail;
    } else {
        item = topNode->m_data;
        return errorCode::success;
    }
}

/********************************* */
// Private function
template <class Entry>
bool LinkedStack<Entry>::is_empty() const
{
    return (topNode == nullptr);
    // return (count == 0);
}

template <class Entry>
bool LinkedStack<Entry>::is_full() const
{
    return (count == maxStack);
}