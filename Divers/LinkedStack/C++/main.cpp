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
        cout << "Push failed" << endl;
        return -1;
    }
    if(stack.push(2) != errorCode::success) {
        cout << "Push failed" << endl;
        return -1;
    }
    if(stack.push(3) != errorCode::success) {
        cout << "Push failed" << endl;
        return -1;
    }
    // Main

    // Output
    cout << "Stack                  : " << stack.stack_export() << endl;
    if(stack.top(value) != errorCode::success) {
        cout << "Top failed" << endl;
        return -1;
    }
    cout << "First value            : " << value << endl;
    if(stack.pop() != errorCode::success) {
        cout << "Pop failed" << endl;
        return -1;
    }
    if(stack.top(value) != errorCode::success) {
        cout << "Top failed" << endl;
        return -1;
    }
    cout << "First value after pop  : " << value << endl;
    if(stack.push(5) != errorCode::success) {
        cout << "Push failed" << endl;
        return -1;
    }
    cout << "Stack after push 5     : " << stack.stack_export() << endl;

    return 0;
}
