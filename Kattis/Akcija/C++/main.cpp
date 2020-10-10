#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    uint N;
    vector<uint> prices;
    uint total = 0;

    cin >> N;

    for(int i = 0; i < N; i++) {
        uint price;
        cin >> price;
        prices.push_back(price);
    }

    sort(prices.rbegin(), prices.rend());

    for(int i = 0; i < N; i++) {
        if(i % 3 != 2) {
            total += prices.at(i);
        }
    }

    cout << total;

    return 0;
}