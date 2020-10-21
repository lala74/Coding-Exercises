#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

#include "Life.h"

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