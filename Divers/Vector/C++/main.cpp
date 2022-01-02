#include <time.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "Duration.h"
#include "Vector.h"

using namespace std;
using namespace std::chrono;

const int limit = 1e4 * 2;

template <class T>
void PrintVector(Vector<T> v)
{
    for (int i = 0; i < v.Size(); i++) {
        cout << i << ":" << v[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char** argv)
{
    // Avoid warning
    argc = 0;
    argv = nullptr;
    // Running time
    Duration duration;

    // Variables
    Vector<int> vector;
    for (int i = 0; i < limit; i++) {
        vector.PushBack(i * 2);
    }
    for (int i = 0; i < limit + 1; i++) {
        vector.PopBack();
    }
    for (int i = 0; i < limit; i++) {
        vector.PushBack(i * 3);
    }
    // vector.Clear();
    // PrintVector(vector);

    // Main

    // Output
    //
    // Memory usage
    return 0;
}
