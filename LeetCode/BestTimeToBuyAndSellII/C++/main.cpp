#include <proc/readproc.h>
#include <time.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    // 1st solution: https://www.programcreek.com/2014/02/leetcode-best-time-to-buy-and-sell-stock-iii-java/
    int maxProfit(vector<int>& prices)
    {
        int len = static_cast<int>(prices.size());
        // forward
        int min = prices[0];
        int forward[len];
        forward[0] = 0;
        for(int i = 1; i < len; ++i) {
            min = std::min(min, prices[i]);
            forward[i] = std::max(forward[i - 1], prices[i] - min);
        }
        // backward
        int max = prices[len - 1];
        int backward[len];
        backward[len - 1] = 0;
        for(int i = len - 2; i >= 0; --i) {
            max = std::max(max, prices[i]);
            backward[i] = std::max(backward[i + 1], max - prices[i]);
        }
        // total
        int maxProfit = 0;
        for(int i = 0; i < len; ++i) {
            int totalProfit = forward[i] + backward[i];
            if (totalProfit > maxProfit) {
                maxProfit = totalProfit;
            }
        }
        return maxProfit;
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    int result;
    vector<int> prices{1, 2,3,4,5};
    // Input

    // Main
    Solution solution;
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