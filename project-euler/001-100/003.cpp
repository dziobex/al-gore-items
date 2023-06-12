#include <iostream>

using namespace std;

#define ull unsigned long long

/*
600851475143
*/

ull number = 600851475143;

bool nprimes[775200]{};

void sieve() {
    nprimes[0] = nprimes[1] = true;

    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            for (int j = i * 2; j * j <= number; j += i) {
                nprimes[j] = true;
            }
        }
    }
}

int main () {
    ull maxP = 0;

    sieve();

    for (int i = 2; i * i <= number; ++i)
        if (number % i == 0 && !nprimes[i])
            maxP = i;

    cout << maxP;

    return 0;
}