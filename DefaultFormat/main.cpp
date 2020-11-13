#include <time.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    clock_t tStart = clock();

    // Variables
    string result;

    // Input

    // Main

    // Output
    cout << result << endl;
    cout << "------------" << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}