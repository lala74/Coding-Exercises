#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Class template and function definition must be in the same file
// https://stackoverflow.com/questions/115703/storing-c-template-function-definitions-in-a-cpp-file
// https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
// https://www.codeproject.com/Articles/48575/How-to-Define-a-Template-Class-in-a-h-File-and-Imp

template <class Entry>
class Temp
{
public:
    Temp();
    ~Temp();

private:
    Entry TempMember;
};

template <class Entry>
Temp<Entry>::Temp()
{

}

template <class Entry>
Temp<Entry>::~Temp()
{

}
