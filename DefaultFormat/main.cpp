#include <time.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int solution()
    {
    }
};

int main(int argc, char** argv)
{
    clock_t tStart = clock();

    // Variables
    int result;

    // Input

    // Main
    Solution solution;
    result = solution.solution();

    // Output
    cout << result << endl;
    // Runtime
    cout << "------------" << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}