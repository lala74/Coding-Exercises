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
    // 1st solution
    // void rotate(vector<int>& nums, int k)
    // {
    //     int len = static_cast<int>(nums.size());
    //     int arr[len];
    //     for(int i = 0; i < len; i++) {
    //         arr[i] = nums[i];
    //     }
    //     for(int i = 0; i < len; i++) {
    //         nums[(i + k) % len] = arr[i];
    //     }
    // }

    // 2nd solution
    // void rotate(vector<int>& nums, int k)
    // {
    //     int len = static_cast<int>(nums.size());
    //     int temp, previous;
    //     k %= len;
    //     for(int rotation = 0; rotation < k; ++rotation) {
    //          previous = nums[len - 1];
    //         for(int i = 0; i < len; ++i) {
    //             temp = nums[i];
    //             nums[i] = previous;
    //             previous = temp;
    //         }
    //     }
    // }

    // 3rd solution
    void rotate(vector<int>& nums, int k)
    {
        int len = static_cast<int>(nums.size());
        k %= len;
        if(k == 0) return;
        reverse(nums, 0, len - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, len - 1);
    }

private:
    void reverse(vector<int>& nums, int begin, int end)
    {
        int temp;
        int j = 0;
        for(int i = begin; i <= (begin + end) / 2; ++i) {
            temp = nums[i];
            nums[i] = nums[end - j];
            nums[end - j] = temp;
            ++j;
        }
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    vector<int> nums = {1, 2};
    int k = 2;

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
    printf("Memory usage: %.3f MB\n", static_cast<float>(usage.vsize) / 1024 / 1024);
    return 0;
}