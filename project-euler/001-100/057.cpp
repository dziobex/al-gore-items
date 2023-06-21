#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define ull unsigned long long

const int LIMIT = 1000;
const int LIM = 500;

int determineStart(int digits[LIM]) {
    int index = 0;
    while (digits[++index] == 0) {}
    return index;
}

void action(ull what, int (&digits)[LIM]) {
    for (int a = LIM - 1; a >= 0; --a)
        digits[a] *= what;
        
    for (int a = LIM - 1; a >= 0; --a) {
        int sure = digits[a] % 10;
        int package = (digits[a] - sure) / 10;

        digits[a] = sure;

        if (a >= 1)
            digits[a - 1] += package;
    }
}

void add(int (&dest)[LIM], int (&added)[LIM]) {
    for (int a = LIM - 1; a >= 0; --a)
        dest[a] += added[a];
        
    for (int a = LIM - 1; a >= 0; --a) {
        int sure = dest[a] % 10;
        int package = (dest[a] - sure) / 10;

        dest[a] = sure;

        if (a >= 1)
            dest[a - 1] += package;
    }
}

int main () {

    int a[LIM]{}, b[LIM]{};
    a[LIM - 1] = 1; b[LIM - 1] = 1;
    int totalCount = 0;

    for (int i = 1; i <= 1000; ++i) {
        int na[LIM]{}, nb[LIM]{};

        for (int j = 0; j < LIM; ++j) {
            na[j] = b[j];
            nb[j] = b[j];
        }

        action(2, na);

        add(na, a);
        add(nb, a);

        int starta = determineStart(a);
        int startb = determineStart(b);

        for (int x = 0; x < LIM; ++x) {
            a[x] = na[x];
            b[x] = nb[x];
        }

        if (starta < startb)
            ++totalCount;
    }

    cout << totalCount;

    return 0;
}