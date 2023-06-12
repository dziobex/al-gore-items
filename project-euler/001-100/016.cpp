#include <iostream>

using namespace std;

const int limit = 310, power = 1000;

int digits[limit]{};

int main () {

    digits[limit - 1] = 1;

    for (int i = 1; i <= power; ++i) {

        for (int j = limit - 1; j >= 0; --j) {
            digits[j] *= 2;
        }

        for (int j = limit - 1; j >= 1; --j) {
            int sure = digits[j] % 10;
            int package = (digits[j] - sure) / 10;

            digits[j] = sure;
            digits[j - 1] += package;
        }
    }

    int sum = 0;
    for (int i = 0; i < limit; ++i)
        sum += digits[i];
    
    cout << sum;

    return 0;
}