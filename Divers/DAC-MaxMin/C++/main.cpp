#include <time.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int DAC_max(int arr[], int leftIndex, int rightIndex)
{
    int max, firstElement;

    if((rightIndex - leftIndex) == 1) {
        // There are only 2 elements in subarray
        return (arr[rightIndex] > arr[leftIndex] ? arr[rightIndex] : arr[leftIndex]);
    }

    firstElement = arr[leftIndex];
    max = DAC_max(arr, leftIndex + 1, rightIndex);

    return (firstElement > max ? firstElement : max);
}

int DAC_min(int arr[], int leftIndex, int rightIndex)
{
    int min, firstElement;

    if((rightIndex - leftIndex) == 1) {
        // There are only 2 elements in subarray
        return (arr[rightIndex] < arr[leftIndex] ? arr[rightIndex] : arr[leftIndex]);
    }

    firstElement = arr[leftIndex];
    min = DAC_min(arr, leftIndex + 1, rightIndex);

    return (firstElement < min ? firstElement : min);
}

int main(int argc, char** argv)
{
    clock_t tStart = clock();

    // Variables
    int min, max;
    int N;

    // Input
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Main
    min = DAC_min(arr, 0, N - 1);
    max = DAC_max(arr, 0, N - 1);

    // Output
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "------------" << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}