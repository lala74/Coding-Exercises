#include <time.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

uint BinarySearch(int arr[], uint leftIndex, uint rightIndex, int valueToFind)
{
    uint index;
    uint midIndex = (leftIndex + rightIndex) / 2;

    if(valueToFind == arr[midIndex]) {
        return midIndex;
    }
    if(valueToFind > arr[midIndex]) {
        leftIndex = midIndex + 1;
    } else {
        rightIndex = midIndex - 1;
    }
    index = BinarySearch(arr, leftIndex, rightIndex, valueToFind);

    return index;
}

int main(int argc, char** argv)
{
    clock_t tStart = clock();

    // Variables
    int result = 0;
    int N, K;

    // Input
    cin >> N >> K;
    int arr[N];
    for(int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Main
    result = BinarySearch(arr, 0, N - 1, K);

    // Output
    cout << result << endl;
    cout << "------------" << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}