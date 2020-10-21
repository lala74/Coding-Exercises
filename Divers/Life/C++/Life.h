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