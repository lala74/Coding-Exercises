#include <proc/readproc.h>
#include <time.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> hashSet;
        int len = static_cast<int>(nums.size());
        for(int i = 0; i < len; ++i) {
            if (hashSet.find(nums[i]) != hashSet.end()) {
                return true;
            } else {
                hashSet.insert(nums[i]);
            }
        }
        return false;
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    bool result;

    // Input
    vector<int> nums{1, 2, 3, 1};

    // Main
    Solution solution;
    result = solution.containsDuplicate(nums);

    // Output
    cout << result << endl;
    // Runtime
    cout << "------------" << endl;
    printf("Time taken  : %.2f s\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    // Memory usage
    look_up_our_self(&usage);
    printf("Memory usage: %.2f MB\n", static_cast<float>(usage.vsize) / 1024 / 1024);
    return 0;
}