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
    int removeDuplicates(vector<int>& nums)
    {
        int len = static_cast<int>(nums.size());
        if(len == 0) return 0;
        int i = 0;
        for(int j = 1; j < len; ++j) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    int result;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    // Input

    // Main
    Solution solution;
    result = solution.removeDuplicates(nums);

    // Output
    cout << result << endl;
    for(int i = 0; i < result; ++i) {
        cout << nums.at(i) << " ";
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