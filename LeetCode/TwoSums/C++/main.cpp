#include <time.h>

#include <algorithm>
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
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result;
        unordered_map<int, int> hashMap;
        for(vector<int>::size_type i = 0; i < nums.size(); ++i) {
            hashMap.insert({nums.at(i), static_cast<int>(i)});
        }
        for(vector<int>::size_type i = 0; i < nums.size(); ++i) {
            int secondValue = target - nums.at(i);
            auto it = hashMap.find(secondValue);
            if(it != hashMap.end()) {
                if(hashMap[secondValue] != static_cast<int>(i)) {
                    result = {
                        static_cast<int>(i),
                        hashMap[secondValue],
                    };
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