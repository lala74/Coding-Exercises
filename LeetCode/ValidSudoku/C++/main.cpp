#include <proc/readproc.h>
#include <time.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for(int r = 0; r < 9; ++r) {
            unordered_set<char> row;
            for(int c = 0; c < 9; ++c) {
                if(board[r][c] != '.') {
                    if(row.find(board[r][c]) != row.end()) {
                        // cout << "False in row" << endl;
                        return false;
                    } else {
                        row.insert(board[r][c]);
                    }
                }
            }
        }

        for(int c = 0; c < 9; ++c) {
            unordered_set<char> col;
            for(int r = 0; r < 9; ++r) {
                if(board[r][c] != '.') {
                    if(col.find(board[r][c]) != col.end()) {
                        // cout << "False in col" << endl;
                        return false;
                    } else {
                        col.insert(board[r][c]);
                    }
                }
            }
        }

        for (int center_row = 1; center_row <= 7; center_row+=3) {
            for (int center_col = 1; center_col <= 7; center_col+=3) {
                if (check_sub_boxes(board, center_row, center_col) ==  false) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool check_sub_boxes(vector<vector<char>>& board, int center_row, int center_col)
    {
        unordered_set<char> subboxes;
        for(int r = center_row - 1; r <= center_row + 1; ++r) {
            for(int c = center_col - 1; c <= center_col + 1; ++c) {
                if(board[r][c] != '.') {
                    if(subboxes.find(board[r][c]) != subboxes.end()) {
                        // cout << "False in subboxes" << endl;
                        return false;
                    } else {
                        subboxes.insert(board[r][c]);
                    }
                }
            }
        }
        return true;
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    bool result;

    // Input
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    // Main
    Solution solution;
    result = solution.isValidSudoku(board);

    // Output
    cout << result << endl;
    // Runtime
    cout << "------------" << endl;
    printf("Time taken  : %.2f s\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    // Memory usage
    look_up_our_self(&usage);
    printf("Memory usage: %.2f MB\n", static_cast<float>(usage.vsize) / 1024 / 1024);
    return 0;
}