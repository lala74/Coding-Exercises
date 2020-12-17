#include <proc/readproc.h>
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

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int len = static_cast<int>(digits.size());
        for(int i = len - 1; i >= 0; --i) {
            if(digits[i] != 9) {
                ++digits[i];
                return digits;
            } else {
                digits[i] = 0;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    vector<int> result;
    vector<int> digits = {9, 9, 9};

    // Input

    // Main
    Solution solution;
    result = solution.plusOne(digits);

    // Output
    for(int i = 0; i < static_cast<int>(digits.size()); ++i) {
        cout << digits[i] << ' ';
    }
    cout << '\n';
    // Runtime
    cout << "------------" << endl;
    printf("Time taken  : %.2f s\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    // Memory usage
    look_up_our_self(&usage);
    printf("Memory usage: %.2f MB\n", static_cast<float>(usage.vsize) / 1024 / 1024);
    return 0;
}