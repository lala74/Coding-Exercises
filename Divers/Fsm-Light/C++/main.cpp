#include <time.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "Light.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv)
{
    auto startTime = steady_clock::now();

    // Variables
    Light light;
    light.Toggle();
    light.Toggle();
    light.Toggle();
    light.Toggle();
    light.Toggle();

    // Input

    // Main

    // Output
    //
    //
    //
    // Runtime
    cout << "------------" << endl;
    auto finishTime = steady_clock::now();
    auto runtime = finishTime - startTime;
    cout << "Runtime: " << duration_cast<seconds>(runtime).count() << "ms" << endl;
    // Memory usage
    return 0;
}
