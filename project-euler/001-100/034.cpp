#include <iostream>

using namespace std;

#define ull unsigned long long

ull factorials[10]{};

int main () {
    factorials[0] = 1;

    for (int i = 1; i <= 9; ++i) {
        factorials[i] = i * factorials[i - 1];
    }

    ull totalSum = 0;
    for (ull i = 12; i <= 9999999; ++i) { // 7x9 > 9!*7
        ull sum = 0, copy = i;

        while (copy > 0) {
            sum += (factorials[copy % 10]);
            copy /= 10;
        }

        if (sum == i)
            totalSum += i;
    }

    cout << totalSum;

    return 0;
}