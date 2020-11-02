#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int f(uint x)
{
    if (x == 0) {
        return -1;
    }
    if (x == 1) {
        return 101;
    }
    return (f(x-1) + 1);
}

int main(int argc, char** argv)
{
    // Variable

    // Input

    // Main

    // Output
    cout << f(2) << endl;

    return 0;
}