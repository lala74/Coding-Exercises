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
        int duplicate = 0;
        int length = static_cast<int>(nums.size());
        unordered_set<int> hashSet;
        for(int i = 0; i < length; ++i) {
            if(hashSet.find(nums.at(i)) != hashSet.end()) {
                duplicate = nums.at(i);
                break;
            } else {
                hashSet.insert({nums.at(i)});
            }
        }
        return duplicate;
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