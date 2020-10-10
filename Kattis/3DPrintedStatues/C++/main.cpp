#include <iostream>

using namespace std;

int main()
{
    uint n = 0;
    uint days = 1;
    uint nbPrinters = 1;
    
    cin >> n;
    
    while (n > nbPrinters) {
        nbPrinters *= 2;
        days += 1;
    }

    cout << days;

    return 0;
}