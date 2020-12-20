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
    void moveZeroes(vector<int>& nums)
    {
        int len = static_cast<int>(nums.size());
        int count = 0;
        for(int i = 0; i < len; ++i) {
            if(nums[i] == 0) {
                ++count;
            } else {
                nums[i - count] = nums[i];
            }
        }
        for(int i = len - count; i < len; ++i) {
            nums[i] = 0;
        }
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables

    // Input
    vector<int> nums{0, 1, 0, 3, 12};

    // Main
    Solution solution;
    solution.moveZeroes(nums);

    // Output
    for(int i = 0; i < static_cast<int>(nums.size()); ++i) {
        cout << nums[i] << ' ';
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