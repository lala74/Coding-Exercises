#include <proc/readproc.h>
#include <time.h>

#include <algorithm>
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
    int findDuplicate(vector<int>& nums)
    {
        int len = static_cast<int>(nums.size());
        int seenArr[len];
        for(int i = 0; i < len; ++i) {
            seenArr[i] = 0;
        }
        int value = nums.at(0);
        while(1) {
            if(seenArr[value] == 1) {
                break;
            } else {
                seenArr[value] = 1;
                value = nums.at(value);
            }
        }
        return value;
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    int result;

    // Input
    vector<int> nums{1, 3, 4, 2, 2};

    // Main
    Solution solution;
    result = solution.findDuplicate(nums);

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