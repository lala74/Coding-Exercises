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
int partition(int arr[], int leftIndex, int rightIndex)
{
    int i = leftIndex;
    int pivot = arr[leftIndex];  // choose pivot to be the first element of array

    for(int j = leftIndex + 1; j <= rightIndex; ++j) {  // iterate through all array with j
        if(arr[j] <= pivot) {
            swap(&arr[++i], &arr[j]);  // swap element smaller than pivot with the element at index i+1
        }
    }
    swap(&arr[leftIndex], &arr[i]);  // swap pivot to the last element of first party (smaller)
    return i;
}

void quicksort(int arr[], int leftIndex, int rightIndex)
{
    if(leftIndex < rightIndex) {
        int index;
        index = partition(arr, leftIndex, rightIndex);
        quicksort(arr, leftIndex, index - 1);
        quicksort(arr, index + 1, rightIndex);
    }
}

int main(int argc, char** argv)
{
    clock_t tStart = clock();

    // Variables
    stringstream result;
    int N;

    // Input
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Main
    quicksort(arr, 0, N - 1);

    for(int i = 0; i < N; ++i) {
        result << arr[i] << " ";
    }

    // Output
    cout << result.str() << endl;
    cout << "------------" << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}