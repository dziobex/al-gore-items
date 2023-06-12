#include <iostream>

using namespace std;

#define ull unsigned long long

bool isprime(int n) {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main () {

    ull maxPow = 0, what = 0;

    for (int n = 7; n < 1000; ++n) {
        if (!isprime(n))
            continue;
        
        ull p = 1, pow = 10;

        while (pow % n != 1) {
            ++p;
            pow = (pow % n) * 10;
        }

        if (p > maxPow) {
            what = n;
            maxPow = p;
        }
    }

    cout << what;

    return 0;
}