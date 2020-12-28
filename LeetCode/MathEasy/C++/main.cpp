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
    int countPrimes(int n)
    {
        if(n <= 2) return 0;
        bool isPrime[n];
        for(int num = 0; num < n; ++num) {
            isPrime[num] = true;
        }

        for(int num = 2; num < n; ++num) {
            if(isPrime[num]) {
                for(int i = 1; num + i * num < n; ++i) {
                    isPrime[num + i * num] = false;
                }
            }
        }
        int count = 0;
        for(int num = 2; num < n; ++num) {
            if(isPrime[num]) {
                ++count;
                // cout << num << ' ';
            }
        }
        // cout << '\n';
        return count;
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    int result;

    // Input
    int n = 10;

    // Main
    Solution solution;
    result = solution.countPrimes(n);

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