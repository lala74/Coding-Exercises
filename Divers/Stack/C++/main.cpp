#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

#include "Stack.h"

using namespace std;

int main()
{
    // Variable
    string result;
    Stack<int> stack;
    int value = 0;

    // Input
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    // Main

    // Output
    cout << stack.stack_export() << endl;
    stack.top(value);
    cout << value << endl;
    stack.pop();
    stack.top(value);
    cout << value << endl;
    stack.push(5);
    cout << stack.stack_export() << endl;

    return 0;
}
