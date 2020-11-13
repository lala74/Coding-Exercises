#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>

using namespace std;

const uint cSquareSize = 3;
const uint cSum = 9;

const uint cMin = 0;
const uint cMax = cSum;

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
    // Variable
    string result;
    uint count = 0;
    for(a = cMin; a <= cMax; ++a) {
        for(b = cMin; b <= cMax; ++b) {
            for(c = cMin; c <= cMax; ++c) {
                for(d = cMin; d <= cMax; ++d) {
                    for(e = cMin; e <= cMax; ++e) {
                        for(f = cMin; f <= cMax; ++f) {
                            for(g = cMin; g <= cMax; ++g) {
                                for(h = cMin; h <= cMax; ++h) {
                                    for(i = cMin; i <= cMax; ++i) {
                                        if(is_valid()) {
                                            count++;
                                            print_result();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Main

    // Output
    cout << "count: " << count << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}