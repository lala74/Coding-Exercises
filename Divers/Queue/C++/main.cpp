#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

#include "Queue.h"

using namespace std;

int main()
{
    // Variable
    string result;
    Queue<int> queue;
    // int value = 0;

    // Input

    // Main
    queue.append(1);
    queue.append(2);
    queue.append(3);
    queue.append(4);
    queue.append(5);
    queue.append(6);
    queue.append(7);
    queue.append(8);
    queue.append(9);
    queue.append(10);
    queue.serve();

    // Output
    cout << result << endl;
    cout << "Is empty: " << queue.is_empty() << endl;
    cout << "Queue: " << queue.queue_export() << endl;
    if(queue.append(11) == errorCode::overflow) {
        cout << "Overflow" << endl;
    }
    int firstItem;
    queue.retrieve(firstItem);
    cout << "First item: " << firstItem << endl;

    return 0;
}