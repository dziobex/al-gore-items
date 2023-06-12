#include <iostream>

using namespace std;

#define ull unsigned long long

const ull nth = 1000000;

bool unique(ull n) {
    int collect[10]{};

    while (n > 0) {
        int dig = n % 10;

        if (collect[dig]++ > 0)
            return false;
        n /= 10;
    }

    return true;
}

int main () {

    // zawezone wyszukiwanie ->
    // perms = 9! * 2 (0, 1)
    // 3 * 9! (3 i 9x0) >1mln, to jest pewna granica
    
    ull perms = 725760, i = 2000000000;
    for (; i <= 3000000000; ++i) {
        if (unique(i))
            ++perms;
        if (perms >= nth)
            break;
    }

    cout << i;

    return 0;
}