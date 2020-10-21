#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template <class Entry>
class Temp
{
public:
    Temp();
    ~Temp();

private:
    Entry TempMember;
};