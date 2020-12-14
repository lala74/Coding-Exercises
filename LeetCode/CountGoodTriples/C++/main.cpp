#include <time.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c)
    {
        int count = 0;
        int len = static_cast<int>(arr.size());
        for(int i = 0; i < len - 2; ++i) {
            for(int j = i + 1; j < len - 1; ++j) {
                if(abs(arr.at(i) - arr.at(j)) <= a) {
                    for(int k = j + 1; k < len; ++k) {
                        if((abs(arr.at(j) - arr.at(k)) <= b) && (abs(arr.at(i) - arr.at(k)) <= c)) {
                            ++count;
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main(int argc, char** argv)
{
    clock_t tStart = clock();

    // Variables
    int result;

    // Input
    vector<int> arr{7, 3, 7, 3, 12, 1, 12, 2, 3};
    int a = 5;
    int b = 8;
    int c = 1;

    // Main
    Solution solution;
    result = solution.countGoodTriplets(arr, a, b, c);

    // Output
    cout << result << endl;
    // Runtime
    cout << "------------" << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}