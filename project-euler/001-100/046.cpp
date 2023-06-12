#include <iostream>
#include <math.h>

using namespace std;

const int LIM = 10000;

bool sieve[LIM + 1]{};

int main () {

    sieve[0] = sieve[1] = true;

    for (int i = 2; i * i <= LIM; ++i)
        if (!sieve[i])
            for (int j = i * 2; j <= LIM; j += i)
                sieve[j] = true;

    for (int i = 11; i <= LIM; i += 2) {

        bool found = false;
        for (int j = i; j >= 2; --j) {
            if (sieve[j])
                continue;

            int trans = (i - j) / 2;
            int sq = sqrt(trans);

            if (sq * sq == trans) {
                found = true;
                break;
            }
        }

        if (!found) {
            cout << i;
            break;
        }
    }

    return 0;
}