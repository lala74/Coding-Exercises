#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "Duration.h"

using namespace std;
using namespace std::chrono;

typedef vector<int> Ints;

int square(int x)
{
    return x * x;
}

Ints ranged_base_loop(const Ints& xs)
{
    Ints ys;

    for (auto x : xs) {
        ys.push_back(square(x));
    }
    return ys;
}

Ints std_transform(const Ints& xs)
{
    Ints ys;

    transform(begin(xs), end(xs), back_inserter(ys), square);
    return ys;
}

template <typename F, typename T>
vector<T> transform_vec(F f, vector<T> xs)
{
    vector<T> ys;
    transform(begin(xs), end(xs), back_inserter(ys), f);
    return ys;
}

int main(int argc, char** argv)
{
    Duration duration;  // calculate running time
    // avoid warning
    argc = 0;
    argv = nullptr;
    //
    Ints xs = { 1, 2, 3, 4 };
    // Ints ys = ranged_base_loop(xs);
    // Ints ys = std_transform(xs);
    Ints ys = transform_vec(square, xs);
    
    for (auto y : ys) {
        cout << y << " ";
    }
    cout << endl;


    // vector<int>::iterator ait;

    // Memory usage
    return 0;
}
