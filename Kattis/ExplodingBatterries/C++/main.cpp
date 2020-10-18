#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Variable
    string result;
    int current = -1;

    // Input
    while(current != 0) {
        cin >> current;

        // Main
        for(int testNb = 0; testNb <= 13; ++testNb) {
            if (pow(2, testNb) >= current) {
                result += to_string(testNb) + "\n";
                break;
            }
        }
    }

    // Output
    cout << result;

    return 0;
}