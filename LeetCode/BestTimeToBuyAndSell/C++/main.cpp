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
    int maxProfit(vector<int>& prices)
    {
        int len = static_cast<int>(prices.size());
        int priceHold = 0, profit = 0;
        int nextAction = BUY;
        for(int i = 0; i < len - 1; ++i) {
            int priceNow = prices[i];
            int priceNext = prices[i + 1];
            if((nextAction == BUY) && (priceNext > priceNow)) {
                nextAction = SELL;
                priceHold = priceNow;
            }
            if((nextAction == SELL) && (priceNext < priceNow)) {
                nextAction = BUY;
                profit += (priceNow - priceHold);
            }
        }
        int lastPrice = prices[len-1];
        if ((nextAction == SELL) && (lastPrice > priceHold)) {
            profit += lastPrice - priceHold;
        }
        return profit;
    }

private:
    const int BUY = 1;
    const int SELL = 0;
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    int result;
    vector<int> prices = {7,6,4,3,1};

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