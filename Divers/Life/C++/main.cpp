#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const char dead = '-';
const char live = '+';

class Life
{
public:
    Life(){};
    ~Life(){};

    void initialize();
    void update();
    string grid_export();

    uint getCycleNb() { return cycleNb; }
    uint getPeriodMs() { return periodMs; }

private:
    void update_count_grind();
    uint count_live_neighbor(uint r, uint c);

private:
    vector<vector<char>> grid;       // grid with all input value
    vector<vector<int>> count_grid;  // grid contain number of live neighbor cell
    uint Rmax, Cmax, cycleNb, periodMs;
};

void Life::initialize()
{
    cin >> Rmax >> Cmax >> cycleNb >> periodMs;
    // Initialize a grid with size (r+2)x(c+2)
    grid.resize(Rmax + 2);
    count_grid.resize(Rmax + 2);
    for(uint i = 0; i < Rmax + 2; ++i) {
        grid[i].resize(Cmax + 2);
        count_grid[i].resize(Cmax + 2);
    }
    // Initialize value for grid
    for(uint r = 0; r < Rmax + 2; ++r) {
        for(uint c = 0; c < Cmax + 2; ++c) {
            if((r == 0) || (c == 0) || (r == Rmax + 1) || (c == Cmax + 1)) {
                // The values of borders are .
                grid[r][c] = dead;
            } else {
                // The values of the other is input
                cin >> grid[r][c];
            }
        }
    }
}

void Life::update()
{
    update_count_grind();

    for(uint r = 1; r < Rmax + 1; ++r) {
        for(uint c = 1; c < Cmax + 1; ++c) {
            char* cellStatus = &grid[r][c];
            uint liveCellNeighbor = count_grid[r][c];

            if(liveCellNeighbor == 2) {
                continue;
            } else if (liveCellNeighbor == 3) {
                *cellStatus = live;
            } else {
                *cellStatus = dead;
            }
        }
    }
}

void Life::update_count_grind()
{
    for(uint r = 1; r < Rmax + 1; ++r) {
        for(uint c = 1; c < Cmax + 1; ++c) {
            count_grid[r][c] = count_live_neighbor(r, c);
        }
    }
}

uint Life::count_live_neighbor(uint r, uint c)
{
    uint count = 0;

    for(uint x = r - 1; x <= r + 1; ++x) {
        for(uint y = c - 1; y <= c + 1; ++y) {
            if((x != r) || (y != c)) {
                if(grid[x][y] == live) {
                    count += 1;
                }
            }
        }
    }
    return count;
}

string Life::grid_export()
{
    string result;

    for(uint r = 1; r < Rmax + 1; ++r) {
        for(uint c = 1; c < Cmax + 1; ++c) {
            result += grid[r][c];
            result += ' ';
        }
        result += '\n';
    }
    return result;
}

int main()
{
    // Variable
    string result;
    Life life;

    // Input
    life.initialize();

    // Main
    for(uint cycle = 1; cycle <= life.getCycleNb(); ++cycle) {
        cout << "Generation " << cycle << endl;
        life.update();
        cout << life.grid_export() << endl;
        usleep(life.getPeriodMs() * 1000);
    }

    // Output
    cout << result << endl;

    return 0;
}