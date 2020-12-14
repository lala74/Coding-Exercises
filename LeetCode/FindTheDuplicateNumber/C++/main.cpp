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
        sort(nums.begin(), nums.end());
        for (int i=0; i < len-1; ++i) {
            if (nums.at(i) == nums.at(i+1)) {
                return nums.at(i);
            }
        }
        return 0;
    }
};

int main(int argc, char** argv)
{
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
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}