#include <iostream>

using namespace std;

bool isprime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int primes(int a, int b) {
    int counter = 0;

    for (int n = 0; ; ++n) {
        int eq = n*n + n*a + b;

        if (isprime(eq))
            ++counter;
        else
            break;
    }

    return counter;
}

int main () {

    int maxprimes = 0, ab = 0;

    for (int b = 2; b < 1000; ++b) {
        for (int a = -999; a < 1000; ++a) {
            int pc = primes(a, b);

            if (pc > maxprimes) {
                maxprimes = pc;
                ab = a * b;
            }
        }
    }

    cout << ab;

    return 0;
}