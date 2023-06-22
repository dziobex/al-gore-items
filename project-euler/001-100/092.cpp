#include <iostream>
#include <math.h>

using namespace std;

typedef unsigned long long ull;

const ull LIMIT = 10000000;

ull sumPowers(ull src) {
    ull sum = 0;

    while (src > 0) {
        int dg = src % 10;
        sum += dg*dg;
        src /= 10;
    }

    return sum;
}

ull wh = 85;

int main () {

    ull totalCount = 0;

    for (ull i = 1; i <=LIMIT; ++i) {
        ull c = i;

        while (c != 1 && c != 89)
            c = sumPowers(c);

        if (c == 89)
            ++totalCount;
    }

    cout << totalCount;

    return 0;
}