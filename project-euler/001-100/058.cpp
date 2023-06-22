#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return false;
    
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    
    return true;
}

int main () {

    int diag = 5, primes = 0;
    for (int i = 3;; i += 2, diag += 4) {
        int power = i * i;

        for (int j = 0; j < 3; ++j) {
            power -= (i - 1);

            if (isPrime(power))
                ++primes;
        }

        float r = (float)primes / diag * 100.0;
        
        if (r < 10) {
            cout << i;
            break;
        }
    }

    return 0;
}