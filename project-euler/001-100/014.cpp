#include <iostream>

using namespace std;

const int limit = 1000000;

#define ull unsigned long long

int memos[limit]{};

int chainSize(ull start) {
    int csize = 0;

    while (start != 1) {

        if (start < limit && memos[start] != 0)
            return csize + memos[start];
        
        if (start % 2 != 0)
            start = 3 * start + 1;
        else
            start /= 2;
        ++csize;
    }

    return csize;
}

int main () {

    int maxC = 0, maxI = 0;

    for (ull i = 1; i < limit; ++i) {
        int chainsize = chainSize(i);

        memos[i] = chainsize;

        if (chainsize > maxC) {
            maxC = chainsize;
            maxI = i;
        }
    }

    cout << maxC << ' ' << maxI;

    return 0;
}