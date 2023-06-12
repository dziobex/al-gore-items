#include <iostream>

using namespace std;

#define ull unsigned long long

int main () {

    ull sum = 0;

    for (int i = 1; i <= 1000; ++i) {

        ull powered = 1;
        for (int j = 1; j <= i; ++j) {
            powered = (powered * i) % 10000000000;
        }

        sum = (sum + powered) % 10000000000;
    }

    cout << sum;
    
    return 0;
}