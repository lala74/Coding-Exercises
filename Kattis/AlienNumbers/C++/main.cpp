#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

// main idea
// convert alien number of source language to base 10
// convert base 10 number to target language

int alien_number_to_base10(string alienNb, string srcLng)
{
    int base10 = 0;
    uint baseNbOfSrcLng = srcLng.length();
    uint lenOfAlienNb = alienNb.length();

    // Iterate through all digit of alienNb
    for(uint i = 0; i < lenOfAlienNb; ++i) {
        char digit = alienNb[i];
        uint digitPosInNumber = lenOfAlienNb - i - 1;
        uint digitPosInLng = srcLng.find(digit);

        base10 += pow(baseNbOfSrcLng, digitPosInNumber) * digitPosInLng;
    }

    return base10;
}

string base10_to_alien_number(int base10, string srcLng)
{
    string alienNb;
    int resultAfterDivision, remainder;
    int baseNbOfSrcLng = srcLng.length();

    resultAfterDivision = base10;
    while(resultAfterDivision > 0) {
        remainder = resultAfterDivision % baseNbOfSrcLng;
        resultAfterDivision /= baseNbOfSrcLng;
        alienNb += srcLng[remainder];
    }
    reverse(alienNb.begin(), alienNb.end());

    return alienNb;
}

int main()
{
    uint T;
    string result;

    cin >> T;

    for(int caseNb = 1; caseNb <= T; ++caseNb) {
        string alienNb, srcLng, targetLng;
        int base10;
        string alienNbInTargetLng;

        cin >> alienNb;
        cin >> srcLng;
        cin >> targetLng;

        base10 = alien_number_to_base10(alienNb, srcLng);
        alienNbInTargetLng = base10_to_alien_number(base10, targetLng);

        result += "Case #" + to_string(caseNb) + ": " + alienNbInTargetLng + "\n";
    }

    cout << result;

    return 0;
}