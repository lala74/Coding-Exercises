#include <time.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution
{
public:
    int solution() {
        return 0;
    }
};

int main(int argc, char** argv)
{
    auto startTime = steady_clock::now();

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
    auto finishTime = steady_clock::now();
    auto runtime = finishTime - startTime;
    cout << "Runtime: " << duration_cast<seconds>(runtime).count() << "ms" << endl;
    // Memory usage
    return 0;
}
