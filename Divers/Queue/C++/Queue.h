#pragma once

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int maxQueue = 10;
enum errorCode { fail, success, overflow, underflow };

template <class Entry>
class Queue
{
public:
    Queue();
    ~Queue();

    bool is_empty() const;
    errorCode append(const Entry& item);  // add an entry to rear
    errorCode serve();                    // eliminate first entry in queue
    errorCode retrieve(Entry& item);      // get first entry

    string queue_export() const;

private:
    bool is_full() const;
    uint next_position(uint pos) const;

private:
    uint count;
    uint rear, front;
    Entry entry[maxQueue];
};

template <class Entry>
Queue<Entry>::Queue() : count(0), rear(0), front(1)
{
    // in initialization, front must be behind rear
    // when add an entry, augmente rear by 1 rear == front == entryPos
}

template <class Entry>
Queue<Entry>::~Queue()
{
}

template <class Entry>
string Queue<Entry>::queue_export() const
{
    stringstream result;
    if(is_empty()) {
        result << "";
    } else {
        for(uint i = 0; i < count; ++i) {
            uint realPos = (front + i) % maxQueue;
            result << entry[realPos] << " ";
        }
    }
    return result.str();
}

template <class Entry>
errorCode Queue<Entry>::append(const Entry& item)
{
    if (is_full()) {
        return errorCode::overflow;
    } else {
        ++count;
        rear = next_position(rear);
        entry[rear] = item;
    }
    return errorCode::success;
}

template <class Entry>
errorCode Queue<Entry>::serve()
{
    if (is_empty()) {
        return errorCode::underflow;
    } else {
        --count;
        front = next_position(front);
    }
    return errorCode::success;
}

template <class Entry>
errorCode Queue<Entry>::retrieve(Entry &item)
{
    if (is_empty()) {
        return errorCode::underflow;
    } else {
        item = entry[front];
    }
    return errorCode::success;
}

template <class Entry>
bool Queue<Entry>::is_empty() const
{
    return (count == 0);
}

template <class Entry>
bool Queue<Entry>::is_full() const
{
    return (count == maxQueue);
}

template <class Entry>
uint Queue<Entry>::next_position(uint pos) const
{
    return ((pos + 1) % maxQueue);
}
