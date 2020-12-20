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
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            char leftC = tolower(s[left]);
            char rightC = tolower(s[right]);
            if(!isalnum(leftC)) {
                ++left;
                continue;
            }
            if(!isalnum(rightC)) {
                --right;
                continue;
            }

            if(leftC == rightC) {
                ++left;
                --right;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    bool result;

    // Input
    string s = "0P";

    // Main
    Solution solution;
    result = solution.isPalindrome(s);

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