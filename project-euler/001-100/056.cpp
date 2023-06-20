#include <iostream>
#include <math.h>

using namespace std;

const int LIM = 200;

int main () {

    int maxSum = 0;

    for (int a = 99; a <= 99; ++a) {
        int digits[LIM]{};
        digits[LIM - 1] = 1;

        for (int b = 1; b <= 99; ++b) {
            int lokSum = 0;

            for (int c = LIM - 1; c >= 0; --c)
                digits[c] *= a;

            for (int c = LIM - 1; c >= 1; --c) {
                if (digits[c] == 0)
                    break;

                int sure = digits[c] % 10;
                int package = (digits[c] - sure) / 10;

                digits[c] = sure;
                digits[c - 1] += package;

                lokSum += sure;
            }

            if (lokSum > maxSum)
                maxSum = lokSum;
        }
    }

    cout << maxSum;

    return 0;
}