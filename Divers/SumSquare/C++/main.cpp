#include <time.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const uint cSquareSize = 3;
uint cSum = 9;

const uint cMin = 0;
uint cMax = cSum;

uint square[cSquareSize][cSquareSize] = {{3, 3, 3}, {3, 3, 3}, {3,3,3}};

bool is_valid()
{
    uint sumRows[cSquareSize] = {0};
    uint sumCols[cSquareSize] = {0};
    for(uint row = 0; row < cSquareSize; ++row) {
        for(uint col = 0; col < cSquareSize; ++col) {
            uint value = square[row][col];
            sumRows[row] += value;
            sumCols[col] += value;

            if(row == cSquareSize - 1) {
                if(sumCols[col] != cSum) return false;
            }
            if(col == cSquareSize - 1) {
                if(sumRows[row] != cSum) return false;
            }
        }
    }
    return true;
}

void print_result()
{
    cout << "------------" << endl;
    for(uint row = 0; row < cSquareSize; ++row) {
        for(uint col = 0; col < cSquareSize; ++col) {
            uint value = square[row][col];
            cout << value << " ";
        }
        cout << '\n';
    }
}

int main(int argc, char** argv)
{
    clock_t tStart = clock();
    // Variables
    string result;
    uint countResult = 0;
    uint countLoop = 0;
    // Main
    if(argc == 2) {
        string str(argv[1]);
        cSum = stoi(str);
        cMax = cSum;
    }

    if (is_valid()) {
        print_result();
    }

    // Output
    cout << "------------" << endl;
    cout << "Count result: " << countResult << endl;
    cout << "Count loop  : " << countLoop << endl;

    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}