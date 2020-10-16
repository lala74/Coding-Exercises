#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Variable
    string result;
    uint T;

    // Input
    cin >> T;
    for(uint caseNb = 1; caseNb <= T; ++caseNb) {
        uint NG, NM;
        uint godzillaMax = 0;
        uint mechaGodzillaMax = 0;

        cin >> NG >> NM;
        for(uint i = 0; i < NG; ++i) {
            uint godzillaStrength;
            cin >> godzillaStrength;
            godzillaMax = max(godzillaMax, godzillaStrength);
        }
        for(uint i = 0; i < NM; ++i) {
            uint mechaGodzillaStrength;
            cin >> mechaGodzillaStrength;
            mechaGodzillaMax = max(mechaGodzillaMax, mechaGodzillaStrength);
        }

        // Main
        if (godzillaMax >= mechaGodzillaMax) {
            result += "Godzilla\n";
        } else {
            result += "MechaGodzilla\n";
        }
    }

    // Output
    cout << result;

    return 0;
}