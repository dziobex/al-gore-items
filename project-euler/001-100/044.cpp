#include <iostream>
#include <math.h>

using namespace std;

#define ull unsigned long long

bool ispentagonal (ull n) {
    ull eq = 24 * n + 1;
    ull sq = sqrt(eq);

    if (sq * sq != eq)
        return false;
    return (sq+1) % 6 == 0;
}

int main () {

    bool found = false;
    
    for (ull i = 1; !found; ++i) {
        ull a = i * (3 * i - 1) / 2;

        for (ull j = 1; ((j < i) && !found); ++j) {
            ull b = j * (3 * j - 1) / 2;

            if (ispentagonal(a + b) && ispentagonal(a - b)) {
                cout << a - b;
                found = true;
                break;
            }
        }
    }

    return 0;
}