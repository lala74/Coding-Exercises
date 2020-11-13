#include <time.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const uint cSquareSize = 3;
uint cSum = 9;

const uint cMin = 0;
uint cMax = cSum;

uint a, b, c;
uint d, e, f;
uint g, h, i;

bool is_valid()
{
    if((a + b + c) != cSum) return false;
    if((d + e + f) != cSum) return false;
    if((g + h + i) != cSum) return false;
    if((a + d + g) != cSum) return false;
    if((b + e + h) != cSum) return false;
    if((c + f + i) != cSum) return false;
    if((a + e + i) != cSum) return false;
    if((c + e + g) != cSum) return false;

    return true;
}

void print_result()
{
    cout << "------------" << endl;
    cout << a << " " << b << " " << c << endl;
    cout << d << " " << e << " " << f << endl;
    cout << g << " " << h << " " << i << endl;
}

int main(int argc, char** argv)
{
    clock_t tStart = clock();
    // Variables
    string result;
    uint countResult = 0;
    uint countLoop = 0;
    // Main
    if (argc == 2){
        string str(argv[1]);
        cSum = stoi(str);
        cMax = cSum;
    }

    for(a = cMin; a <= cMax; ++a) {
        for(b = cMin; b <= cMax - a; ++b) {                                 // limit max b
            c = cSum - a - b;                                               // calculate c from a and b
            for(d = cMin; d <= cMax - a; ++d) {                             // limit max d
                uint maxE = (cMax - d) < (cMax - b) ? cMax - d : cMax - b;  // choose to limit max e by d or b
                for(e = cMin; e <= maxE; ++e) {
                    f = cSum - d - e;
                    // Calculate g h i
                    g = cSum - a - d;
                    h = cSum - b - e;
                    i = cSum - c - f;

                    if(is_valid()) {
                        ++countResult;
                        print_result();
                    }
                    ++countLoop;
                }
            }
        }
    }

    // Output
    cout << "Count result: " << countResult << endl;
    cout << "Count loop  : " << countLoop << endl;

    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}