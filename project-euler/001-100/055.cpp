#include <iostream>
#include <fstream>

using namespace std;

const int LIM = 30;

int determineStart(int digits[LIM]) {
    int index = 0;
    while (digits[++index] == 0) {}
    return index;
}

bool isPalindrome(int digits[LIM]) {
    int start = determineStart(digits), end = LIM - 1;

    while (start < end) {
        if (digits[start] != digits[end])
            return false;
        start++;
        end--;
    }

    return true;
}

int main () {

    int totalCount = 0;

    for (int i = 2; i < 10000; ++i) {
        int digits[LIM]{};
        int copy = i, idx = LIM - 1;

        while (copy > 0) {
            digits[idx--] = copy % 10;
            copy /= 10;
        }

        int iters = 0;
        bool found = false;


        while (iters < 50 && !found) {
            ++iters;
            int cop[LIM]{};

            int start = determineStart(digits);

            for (int a = start, b = LIM - 1; a < LIM; ++a, --b)
                cop[a] = digits[b];

            for (int c = LIM - 1; c >= start; --c)
                digits[c] += cop[c];

            for (int c = LIM - 1; (c >= start || digits[c] != 0); --c) {
                int sure = digits[c] % 10;
                int package = (digits[c] - sure) / 10;

                digits[c] = sure;
                digits[c - 1] += package;
            }

            if (isPalindrome(digits)) {
                found = true;
                break;
            }
        }

        if (!found)
            ++totalCount;
    }

    cout << totalCount;

    return 0;
}