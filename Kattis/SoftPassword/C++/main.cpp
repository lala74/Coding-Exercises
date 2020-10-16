#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

char reverse_case_char(char c);
string reverse_case(const string& str);
bool check_first_condition(const string& S, const string& P);
bool check_second_condition(const string& S, const string& P);
bool check_third_condition(const string& S, const string& P);
bool check_forth_condition(const string& S, const string& P);
bool check_all_conditions(const string& S, const string& P);

int main()
{
    // Variables
    string S, P;
    string result;

    // Input
    cin >> S >> P;

    if(check_all_conditions(S, P) == true) {
        result = "Yes";
    } else {
        result = "No";
    }

    // Ouput
    cout << result << endl;

    return 0;
}

char reverse_case_char(char c)
{
    const auto uc = static_cast<unsigned char>(c);  // Sic.
    return ::isupper(uc) ? ::tolower(uc) : ::toupper(uc);
}

string reverse_case(const string& str)
{
    string reversedStr;
    for(auto c : str) {
        reversedStr += reverse_case_char(c);
    }
    return reversedStr;
}

bool check_first_condition(const string& S, const string& P)
{
    if(P == S) {
        return true;
    }
    return false;
}

bool check_second_condition(const string& S, const string& P)
{
    uint sizeS = S.size();
    if(('0' <= S[0]) && (S[0] <= '9')) {
        string erasedS;
        erasedS = S.substr(1, sizeS - 1);
        if(erasedS == P) {
            return true;
        }
    }
    return false;
}

bool check_third_condition(const string& S, const string& P)
{
    uint sizeS = S.size();
    if(('0' <= S[sizeS - 1]) && (S[sizeS - 1] <= '9')) {
        string erasedS;
        erasedS = S.substr(0, sizeS - 1);
        if(erasedS == P) {
            return true;
        }
    }
    return false;
}

bool check_forth_condition(const string& S, const string& P)
{
    if(S == reverse_case(P)) {
        return true;
    }
    return false;
}

bool check_all_conditions(const string& S, const string& P)
{
    return (check_first_condition(S, P) || check_second_condition(S, P) || check_third_condition(S, P) || check_forth_condition(S, P));
}