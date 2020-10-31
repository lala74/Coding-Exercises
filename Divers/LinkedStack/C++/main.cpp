#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

#include "LinkedStack.h"

using namespace std;

int main()
{
    // Variable
    string result;
    LinkedStack<int> stack;
    int value = 0;

    // Input
    if(stack.push(1) != errorCode::success) {
        return -1;
    }
    // Main

    // Output
    // cout << stack.stack_export() << endl;
    if(stack.top(value) != errorCode::success) {
        return -1;
    }
    cout << value << endl;
    // stack.pop();
    stack.top(value);
    cout << value << endl;
    stack.push(5);
    // cout << stack.stack_export() << endl;

    return 0;
}
