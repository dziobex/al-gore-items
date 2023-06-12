#include <iostream>
#include <string>

using namespace std;

#define ull unsigned long long

bool isprime(ull n) {
    for (ull i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

bool unique(ull n) {
    int arr[8]{};

    while (n > 0) {
        if (++arr[n % 10] > 1)
            return false;
        n /= 10;
    }

    return true;
}

int main () {

    ull p = 0;
    for (ull i = 7000000; i < 7654321; ++i) { // suma 1...7 jest niepodzielna przez 3; sumy 1..5, 1..6, 1..8, 1..9 są
        if (i % 2 == 0)
            continue;
        
        if (unique(i) && isprime(i)) {
            p = i;
        }
    }

    cout << p;

    return 0;
}