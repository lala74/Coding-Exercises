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
        if ((len == 0) || (len == 1)) return 0;
        int maxProfits[len];
        int min = prices[0];
        maxProfits[0] = 0;
        for(int day = 1; day < len; ++day) {
            min = std::min(min, prices[day]);
            maxProfits[day] = std::max(maxProfits[day - 1], prices[day] - min);
        }
        return maxProfits[len - 1];
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    int result;

    // Input
    vector<int> prices{7, 1, 5, 3, 6, 4};

    // Main
    Solution solution;
    // result = solution.climbStairs(3);
    result = solution.maxProfit(prices);

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