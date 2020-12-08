#include <time.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

uint fibinacci(uint n)
{
    uint arr[n+1];

    arr[0] = 0;
    arr[1] = 1;
    for (uint i = 2; i < n+1; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

int main(int argc, char** argv)
{
    clock_t tStart = clock();

    // Variables
    uint result;
    uint N;

    // Input
    cin >> N;

    // Main
    result = fibinacci(N);

    // Output
    cout << result << endl;
    cout << "------------" << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}