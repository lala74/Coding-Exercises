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
    void rotate(vector<int>& nums, int k)
    {
        int len = static_cast<int>(nums.size());
        int arr[len];
        for(int i = 0; i < len; i++) {
            arr[i] = nums[i];
        }
        for(int i = 0; i < len; i++) {
            nums[(i + k) % len] = arr[i];
        }
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    // Input

    // Main
    Solution solution;
    solution.rotate(nums, k);

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