#include <iostream>
#include <math.h>

using namespace std;

const int LIM = 30;

int determineStart(int digits[LIM]) {
    int index = 0;
    while (digits[++index] == 0) {}
    return index;
}

int main () {

    int totalCount = 0;

    for (int a = 1; a <= 9; ++a) {

        int digits[LIM]{};
        digits[LIM - 1] = 1;

        for (int b = 1; b <= 21; ++b) {

            for (int i = LIM - 1; i >= 0; --i)
                digits[i] *= a;
            
            for (int c = LIM - 1; c >= 1; --c) {
                int sure = digits[c] % 10;
                int package = (digits[c] - sure) / 10;

                digits[c] = sure;
                digits[c - 1] += package;
            }

            if (LIM - determineStart(digits) == b)
                ++totalCount;
        }
    }

    cout << totalCount;

    return 0;
}