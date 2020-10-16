#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<string> dict;
    string result;
    string word;

    // Input
    while(cin >> word) {
        string wordLowerCase;

        for(auto c : word) {
            wordLowerCase += tolower(c);
        }

        if(dict.find(wordLowerCase) == dict.end()) {
            dict.insert(wordLowerCase);
            result += word + " ";
        } else {
            result += ". ";
        }

        if(cin.peek() == '\n') {
            result += "\n";
        }
    }

    cout << result;

    return 0;
}