#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

// 3 bottles of milk on the wall, 3 bottles of milk.
// Take one down, pass it around, 2 bottles of milk on the wall.

// 2 bottles of milk on the wall, 2 bottles of milk.
// Take one down, pass it around, 1 bottle of milk on the wall.

// 1 bottle of milk on the wall, 1 bottle of milk.
// Take it down, pass it around, no more bottles of milk.

using namespace std;

const string bottleInPlural = "bottles";
const string bottleInSingle = "bottle";

std::string replace_all(std::string& str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();  // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

string bottle_of_beverage_according_to_number(uint bottleNb, string beverage)
{
    stringstream str;
    string bottleFormat;
    if(bottleNb > 1) {
        bottleFormat = bottleInPlural;
    } else {
        bottleFormat = bottleInSingle;
    }
    str << bottleNb << " " << bottleFormat << " of " << beverage;
    return str.str();
}

string verse_according_to_number(uint bottleNb, string beverage)
{
    string firstLine = "$chain on the wall, $chain.";
    string secondLine;

    replace_all(firstLine, "$chain", bottle_of_beverage_according_to_number(bottleNb, beverage));
    if(bottleNb > 1) {
        secondLine = "Take one down, pass it around, $chain on the wall.";
        replace_all(secondLine, "$chain", bottle_of_beverage_according_to_number(bottleNb - 1, beverage));
    } else {
        secondLine = "Take it down, pass it around, no more bottles of " + beverage + ".";
    }
    return (firstLine + '\n' + secondLine + '\n');
}

int main()
{
    // Variable
    string result;
    uint N;
    string beverage;

    // Input
    cin >> N >> beverage;
    // Main
    for(uint i = N; i >= 1; --i) {
        result += verse_according_to_number(i, beverage) + '\n';
    }

    // Output
    cout << result << endl;

    return 0;
}