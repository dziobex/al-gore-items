#include <iostream>

using namespace std;

typedef long long ll;

const ll primes[12]{2, 3, 5, 7, 11, 13, 17, 19, 21, 23, 29, 31};
const ll LIMIT = 1000000;

int main () {

    ll result = 1, index = 0;

    while (result * primes[index] <= LIMIT) {
        result *= primes[index++];
    }

    cout << result;

    return 0;
}