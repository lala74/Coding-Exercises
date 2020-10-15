#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reduce_examination_range(vector<pair<uint, uint>> hatches, uint S, uint* minX, uint* maxX, uint* minY, uint* maxY);
pair<uint, uint> find_leash_position(vector<pair<uint, uint>> hatches, uint S, uint minX, uint maxX, uint minY, uint maxY);
bool are_all_hatches_in_range(vector<pair<uint, uint>> hatches, uint S, uint X, uint Y);
bool is_hatch_in_range(pair<uint, uint> hatch, uint S, uint X, uint Y);

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
        pair<uint, uint> leashPos;

        cin >> S >> H;
        for(int hatchNb = 1; hatchNb <= H; ++hatchNb) {
            uint X, Y;
            cin >> X >> Y;
            hatches.push_back(make_pair(X, Y));
        }

        // Main
        reduce_examination_range(hatches, S, &minX, &maxX, &minY, &maxY);
        leashPos = find_leash_position(hatches, S, minX, maxX, minY, maxY);

        if(leashPos.first <= S) {
            result += to_string(leashPos.first) + " " + to_string(leashPos.second) + "\n";
        } else {
            result += "poodle\n";
        }
    }

    // Output
    cout << result << endl;

    return 0;
}

void reduce_examination_range(vector<pair<uint, uint>> hatches, uint S, uint* minX, uint* maxX, uint* minY, uint* maxY)
{
    uint tmpMinX, tmpMaxX, tmpMinY, tmpMaxY;
    *minX = 0;
    *maxX = S;
    *minY = 0;
    *maxY = S;
    for(auto hatch : hatches) {
        uint X, Y;
        X = hatch.first;
        Y = hatch.second;

        tmpMinX = X / 2;
        tmpMaxX = (X + S) / 2;
        tmpMinY = Y / 2;
        tmpMaxY = (Y + S) / 2;

        if(tmpMinX > *minX) *minX = tmpMinX;
        if(tmpMaxX < *maxX) *maxX = tmpMaxX;
        if(tmpMinY > *minY) *minY = tmpMinY;
        if(tmpMaxY < *maxY) *maxY = tmpMaxY;
    }
}

pair<uint, uint> find_leash_position(vector<pair<uint, uint>> hatches, uint S, uint minX, uint maxX, uint minY, uint maxY)
{
    uint X, Y;

    bool found = false;
    for(X = minX; X <= maxX; ++X) {
        for(Y = minY; Y <= maxY; Y++) {
            if(are_all_hatches_in_range(hatches, S, X, Y)) {
                return make_pair(X, Y);
            }
        }
    }
    return make_pair(S + 1, S + 1);
}

bool are_all_hatches_in_range(vector<pair<uint, uint>> hatches, uint S, uint X, uint Y)
{
    for(auto hatch : hatches) {
        if((X == hatch.first) && (Y == hatch.second)) {
            return false;
        }
        if(!is_hatch_in_range(hatch, S, X, Y)) {
            return false;
        }
    }
    return true;
}

bool is_hatch_in_range(pair<uint, uint> hatch, uint S, uint X, uint Y)
{
    uint minDistanceToBorder = min(min(X, S - X), min(Y, S - Y));
    double distanceToHatch = sqrt(pow(abs(int(X - hatch.first)), 2) + pow(abs(int(Y - hatch.second)), 2));
    return distanceToHatch <= minDistanceToBorder;
}