#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int sizeOrder = 3;

// A < B < C

void print_correspond_number(char letter, vector<int> numbers)
{
    if(letter == 'A') {
        cout << numbers.at(2);
    } else if(letter == 'B') {
        cout << numbers.at(1);
    } else if(letter == 'C') {
        cout << numbers.at(0);
    }
}

int main()
{
    vector<int> numbers;
    string order;

    // Input
    for(int i = 0; i < sizeOrder; ++i) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    cin >> order;

    // Main
    sort(numbers.rbegin(), numbers.rend());
    for(int i = 0; i < sizeOrder; ++i) {
        print_correspond_number(order[i], numbers);
        if (i != sizeOrder - 1) {
            cout << " ";
        }
    }

    return 0;
}