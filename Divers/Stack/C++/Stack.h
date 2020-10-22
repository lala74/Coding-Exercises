#pragma once

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int maxStack = 10;
enum errorCode { fail, success, overflow, underflow };

template <class Entry>
class Stack
{
public:
    Stack();
    ~Stack();

    bool is_empty() const;
    errorCode push(const Entry& item);
    errorCode pop();
    errorCode top(Entry& item);

    string stack_export() const;

private:
    bool is_full() const;

private:
    uint count;
    Entry entry[maxStack];
};

template <class Entry>
Stack<Entry>::Stack() : count(0)
{
}

template <class Entry>
Stack<Entry>::~Stack()
{
}

template <class Entry>
bool Stack<Entry>::is_empty() const
{
    return (count == 0);
}

template <class Entry>
bool Stack<Entry>::is_full() const
{
    return (count >= maxStack);
}

template <class Entry>
string Stack<Entry>::stack_export() const
{
    stringstream result;
    for(uint i = 0; i < count; ++i) {
        result << entry[i] << " ";
    }

    return result.str();
}

template <class Entry>
errorCode Stack<Entry>::push(const Entry& item)
{
    if(is_full()) {
        return errorCode::fail;
    } else {
        entry[count] = item;
        ++count;
    }
    return errorCode::success;
}

template <class Entry>
errorCode Stack<Entry>::pop()
{
    if(is_empty()) {
        return errorCode::underflow;
    } else {
        --count;
    }
    return errorCode::success;
}

template <class Entry>
errorCode Stack<Entry>::top(Entry& item)
{
    if(is_empty()) {
        return errorCode::underflow;
    } else {
        item = entry[count - 1];
    }
    return errorCode::success;
}
