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

class Algorithm
{
public:
    /** @return the position of the dancer at stage n​​​​​​‌​​‌​‌‌‌​​​​‌​​​​​‌‌‌​​​​ */
    static int getPositionAt(int n)
    {
        int i = 0;
        int step = 0;
        int first = 0; int second = 1; int third = -1;
        for (i = 2; i < n; i++) {
            step = third + (third-second) - (second-first);
            first = second; second = third; third = step;
            if ((first == 0) && (second == 1) && (third == -1)) {
                n = n % (i-1);
                if (n == 0) return 0;
                if (n == 1) return 1;
                if (n == 2) return -1;
                first = 0; second = 1; third = -1;
                for (int j = 2; j < n; j++) {
                    step = third + (third-second) - (second-first);
                    first = second; second = third; third = step;
                } 
                return step;
            }
        } 
        return step;        
    }
};


int main(int argc, char** argv)
{
    cout << Algorithm::getPositionAt(3) << endl; // -4 
    cout << Algorithm::getPositionAt(100000) << endl; // -5
    cout << Algorithm::getPositionAt(2147483647) << endl; // 1
    return 0;
}
