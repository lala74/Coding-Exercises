#include <time.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int find_min(int arr[], int length)
{
    int min = 0;
    bool foundFirstPositiveValue = false;
    for(int i = 1; i < length; ++i) {
        if(foundFirstPositiveValue) {
            if(arr[i] >= 0) {
                min = (arr[i] < min ? arr[i] : min);
            }
        } else {
            if(arr[i] >= 0) {
                min = arr[i];
                foundFirstPositiveValue = true;
            }
        }
    }
    return min;
}

int calculate_number_of_coin_min(int n, int S, int setOfWeigh[])
{
    int weightTable[S + 1];
    int compareTable[n];

    weightTable[0] = 0;

    for(int weight = 1; weight < S + 1; ++weight) {
        for(int iSetOfWeight = 0; iSetOfWeight < n; ++iSetOfWeight) {
            if(weight >= setOfWeigh[iSetOfWeight]) {
                compareTable[iSetOfWeight] = weightTable[weight - setOfWeigh[iSetOfWeight]];
            } else {
                compareTable[iSetOfWeight] = -1;
            }
        }
        weightTable[weight] = find_min(compareTable, n) + 1;
    }

    // for(int i = 0; i < S + 1; ++i) {
    //     printf("%2d:", i);
    // }
    // cout << '\n';
    // for(int i = 0; i < S + 1; ++i) {
    //     printf("%2d:", weightTable[i]);
    // }
    // cout << '\n';

    return weightTable[S];
}

int main(int argc, char** argv)
{
    clock_t tStart = clock();

    // Variables
    int result;
    int n, S;

    // Input
    cin >> n;
    int setOfWeigh[n];
    for(int i = 0; i < n; ++i) {
        cin >> setOfWeigh[i];
    }
    cin >> S;

    result = calculate_number_of_coin_min(n, S, setOfWeigh);

    // Main

    // Output
    cout << result << endl;
    cout << "------------" << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}