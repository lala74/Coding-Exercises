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
    // Climbing Stairs
    int climbStairs(int n)
    {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int steps[n + 1];
        steps[1] = 1;
        steps[2] = 2;
        for(int step = 3; step < n + 1; ++step) {
            steps[step] = steps[step - 1] + steps[step - 2];
        }
        return steps[n];
    }

    // Best Time to Buy and Sell Stock
    int maxProfit(vector<int>& prices)
    {
        int len = static_cast<int>(prices.size());
        if((len == 0) || (len == 1)) return 0;
        int maxProfits[len];
        int min = prices[0];
        maxProfits[0] = 0;
        for(int day = 1; day < len; ++day) {
            min = std::min(min, prices[day]);
            maxProfits[day] = std::max(maxProfits[day - 1], prices[day] - min);
        }
        return maxProfits[len - 1];
    }

    // Max Subarray
    int maxSubArray(vector<int>& nums)
    {
        int len = static_cast<int>(nums.size());
        if(len == 0) return 0;
        int maxCurrentSub = 0;
        int maxGlobalSub = nums[0];
        for(int num : nums) {
            if(maxCurrentSub < 0) maxCurrentSub = 0;
            maxCurrentSub += num;
            maxGlobalSub = std::max(maxGlobalSub, maxCurrentSub);
        }
        return maxGlobalSub;
    }

    // House Robber
    int rob(vector<int>& nums)
    {
        int len = static_cast<int>(nums.size());
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        if(len == 2) return std::max(nums[0], nums[1]);
        int maxMoneys[len];
        maxMoneys[0] = nums[0];
        maxMoneys[1] = std::max(nums[0], nums[1]);
        for(int i = 2; i < len; ++i) {
            maxMoneys[i] = std::max(maxMoneys[i - 1], maxMoneys[i - 2] + nums[i]);
        }
        return maxMoneys[len - 1];
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    int result;

    // Input
    // vector<int> prices{7, 1, 5, 3, 6, 4};    // maxProfit
    // vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4}; // maxSubArray
    vector<int> nums{2, 1, 1, 2};  // rob

    // Main
    Solution solution;
    // result = solution.climbStairs(3);
    // result = solution.maxProfit(prices);
    // result = solution.maxSubArray(nums);
    result = solution.rob(nums);

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