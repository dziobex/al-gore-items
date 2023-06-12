#include <iostream>

using namespace std;

int main () {

    int limit = 10;
    int t = 3, f = 5, sum = 0;

    while (t < limit) {
        sum += t;
        t += 3;
    }

    while (f < limit) {
        sum += f;
        f += 5;
    }

    int c = 3 * 5;

    while (c < limit) {
        sum -= c;
        c += 3 * 5;
    }
    cout << sum;

    return 0;
}