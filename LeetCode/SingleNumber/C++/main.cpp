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
    int singleNumber(vector<int>& nums)
    {
        int len = static_cast<int>(nums.size());
        if (len == 1) return nums[0];
        sort(nums.begin(), nums.end());

        for(int i = 0; i < len; i = i + 2) {
            if (nums[i] != nums[i+1]) {
                return nums[i];
            }
        }
        return nums[len-1];
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    int result;
    vector<int> nums = {1};

    // Input

    // Main
    Solution solution;
    result = solution.singleNumber(nums);

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