#include <iostream>
#include <vector>

using namespace std;

bool isprime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

const int LIM = 1000000;
bool sieve[LIM+2]{};

int main () {

    sieve[0] = sieve[1] = true; // primesn't
    
    for (int i = 2; i * i <= LIM; ++i) {
        if (!sieve[i]) {
            for (int j = i*2; j <= LIM; j += i)
                sieve[j] = true;
        }
    }

    vector<int> primes;

    for (int i = 2; i <= LIM; ++i)
        if (!sieve[i]) {
            primes.push_back(i);
        }
    
    int chainSizeMax = 0, p = 0;
    for (int i = 0; i < primes.size(); ++i) {

        int chainSize = 1, chain = primes[i];
        for (int j = i + 1; j < primes.size(); ++j) {
            chain += primes[j];
            ++chainSize;
            if (chain >= LIM)
                break;

            if (!sieve[chain]) {
                if (chainSize > chainSizeMax) {
                    chainSizeMax = chainSize;
                    p = chain;
                }
            }
        }
    }

    cout << p;

    return 0;
}