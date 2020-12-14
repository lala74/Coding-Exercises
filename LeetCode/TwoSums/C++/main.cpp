#include <time.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result;
        for(vector<int>::size_type i = 0; i < nums.size() - 1; ++i) {
            for(vector<int>::size_type j = i + 1; j < nums.size(); ++j) {
                if((nums.at(i) + nums.at(j)) == target) {
                    result = {static_cast<int>(i), static_cast<int>(j)};
                    break;
                }
            }
        }
        return result;
    }
};

int main(int argc, char** argv)
{
    clock_t tStart = clock();

    // Variables
    vector<int> nums{2, 7, 11, 13};
    int target = 9;
    vector<int> result;

    // Input

    // Main
    Solution solution;
    result = solution.twoSum(nums, target);

    // Output
    for(vector<int>::size_type i = 0; i < result.size(); ++i) {
        cout << result.at(i) << " ";
    }
    cout << endl;
    // Runtime
    cout << "------------" << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}