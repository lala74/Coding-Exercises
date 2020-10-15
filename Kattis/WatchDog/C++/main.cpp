#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    string result, test;
    uint N;
    // Input
    cin >> N;
    for(int caseNb = 1; caseNb <= N; ++caseNb) {
        uint S, H;
        uint minX, maxX, minY, maxY;
        vector<pair<uint, uint>> hatches;
        bool found = false;

        cin >> S >> H;
        minX = 0;
        maxX = S;
        minY = 0;
        maxY = S;
        for(int hatchNb = 1; hatchNb <= H; ++hatchNb) {
            uint X, Y;
            uint tmpMinX, tmpMaxX, tmpMinY, tmpMaxY;

            cin >> X >> Y;
            pair<uint, uint> hatch;
            hatch.first = X;
            hatch.second = Y;
            hatches.push_back(hatch);

            // Main
            tmpMinX = X / 2;
            tmpMaxX = (X + S) / 2;
            tmpMinY = Y / 2;
            tmpMaxY = (Y + S) / 2;
            if(tmpMinX > minX) minX = tmpMinX;
            if(tmpMaxX < maxX) maxX = tmpMaxX;
            if(tmpMinY > minY) minY = tmpMinY;
            if(tmpMaxY < maxY) maxY = tmpMaxY;

            // test += "S:" + to_string(S) + " H:" + to_string(H) + " X:" + to_string(X) + " Y:" + to_string(Y) + "\n";
            // test += "tmpMinX:" + to_string(tmpMinX) + " minX:" + to_string(minX) + "\n";
            // test += "tmpMaxX:" + to_string(tmpMaxX) + " maxX:" + to_string(maxX) + "\n";
            // test += "tmpMinY:" + to_string(tmpMinY) + " minY:" + to_string(minY) + "\n";
            // test += "tmpMaxY:" + to_string(tmpMaxY) + " maxY:" + to_string(maxY) + "\n";
        }
        result += "Case #" + to_string(caseNb) + ": ";
        result += " MinX:" + to_string(minX) + " MaxX:" + to_string(maxX) + " MinY:" + to_string(minY) +
                  " MaxY:" + to_string(maxY) + "\n";
        // for(int x=minX; x <= maxX; ++x) {
        //     for(int y=)
        // }
    }

    // Output
    cout << result << endl;
    // cout << "Test: " << test;

    return 0;
}