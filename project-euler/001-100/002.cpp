#include <iostream>

using namespace std;

#define ull unsigned long long

int main () {

    ull loc1 = 1, loc2 = 2, loc3 = 0, sum = 2;

    for (int i = 3; ; ++i) {
        loc3 = loc1 + loc2;
        loc1 = loc2;
        loc2 = loc3;

        if (loc3 > 4000000)
            break;

        if (loc3 % 2 == 0)
            sum += loc3;

    }

    cout << sum;

    return 0;
}