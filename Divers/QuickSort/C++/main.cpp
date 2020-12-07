#include <time.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Sort array to 2 parties (one is smaller/equal than pivot, one is larger than pivot)
int partition(int arr[], uint leftIndex, uint rightIndex)
{
    uint i = leftIndex;
    int pivot = arr[leftIndex];  // choose pivot to be the first element of array

    for(uint j = leftIndex + 1; j <= rightIndex; ++j) {  // iterate through all array with j
        if(arr[j] <= pivot) {
            swap(&arr[++i], &arr[j]);  // swap element smaller than pivot with the element at index i
        }
    }
    swap(&arr[leftIndex], &arr[i]);  // swap pivot to the last element of first party (smaller)
    return i;
}

void quicksort(int arr[], uint leftIndex, uint rightIndex)
{
    uint index;

    if(leftIndex < rightIndex) {
        index = partition(arr, leftIndex, rightIndex);
        quicksort(arr, leftIndex, index);
        quicksort(arr, index + 1, rightIndex);
    }
}

int main(int argc, char** argv)
{
    clock_t tStart = clock();

    // Variables
    stringstream result;
    uint N;

    // Input
    cin >> N;
    int arr[N];
    for(uint i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Main
    quicksort(arr, 0, N - 1);

    for(uint i = 0; i < N; ++i) {
        result << arr[i] << " ";
    }

    // Output
    cout << result.str() << endl;
    cout << "------------" << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}