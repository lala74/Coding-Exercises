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

struct Vector3
{
    float mx = 0.0f;
    float my = 0.0f;
    float mz = 0.0f;

    ~Vector3() { cout << "Destroy" << endl; }
    Vector3() {}
    Vector3(float x)
        : mx(x)
        , my(x)
        , mz(x)
    {}
    Vector3(float x, float y, float z)
        : mx(x)
        , my(y)
        , mz(z)
    {}
    Vector3(const Vector3& v)
        : mx(v.mx)
        , my(v.my)
        , mz(v.mz)
    {
        cout << "Copy constructor" << endl;
    }
    Vector3(Vector3&& v)
        : mx(v.mx)
        , my(v.my)
        , mz(v.mz)
    {
        cout << "Move constructor" << endl;
    }
    Vector3& operator=(const Vector3& v)
    {
        cout << "Copy" << endl;
        mx = v.mx;
        my = v.my;
        mz = v.mz;
        return *this;
    }
    Vector3& operator=(Vector3&& v)
    {
        cout << "Move" << endl;
        mx = v.mx;
        my = v.my;
        mz = v.mz;
        return *this;
    }
};

template<class T>
void PrintVector(Vector<T> v)
{
    for (int i = 0; i < v.Size(); i++) {
        cout << i << ":" << v[i] << " ";
    }
    cout << "\n";
}

void PrintVector3(Vector<Vector3> v)
{
    for (size_t i = 0; i < v.Size(); ++i) {
        cout << "[" << v[i].mx << "," << v[i].my << "," << v[i].mz << "]"
             << endl;
    }
    cout << "----------------------------" << endl;
}

int main(int argc, char** argv)
{
    // Avoid warning
    argc = 0;
    argv = nullptr;
    // Running time
    Duration duration;

    // Variables
    Vector<Vector3> vector;
    vector.PushBack(Vector3(1.0f));
    vector.PushBack(Vector3(1.0f, 2.0f, 3.0f));
    vector.PushBack(Vector3(1.0f, 5.0f, 3.0f));
    vector.PushBack(Vector3());
    PrintVector3(vector);

    // vector.Clear();
    // PrintVector(vector);

    // Main

    // Output
    //
    // Memory usage
    return 0;
}
